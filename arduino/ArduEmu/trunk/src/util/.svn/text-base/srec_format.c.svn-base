/*
 * srec_format.c
 *
 *  Created on: 27-Feb-2009
 *      Author: Samuel Truscott
 *      Author: Richard Slaughter
 */

#include "srec_format.h"
#include <string.h>

#include "bin_utils.h"
#include "global_types.h"

#define ASCII_TO_INT 48
#define CHECKSUM_HEX_COUNT 1
#define CHECKSUM_BYTE_COUNT CHECKSUM_HEX_COUNT * 2

/*
 * this type contains all the types of srec format
 */
typedef enum
{
	S0 = 0,
	S1 = 1,
	S2 = 2,
	S3 = 3,
	S_UNKNOWN_1 = 4,
	S5 = 5,
	S_UNKNOWN_2 = 6,
	S7 = 7,
	S8 = 8,
	S9 = 9
} srec_type_type;

/*
 * this type contains the header for an s-record record
 */
typedef struct
{
	INT8 header_char;
	srec_type_type record_type;
	UINT16 byte_count;
	UINT32 program_addr;
} srec_format_type;

/*
 * this lookup table is used to get the number
 * of hex chars which determine the length of the data field
 */
const UINT8 SREC_BYTE_COUNT_LOOKUP[] =
{
		/* S0 */ 2,
		/* S1 */ 2,
		/* S2 */ 3,
		/* S3 */ 4,
				 0,
		/* S5 */ 2,
				 0,
		/* S7 */ 4,
		/* S8 */ 3,
		/* S9 */ 2,
};

/*
 * this procedure is used to take a parsed
 * header and program the data into memory
 */
static srec_parse_result_type parse_srec_record(
		const INT8** in_data,
		const UINT32 in_data_len,
		INT8* out_data,
		const UINT16 out_data_len,
		const srec_format_type *header);

srec_parse_result_type parse_srec(
	const INT8* in_data,
	const UINT32 in_data_size,
	INT8* out_data,
	const UINT16 out_data_size)
{
	boolean eof = FALSE;
	srec_format_type header;
	srec_parse_result_type ret = SREC_PARSED_OK;

	while ( eof == FALSE )
	{
		header.header_char = in_data[0];
		header.record_type = in_data[1] - ASCII_TO_INT;
		in_data += 2;

		header.byte_count = read_hex_byte ( &in_data );

		header.byte_count -= SREC_BYTE_COUNT_LOOKUP[header.record_type];
		header.byte_count -= CHECKSUM_HEX_COUNT;

		switch ( SREC_BYTE_COUNT_LOOKUP[header.record_type] )
		{
			case 2:
				header.program_addr = read_hex_short ( &in_data );
				break;
			case 3:
				header.program_addr = read_hex_byte ( &in_data ) << 16
					| read_hex_short ( &in_data);
				break;
			case 4:
				header.program_addr = read_hex_int ( &in_data );
				break;
			default:
				ret = SREC_BAD_FORMAT;
				eof = TRUE;
				break;
		}

		ret = parse_srec_record(
				&in_data,
				in_data_size,
				out_data,
				out_data_size,
				&header);

		if ( header.record_type == S9
				|| header.record_type == S7 )
		{
			eof = TRUE;
		}
	}

	return ret;
}

srec_parse_result_type parse_srec_record(
		const INT8** in_data,
		const UINT32 in_data_len,
		INT8* out_data,
		const UINT16 out_data_len,
		const srec_format_type *header)
{
	UINT8 current_byte;
	srec_parse_result_type ret = SREC_PARSED_OK;

	switch ( header->record_type )
	{
		case S1:
		case S2:
		case S3:
			for ( current_byte = 0 ;
				  current_byte < header->byte_count;
				  current_byte++ )
			{
				*(char*)(out_data + header->program_addr + current_byte)
					= read_hex_byte(in_data);
			}
			break;
		default:
			/* mul by two because two chars per ascii hex byte */
			(*in_data) += header->byte_count * 2;

	}

	(*in_data) += CHECKSUM_BYTE_COUNT + 2; /* assumes 2 for checksum and 2 for \r\n */

	return ret;
}
