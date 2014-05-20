/*
 * atmel_sram.c
 *
 *  Created on: 09-Mar-2009
 *      Author: Samuel Truscott
 *      Author: Richard Slaughter
 *
 * Handles SRAM (where data is stored)
 */

#include <stdio.h>
#include <string.h>
#include "atmel_decoder.h"
#include "atmel_operations.h"
#include "atmel_sram.h"

#include "global_types.h"
#include "device_io_types.h"

static UINT8 atmel_data_memory[DATA_MEMORY_SIZE];

#define MAX_NO_DEVICES 10
static device_type* memory_mapped_devices[MAX_NO_DEVICES] = {NULL};
static UINT8 number_devices = 0;

void init_data_memory(void)
{
	memset(
		atmel_data_memory,
		0xFF,
		DATA_MEMORY_SIZE);
}

UINT8* get_data_memory(const UINT16 addr)
{
	/* TODO need to update this for devices? */
	return &atmel_data_memory[addr];
}

UINT16 get_data_memory_size()
{
	return DATA_MEMORY_SIZE;
}

void write_data_memory(
	const UINT16 addr,
	const UINT8* data,
	const UINT16 size)
{
	UINT8 device;
	boolean is_device = FALSE;
	device_type *cd = NULL;

	/* TODO optimise this */
	for ( device=0; device<number_devices; device++)
	{
		cd = memory_mapped_devices[device];
		if ( addr >= cd->info.base_address &&
			addr < (cd->info.base_address + cd->info.device_size) )
		{
			is_device = TRUE;

			cd->write_op ( addr, size, data );
		}
	}

	if ( is_device == FALSE)
	{
		memcpy(
			&atmel_data_memory[addr],
			data,
			size);
	}
}

void register_device ( device_type* device )
{
	if ( number_devices < MAX_NO_DEVICES )
	{
		memory_mapped_devices[number_devices++] = device;
	}
}
