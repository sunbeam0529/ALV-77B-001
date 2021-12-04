/*
 * SW_I2C.h
 *
 *  Created on: 2021Äê12ÔÂ4ÈÕ
 *      Author: dm01
 */

#ifndef ABSTRATIONLAYER_SW_I2C_H_
#define ABSTRATIONLAYER_SW_I2C_H_
#include "Cpu.h"
#include "PinDef.h"

uint8_t SWI2C_ReceiveDataBlocking(uint8_t addr, uint8_t * rxBuff,uint32_t rxSize, bool sendStop);
uint8_t SWI2C_ReceiveDataBlocking(uint8_t addr, uint8_t * rxBuff,uint32_t rxSize, bool sendStop);


#endif /* ABSTRATIONLAYER_SW_I2C_H_ */
