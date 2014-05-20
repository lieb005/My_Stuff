/*
 * atmel_obj_format.c
 *
 *  Created on: 27-Feb-2009
 *      Author: Samuel Truscott
 *      Author: Richard Slaughter
 */

#include <string.h>
#include <stdio.h>
#include <global_types.h>
#include <atmel_obj_format.h>
#include <bin_utils.h>

/*
 * this type contains the header
 * for an ASM object file
 */
typedef struct
{
	UINT32 offset_to_src_filenames;
	UINT32 offset_to_object_records;
	UINT8 no_bytes_per_record;
	UINT8 no_files_in_tail;
	const INT8* name;
} file_obj_header_type;

/*
 * this procedure takes a buffer and reads the object
 * file header. after reading the buffer will have
 * moved to the end of the header
 */
static file_obj_header_type decode_header( const INT8** buffer );

/*
 * this procedure is used to take the buffer and decode an instruction
 */
static void decode_instruction(
		const INT8** buffer,
		INT8* out_data,
		const UINT16 out_data_size);

void decode_atmel_format(
		const INT8* buffer,
		const UINT32 buffer_size,
		INT8* out_data,
		const UINT16 out_data_size)
{
	file_obj_header_type header;
	UINT32 number_of_records;
	UINT32 current_record;

	/* get the header from the objectr file */
	header = decode_header ( &buffer ) ;

	/* work out the number of records
	 * and parse them all
	 */
	number_of_records = (header.offset_to_src_filenames
	- header.offset_to_object_records) / header.no_bytes_per_record;
	for ( 	current_record=0 ;
			current_record < number_of_records ;
			current_record++)
	{
		decode_instruction ( &buffer, out_data, out_data_size );
	}
}

file_obj_header_type decode_header( const INT8** buffer)
{
	file_obj_header_type file_header;

	file_header.offset_to_src_filenames = read_int(buffer);
	file_header.offset_to_object_records = read_int(buffer);
	file_header.no_bytes_per_record = read_byte(buffer);
	file_header.no_files_in_tail = read_byte(buffer);
	file_header.name = (*buffer);

	(*buffer) += strlen(file_header.name) + 1;

	return file_header;
}

void decode_instruction(
		const INT8** buffer,
		INT8* out_data,
		const UINT16 out_data_size)
{
	UINT32 program_memory_address;
	UINT16 opcode;
	UINT8 src_file;
	UINT16 src_line_no;

	program_memory_address = read_3(buffer);
	opcode = read_short(buffer);
	src_file = read_byte(buffer);
	src_line_no = read_short(buffer);

	*(UINT16*)(out_data + (program_memory_address * 2)) = opcode;

#ifdef _DEBUG
	printf("FLASH 0x%04X: 0x%04X\n", (program_memory_address * 2), opcode);
#endif

	*buffer += 1; /* eof */
}
