/*
 * atmel_flash.h
 *
 *  Created on: 09-Mar-2009
 *      Author: Samuel Truscott
 *      Author: Richard Slaughter
 */

#ifndef ATMEL_FLASH_H_
#define ATMEL_FLASH_H_

#include "device_io_types.h"	/* used for the emulated devices */

void init_program_memory(void);

UINT8* get_program_memory(const UINT16 addr);

const UINT16 get_program_memory_size();

void write_program_memory(const UINT16 addr,
						  const UINT8* data,
						  const UINT16 size);

#endif /* ATMEL_FLASH_H_ */
