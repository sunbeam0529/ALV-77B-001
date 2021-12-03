#include "Cpu.h"
#include "event.h"
//#include "MotorDrv.h"
#include "ECUM.h"

volatile uint32_t DelayMsTime;

void LPIT0_IRQHandler(void)
{
    //LPIT CH0
	if (LPIT_DRV_GetInterruptFlagTimerChannels(INST_LPIT1,(1 << 0)))
	{
        //1ms 
        TimeBaseCount();
        //lin_lld_timeout_service(LI0);//todo
        if(DelayMsTime < 1000000)
            DelayMsTime++;
        /* Clear LPIT channel flag */
		LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT1, (1 << 0));
	}

    //LPIT CH1
    if (LPIT_DRV_GetInterruptFlagTimerChannels(INST_LPIT1,(1 << 1)))
	{
        //180 * 100 = 18000Hz

        /* Clear LPIT channel flag */
        LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT1, (1 << 1));
	}
}
