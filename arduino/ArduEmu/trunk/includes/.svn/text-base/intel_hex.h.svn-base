/*
 * intel_hex.h
 *
 *  Created on: 26-Feb-2009
 *      Author: Samuel Truscott
 *      Author: Richard Slaughter
 */

#ifndef INTEL_HEX_H_
#define INTEL_HEX_H_

#include "global_types.h"

/*
 * this type lists all the possible error codes
 * which may occur during parsing
 */
typedef enum
{
	HEX_CONVERTED_OK,
	HEX_BAD_FILE_FORMAT,
	HEX_CHECKSUM_FAIL,
	HEX_INVALID_MEMORY,
	HEX_OUT_OF_MEMORY,
	HEX_FORMAT_NOT_SUPPORTED,
	HEX_UNKNOWN_ERROR
} intel_hex_result_type;

/*
 * this procedure is used to take data from the in_data
 * buffer, parse it (assuming its binary) and program
 * it into out_data (which is assumed to be the base
 * address of the programmed device - i.e. FLASH)
 *
 */
intel_hex_result_type parse_intel_hex (
		const INT8* in_data,
		const UINT32 in_data_len,
		INT8* out_data,
		const UINT16 out_data_len);


#endif /* INTEL_HEX_H_ */
