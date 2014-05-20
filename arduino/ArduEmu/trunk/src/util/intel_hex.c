/*
 * intel_hex.c
 *
 *  Created on: 26-Feb-2009
 *      Author: Samuel Truscott
 *      Author: Richard Slaughter
 */

#include <intel_hex.h>
#include <string.h>
#include <stdio.h>

#include <global_types.h>
#include <bin_utils.h>

#define INTEL_HEX_CHECKSUM_SIZE 2
#define INTEL_HEX_HEADER_SIZE 9
#define INTEL_HEX_HEADER_BYTESIZE 4
#define END_OF_LINE_SIZE 1 /* TODO 1 on Unix? */

/*
 * this type contains the different data types that
 * an Intel Hex record may be
 */
typedef enum
{
	DATA_RECORD = 0x00,
	END_OF_FILE = 0x01,
	EXTENDED_SEG_ADDR = 0x02,
	START_SEG_ADDR = 0x03,
	EXTENDED_LINEAR_ADDR = 0x04,
	START_LINEAR_ADDR = 0x05
} intel_hex_data_types_type;

/*
 * this type is used to read the header of the
 * intel hex file format
 */
typedef struct
{
	INT8 start_char;
	UINT8 byte_count;
	UINT16	data_address;
	intel_hex_data_types_type data_type : 8;

} intel_hex_format_type;

extern UINT16 atmel_PC;

/*
 * this procedure is used to parse and program
 * a single record of an intel hex file
 */
static intel_hex_result_type parse_intel_hex_data_byte (
		const INT8** in_data,
		const UINT32 in_data_len,
		INT8* out_data,
		const UINT32 out_data_len,
		const intel_hex_format_type *header);

/*
 * this procedure is sued to parse and program
 * a single (16bit) record of an intel hex 16 file
 */
static intel_hex_result_type parse_intel_hex_data_short (
		const INT8** in_data,
		const UINT32 in_data_len,
		INT16* out_data,
		const UINT32 out_data_len,
		const intel_hex_format_type *header);

intel_hex_result_type parse_intel_hex (
		const INT8* in_data,
		const UINT32 in_data_len,
		INT8* out_data,
		const UINT16 out_data_len)
{
	intel_hex_result_type ret = HEX_CONVERTED_OK;
	boolean eof = FALSE;

	const INT8* starting_address = in_data;

	intel_hex_format_type header;

	UINT16 segment_address = 0;
	
	memset(
		&header,
		0,
		sizeof(header));

	while ( eof == FALSE )
	{
		UINT8 checksum_value;
		UINT8 file_checksum;

		/* quick check to ensure we're not reading
		 * past the end of the file */
		if ( in_data >= (starting_address
			+ in_data_len) )
		{
			ret = HEX_OUT_OF_MEMORY;
			eof = TRUE;
			break;
		}

		/*
		 * get the header out of the file. increase the offset
		 * in the buffer as we go
		 */
		header.start_char = in_data[0];
		in_data += 1;
		header.byte_count = read_hex_byte( &in_data );
		header.data_address = read_hex_short (&in_data );
		header.data_type = read_hex_byte( &in_data );

		if ( header.start_char != ':')
		{
			ret = HEX_BAD_FILE_FORMAT;
			eof = TRUE;
		}
		else
		{
			switch ( header.data_type )
			{
				case DATA_RECORD:
					/* check sum line */
					checksum_value =
						get_checksum(
								in_data - INTEL_HEX_HEADER_SIZE + 1,
								INTEL_HEX_HEADER_BYTESIZE + header.byte_count);

					/* if we see a data record parse that in */
					ret = parse_intel_hex_data_byte (
							&in_data,
							in_data_len,
							out_data + segment_address,
							out_data_len,
							&header);

					/* skip over the checksum and \r\n */
					file_checksum = read_hex_byte( &in_data );
					if ( checksum_value != file_checksum)
					{
						eof = TRUE;
						ret = HEX_CHECKSUM_FAIL;
					}
					in_data += END_OF_LINE_SIZE;

					break;
				case END_OF_FILE:
					eof = TRUE;
					break;
				case EXTENDED_SEG_ADDR:
					
					/* check sum line */
					checksum_value =
						get_checksum(
								in_data - INTEL_HEX_HEADER_SIZE + 1,
								INTEL_HEX_HEADER_BYTESIZE + header.byte_count);

					/* if we see a data record parse that in */
					ret = parse_intel_hex_data_short (
							&in_data,
							in_data_len,
							//(INT16*)out_data,
							(INT16*)&segment_address,
							2,
							&header);

					/* skip over the checksum and \r\n */
					if ( checksum_value != read_hex_byte( &in_data ) )
					{
						eof = TRUE;
						ret = HEX_CHECKSUM_FAIL;
					}
					in_data += END_OF_LINE_SIZE;

					break;
				case START_SEG_ADDR:

					checksum_value =
						get_checksum(
								in_data - INTEL_HEX_HEADER_SIZE + 1,
								INTEL_HEX_HEADER_BYTESIZE + header.byte_count);
					
					/* TODO the CS */ read_hex_short( &in_data );
					atmel_PC = read_hex_short( &in_data );

					file_checksum = read_hex_byte( &in_data );
					if ( checksum_value != file_checksum)
					{
						eof = TRUE;
						ret = HEX_CHECKSUM_FAIL;
					}
					in_data += END_OF_LINE_SIZE;

					break;
				case EXTENDED_LINEAR_ADDR:
					eof = TRUE;
					ret = HEX_FORMAT_NOT_SUPPORTED;
					break;
				case START_LINEAR_ADDR:
					eof = TRUE;
					ret = HEX_FORMAT_NOT_SUPPORTED;
					break;
			}
		}
	}

	return ret;
}

