/*
 * pedometer.h
 *
 *  Created on: Jun 28, 2012
 *      Author: mark
 */

#ifndef PEDOMETER_H_
#define PEDOMETER_H_

struct pedo
{
	u16 steps; // amount of steps taken since last reset
	u8 stride; // stride in metres * 100

};

#endif /* PEDOMETER_H_ */
