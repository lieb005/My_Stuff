/*
 * bin_utils.h
 *
 *  Created on: 22-Feb-2009
 *      Author: Samuel Truscott
 *      Author: Richard Slaughter
 */

#ifndef BIN_UTILS_H_
#define BIN_UTILS_H_

#include "global_types.h"

/*
 * this procedure takes a buffer and returns
 * a big endian integer (32-bits)
 *
 * the position in the buffer is increased by 4 (int)
 */
UINT32 read_int(const INT8** buffer);

/*
 * this procedure takes a buffer and returns
 * a big endian 3-byte integer (24-bits)
 *
 * the position in the buffer is increased by 3
 */
UINT32 read_3(const INT8** buffer);

/*
 * this procedure takes a buffer and returns
 * a big endian 2-byte short integer (16-bits)
 *
 * the position in the buffer is increased by 2 (short)
 */
UINT16 read_short(const INT8** buffer);

/*
 * this procedure takes a buffer and returns
 * a byte integer (8-bits)
 *
 * the position in the buffer is increased by 1 (byte)
 */
UINT8 read_byte( const INT8** buffer);

/*
 * this procedure converts a hex nibble (i.e. E) to
 * a decimal values
 */
UINT8 read_hex_nibble ( const INT8 );

/*
 * this procedure reads an ASCII hex byte value (i.e. E0)
 * and converts it to decimal
 */
UINT8 read_hex_byte ( const INT8** buffer);

/*
 * this procedure reads an ASCII hex short value (i.e. E0E0)
 * and converts it to decimal
 */
UINT16 read_hex_short ( const INT8** buffer );

/*
 * this procedure reads an ASCII hex int value (i.e. E0E0E0E0)
 * and converts it to decimal
 */
UINT32 read_hex_int ( const INT8** buffer );

/*
 * this procedure calculates a checksum for the given hex data,
 * returning the least significant byte of the two's complement sum
 * of the values
 */
UINT8 get_checksum( const INT8* in_data, UINT16 data_size);

void swap_endianess_short( INT16* data );

#endif /* BIN_UTILS_H_ */
