

#ifndef __MCP4716DRV_H__
#define __MCP4716DRV_H__

#include "Cpu.h"

extern const int16_t sine_wave[];

uint8_t DAC_Write_VolatileRegVal(uint16_t val);
void PlaySineWave(void);
void StartWave(void);


#endif
