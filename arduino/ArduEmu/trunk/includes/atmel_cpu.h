/*
 * atmel_cpu.h
 *
 *  Created on: 04-Mar-2009
 *      Author: Samuel Truscott
 *      Author: Richard Slaughter
 */

#ifndef ATMEL_CPU_H_
#define ATMEL_CPU_H_

void init_atmel(void);
void atmel_fetch_execute(const UINT32 start_address);

#endif /* ATMEL_CPU_H_ */
