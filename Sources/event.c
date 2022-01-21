#include "Cpu.h"
#include "event.h"
//#include "MotorDrv.h"
#include "ECUM.h"
#include "MCP4716Drv.h"
volatile uint32_t DelayMsTime;

volatile uint16_t capturedValue = 0U;
volatile bool linEnabled = false;
uint16_t timerOverflowInterruptCount = 0U;
#define TIMER_COMPARE_VAL             (uint16_t)(2000U)
#define TIMER_TICKS_1US               (uint16_t)(4U)

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
        //8KHz
        PlaySineWave();

        /* Clear LPIT channel flag */
        LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT1, (1 << 1));
	}
}

void PORT_IRQHandler(void)
{
    static bool autoBaudComplete = false;

    /* Check if the interrupt is triggered by the LPUART Rx Pin */
    if(PINS_DRV_GetPortIntFlag(PORTC) & (1UL << 6))
    {
        /* Capture transition time stamp */
        capturedValue = LPTMR_DRV_GetCounterValueByCount(INST_LPTMR1);
        /* If the auto baud process is not completed and lin is enabled, call
         * LIN_DRV_AutoBaudCapture
         */
        if((!autoBaudComplete) && (linEnabled))
        {
            if (LIN_DRV_AutoBaudCapture(INST_LIN1) == STATUS_SUCCESS)
            {
                autoBaudComplete = true;
            }
        }

        /* Clear PORT interrupt register */
        PINS_DRV_ClearPortIntFlagCmd(PORTC);
    }


}

uint32_t lin1TimerGetTimeIntervalCallback0(uint32_t *ns)
{
    static uint32_t previousCountValue = 0UL;
    uint32_t counterValue;
    counterValue = capturedValue;
    *ns = ((uint32_t)(counterValue + timerOverflowInterruptCount * TIMER_COMPARE_VAL - previousCountValue)) * 1000UL / TIMER_TICKS_1US;
    timerOverflowInterruptCount = 0UL;
    previousCountValue = counterValue;
    return 0UL;
}
