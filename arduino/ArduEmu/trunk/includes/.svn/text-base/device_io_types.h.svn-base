/*
 * device_io_types.h
 *
 *  Created on: 26-Feb-2009
 *      Author: Samuel Truscott
 *      Author: Richard Slaughter
 */

#ifndef DEVICE_IO_TYPES_H_
#define DEVICE_IO_TYPES_H_

#include "global_types.h"

typedef struct
{
	INT8*	device_name;
	UINT16	base_address;
	UINT16	device_size;
} device_info_type;

typedef void(*device_read_write_operation)(
	const UINT16 dev_address,
	const UINT16 number_bytes,
	const UINT8* data);

typedef struct
{
	device_info_type	info;
	device_read_write_operation read_op;
	device_read_write_operation write_op;
	/* TODO add more details - i.e. control & interrupts */
}  device_type;

#endif
