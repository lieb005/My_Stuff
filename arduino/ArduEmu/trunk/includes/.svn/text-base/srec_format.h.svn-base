/*
 * srec_format.h
 *
 *  Created on: 27-Feb-2009
 *      Author: Samuel Truscott
 *      Author: Richard Slaughter
 */

#ifndef SREC_FORMAT_H_
#define SREC_FORMAT_H_

#include "global_types.h"

/*
 * this type is used to indicate the result
 * of parsing an S-Record file
 */
typedef enum
{
	SREC_PARSED_OK,
	SREC_BAD_FORMAT
} srec_parse_result_type;

/*
 * this procedure is used to parse an S-Record into
 * a memory region
 */
srec_parse_result_type parse_srec(
	const INT8*,
	const UINT32,
	INT8*,
	const UINT16);

#endif /* SREC_FORMAT_H_ */