intel_hex_result_type parse_intel_hex_data_byte (
		const INT8** in_data,
		const UINT32 in_data_len,
		INT8* out_data,
		const UINT32 out_data_len,
		const intel_hex_format_type *header)
{
	intel_hex_result_type ret = HEX_CONVERTED_OK;

	/* check the data is visible to the out data */
	if ( header->data_address > out_data_len )
	{
		ret = HEX_OUT_OF_MEMORY;
	}
	else
	{
		UINT16 current_byte;

		/* based on the read read a number of bytes */
		for ( current_byte = 0 ;
				current_byte < header->byte_count;
				current_byte++)
		{
			const UINT16 addr = header->data_address + current_byte;

			/* copy those bytes into the output memory
			 * with an offset (which is the program address)
			 */
			*(out_data + addr)
				= read_hex_byte ( in_data );

#ifdef _DEBUG
			printf("FLASH 0x%04X: 0x%02X\n", (addr), *((UINT8*)(out_data + addr)));
#endif
		}
	}

	return ret;
}

intel_hex_result_type parse_intel_hex_data_short (
		const INT8** in_data,
		const UINT32 in_data_len,
		INT16* out_data,
		const UINT32 out_data_len,
		const intel_hex_format_type *header)
{
	intel_hex_result_type ret = HEX_CONVERTED_OK;

	/* check the data is visible to the out data */
	if ( header->data_address > out_data_len )
	{
		ret = HEX_OUT_OF_MEMORY;
	}
	else
	{
		UINT16 current_byte;

		/* based on the read read a number of bytes */
		for ( current_byte = 0 ;
				current_byte < header->byte_count;
				current_byte+=2)
		{
			const UINT16 addr = header->data_address + current_byte;
			/* copy those bytes into the output memory
			 * with an offset (which is the program address)
			 */
			*(out_data + addr)
				= read_hex_short ( in_data );
#ifdef _DEBUG
			printf("FLASH 0x%04X: 0x%04X\n", (addr), *((UINT16*)(out_data + addr)));
#endif
		}
	}

	return ret;
}

