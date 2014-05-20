/*
 * atmel_sram.h
 *
 *  Created on: 09-Mar-2009
 *      Author: Samuel Truscott
 *      Author: Richard Slaughter
 */

#ifndef ATMEL_SRAM_H_
#define ATMEL_SRAM_H_

#include "device_io_types.h"	/* used for the emulated devices */

#define DATA_MEMORY_SIZE 1280

void init_data_memory(void);

UINT8* get_data_memory(const UINT16 addr);

UINT16 get_data_memory_size();

void write_data_memory(const UINT16 addr, const UINT8* data, const UINT16 size);

void register_device ( device_type* device );

#endif /* ATMEL_SRAM_H_ */
