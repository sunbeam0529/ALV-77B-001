
#include "Cpu.h"
#include "ECUM.h"

static volatile uint16_t TimeBaseCounter;
volatile uint8_t TimeBase1msFlag;
volatile uint8_t TimeBase5msFlag;
volatile uint8_t TimeBase10msFlag;
volatile uint8_t TimeBase20msFlag;
volatile uint8_t TimeBase50msFlag;
volatile uint8_t TimeBase100msFlag;
volatile uint8_t TimeBase1000msFlag;

uint16_t security_access_counter=0;

void TimeBaseCount(void)
{
    TimeBaseCounter++;
    TimeBase1msFlag = 1;
    if(TimeBaseCounter % 5 == 0)
    {
        TimeBase5msFlag = 1;
    }
    if(TimeBaseCounter % 10 == 0)
    {
        TimeBase10msFlag = 1;
    }
    if(TimeBaseCounter % 20 == 0)
    {
        TimeBase20msFlag = 1;
    }
    if(TimeBaseCounter % 50 == 0)
    {
        TimeBase50msFlag = 1;
    }
    if(TimeBaseCounter % 100 == 0)
    {
        TimeBase100msFlag = 1;
    }
    if(TimeBaseCounter % 1000 == 0)
    {
        TimeBase1000msFlag = 1;
    }
    if(TimeBaseCounter >= 60000)
    {
        TimeBaseCounter = 0;
    }
    security_access_counter++;
}

uint16_t GetTimeCounter(void)
{
    return security_access_counter;
}
