/*
 * atmel_flash.c
 *
 *  Created on: 09-Mar-2009
 *      Author: Samuel Truscott
 *      Author: Richard Slaughter
 *
 * Handles flash memory (where program is stored)
 */

#include <stdio.h>
#include <string.h>

#include "global_types.h"

#define PROGRAM_MEMORY_SIZE (16 * 1024)

static UINT8 atmel_program_memory[PROGRAM_MEMORY_SIZE];

void init_program_memory(void)
{
	memset(
		atmel_program_memory,
		'X',
		PROGRAM_MEMORY_SIZE);
}

UINT8* get_program_memory(UINT16 addr)
{
	/* TODO need to update this for devices? */
	return &atmel_program_memory[addr];
}

const UINT16 get_program_memory_size()
{
	return PROGRAM_MEMORY_SIZE;
}

void write_program_memory(
	UINT16 addr,
	UINT8* data,
	UINT16 size)
{
	memcpy(
		&atmel_program_memory[addr],
		data,
		size);
}
