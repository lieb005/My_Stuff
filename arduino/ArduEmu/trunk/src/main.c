/*
 * main.c
 *
 *  Created on: 22-Feb-2009
 *      Author: Samuel Truscott
 *      Author: Richard Slaughter
 */

#include "atmel_decoder.h"		/* used for decoding Opcodes */
#include "intel_hex.h"			/* used for parsing Intel Hex files */
#include "srec_format.h"		/* used for parsing Motorola S-Record files */
#include "atmel_obj_format.h"	/* used for parsing Atmel Object files */
#include "atmel_flash.h" 		/* used to access memory for loading program into */
#include "atmel_sram.h" 		/* used to access memory for loading data into */
#include "atmel_cpu.h"			/* used for the cpu surprisingly enough */
#include "global_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_DATA_TO_READ 32 * 1024
#define FILE_READ_ERROR -1

typedef enum
{
	MEMORY_NOT_LOADED,
	MEMORY_LOADED_SUCCESFULLY,
} memory_load_result;

extern UINT16 atmel_PC;

static void print_help(void);

static memory_load_result load_from_intel_hex(INT8* filename);

static memory_load_result load_from_srec(INT8* filename);

static memory_load_result load_from_obj_file(INT8* filename);

int main(INT32 argc, INT8* argv[])
{
	INT8* filename;
	decode_type format;
	memory_load_result memory_loaded = MEMORY_NOT_LOADED;

	if(argc == 1
			|| ((argc == 2) && strcmp(argv[1],"-h\0") == 0)
			|| ((argc == 2) && strcmp(argv[1],"--help\0") == 0)
			|| ((argc == 2) && strcmp(argv[1], "/?\0") == 0))
	{
		print_help();
		return 0;
	}
	else if ( argc == 2 )
	{
		filename = argv[1];
		argv[2] = "intel_hex\0";
		format = INTEL_HEX;
	}
	else if ( argc == 3 )
	{
		filename = argv[1];

		if ( strcmp(argv[2], "intel_hex\0") == 0)
		{
			format = INTEL_HEX;
		}
		else if ( strcmp(argv[2], "srec\0") == 0)
		{
			format = SREC;
		}
		else if ( strcmp(argv[2], "binary\0") == 0)
		{
			format = RAW_BIN;
		}
		else if ( strcmp(argv[2], "atmel_object\0") == 0)
		{
			format = OBJ_FILE;
		}
		else
		{
			printf("Unknown file format\n");
			format = UNKNOWN_FORMAT;
		}
	}
	else
	{
		format = UNKNOWN_FORMAT;
	}

	/* setup the CPU and memory before we load in
	 * the program */
	init_atmel();

	printf("Loading: %s\n", filename);

	if( format == INTEL_HEX)
	{
		memory_loaded = load_from_intel_hex(filename);
	}
	else if ( format == SREC )
	{
		memory_loaded = load_from_srec(filename);
	}
	else if( format == OBJ_FILE)
	{
		memory_loaded = load_from_obj_file(filename);
	}
	else
	{
		print_help();
	}

	if(memory_loaded == MEMORY_LOADED_SUCCESFULLY)
	{
		//kick off execution
		//TODO: do something with the start address
		printf("Starting execution...\n");
		atmel_fetch_execute(atmel_PC);
	}

	printf("Execution terminated, press any key to continue...\n");
#ifdef _DEBUG
	getchar();
#endif

	return 0;
}


void print_help(void)
{
	printf("arduEmu 0.1\n");
	printf("Usage: arduEmu <program_file> <format>\n");
	printf("\n");
	printf("<format> should be one of the following:\n");
	printf("\tintel_hex\tThe Intel Hex file format (default)\n");
	printf("\tsrec\t\tThe Motorola S-Record Format\n");
	printf("\tbinary\t\tRaw binary image\n");
	printf("\tatmel_object\tAtmel Object File\n");
	printf("\telf\t\tNot supported\n");
}

memory_load_result load_from_obj_file(INT8* filename)
{
	FILE* file2 = fopen(filename, "r");

	printf ( "LOADING FROM OBJ FILE\n");

	if ( file2 == NULL )
	{
		printf("Failed to open obj file\n");
		return MEMORY_NOT_LOADED;
	}
	else
	{
		INT8 data[FILE_DATA_TO_READ];
		INT32 the_read = 0;

		memset(data, 0xFF, FILE_DATA_TO_READ);
		the_read = (INT32)fread(data,sizeof(INT8),FILE_DATA_TO_READ,file2);

		printf("read %d bytes\n", the_read);
		fclose(file2);

		if ( file2 != NULL )
		{
			decode_atmel_format(
					data,
					the_read,
					(INT8*)get_program_memory(0),
					get_program_memory_size());

			//FIXME: need to check if this succeeded?
			printf("Decoded obj file OK!\n");
		}

		fflush(stdout);
	}
	return MEMORY_LOADED_SUCCESFULLY;
}

memory_load_result load_from_srec(INT8* filename)
{
	FILE* srec_file;
	INT8 file_buffer[FILE_DATA_TO_READ];
	INT32 data_read;
	memory_load_result ret;

	srec_file = fopen(filename, "r");

	if ( srec_file != NULL )
	{
		data_read = (INT32)fread(file_buffer, sizeof(char), FILE_DATA_TO_READ, srec_file);

		if ( data_read == FILE_READ_ERROR )
		{
			ret = MEMORY_NOT_LOADED;
		}
		else
		{
			fclose(srec_file);

			if( parse_srec(
					file_buffer,
					data_read,
					(INT8*)get_program_memory(0),
					get_program_memory_size()) != SREC_PARSED_OK )
			{
				ret =  MEMORY_NOT_LOADED;
			}
			else
			{
				ret = MEMORY_LOADED_SUCCESFULLY;
			}
		}
	}
	else
	{
		ret = MEMORY_NOT_LOADED;
	}

	return ret;
}

memory_load_result load_from_intel_hex(INT8* filename)
{
	FILE* file1 = fopen(filename, "r");
	INT8 file_data[FILE_DATA_TO_READ] = {'\0'};
	INT32 hex_read = 0;

	printf ( "LOADING FROM INTEL HEX\n");

	if ( file1 == NULL)
	{
		printf("Couldn't open up Intel Hex test file\n");
		return MEMORY_NOT_LOADED;
	}
	else
	{
		hex_read = (INT32)fread(file_data, sizeof(INT8), FILE_DATA_TO_READ, file1);
		fclose(file1);

		printf("Read %d bytes\n", hex_read);
		if( parse_intel_hex(
				file_data,
				(UINT32)hex_read,
				(INT8*)get_program_memory(0),
				get_program_memory_size()) != HEX_CONVERTED_OK)
		{
			printf("Failed to parse the Intel Hex file\n");
			return MEMORY_NOT_LOADED;
		}
		else
		{
			printf("Parse Intel Hex file OK!\n");
		}
	}

	printf("\n");

	return MEMORY_LOADED_SUCCESFULLY;
}
