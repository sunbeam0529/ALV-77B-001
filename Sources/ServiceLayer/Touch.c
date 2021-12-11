
#include "Cpu.h"
#include "filter.h"
#include "touch.h"
#include "ets.h"
#include "lptmr.h"
#include "adc.h"
#include "PressSensor.h"
#include "power_mode.h"

#define sample_no  0

// ADC0 and ADC1 gain register results after calibration
int16_t calibrationGainADC0;
uint8_t scanningIdleFlag;
// Low power mode
extern uint8_t  lowPowerModeCtrl, lowPowerModeEnable;
extern int16_t   numberOfElectrodeSensingCyclesPerSample;
extern uint8_t   electrodeTouchQualified[NUMBER_OF_ELECTRODES];
extern int16_t   elecNumberOfSamples[NUMBER_OF_ELECTRODES];
extern int16_t   elecNumberOfSamplesActive[NUMBER_OF_ELECTRODES];
extern int32_t   elecRawData[NUMBER_OF_ELECTRODES][NUMBER_OF_HOPPING_FREQUENCIES];
extern int32_t   elecDCTrackerBuffer[NUMBER_OF_ELECTRODES];
extern uint8_t   elecDCTrackerShift[NUMBER_OF_ELECTRODES];
extern int32_t   elecDCTracker[NUMBER_OF_ELECTRODES];
extern int32_t   elecThresholdTouch[NUMBER_OF_ELECTRODES], elecThresholdRelease[NUMBER_OF_ELECTRODES];
extern int16_t   elecThresholdTouchDelta[NUMBER_OF_ELECTRODES], elecThresholdReleaseDelta[NUMBER_OF_ELECTRODES];
extern uint8_t   elecTouch[NUMBER_OF_ELECTRODES][NUMBER_OF_HOPPING_FREQUENCIES];
extern tFrac32   elecLPFilterData[NUMBER_OF_ELECTRODES][NUMBER_OF_HOPPING_FREQUENCIES];
extern uint8_t   firstButtonElecNum;
extern uint8_t   elecNum;
extern uint8_t   sliderElectrodeTouchQualified;
extern uint8_t samplesReadyFlag, proximityDetectedFlag, electrodesSelfTrimDoneFlag;
extern uint8_t  frequencyID;
uint8_t keysignal[8];
uint8_t TouchDetectDoneFlag=0;
uint8_t TouchKeyALL;
uint32_t TouchSensorSignalValue[NUMBER_OF_ELECTRODES];
uint8_t key_OK,key_RETURN,key_UP,key_DOWN,key_PHONE,key_volplus,key_volminus;
uint32_t LIN_PressTH,LIN_MotorDrvCycle,LIN_MotorDrvLevel;
static uint8_t SliderDelayCounter=0,SliderDir=0;
volatile uint32_t release_time;
uint8_t release_start;

uint8_t touch_count=0;

uint8_t TouchRatioArr[8] = {10,10,10,10,10,10,10,10};

uint32_t SliderFilter(uint32_t newdata)
{
    static uint32_t SliderFilterArr[16];
    static uint8_t datapointer=0,datanum=0;;
    uint8_t i;
    uint32_t datamax=0,datamin=1000,sum=0;
    SliderFilterArr[(datapointer++)&0x0f] = newdata;
    for(i=0;i<8;i++)
    {
        sum += SliderFilterArr[i];
        if(datamax < SliderFilterArr[i])
            datamax = SliderFilterArr[i];
        if(datamin > SliderFilterArr[i])
            datamin = SliderFilterArr[i];
    }
    sum -= datamin;
    sum -= datamax;
    sum /= 6;
    if(sum == 0)
    {
        datanum = 0;
    }
    else
    {
        if(datanum < 8)
            datanum++;
    }
    if(datanum > 7)
    {
        return sum;
    }
    else
    {
        return 0;
    }
}
void TouchInit(void)
{
    LPTMR0_Init(LPTMR_ELEC_CAL);
    //NVIC_IRQ_ENABLE(LPTMR0_IRQn); // Enable LPTMR0 interrupts in NVIC
    calibrationGainADC0 = ADC0_Calibration();
    ADC0_Init(ADC_SWTRIGGER_SAMPLE_TIME, 0, RUN_FIRC);
    lowPowerModeCtrl = OFF;
    ElectrodesTouchSenseInit();
    INT_SYS_EnableIRQ(LPTMR0_IRQn);
}

void TouchDetect(void)
{
    // Electrodes samples set scanned and ready?
		if (samplesReadyFlag == 1) // Yes, do touch digital processing and touch detecting routine
		{

			// Electrodes self-trim done?
			if(electrodesSelfTrimDoneFlag == 1)
			{
				TouchDetectDoneFlag = 1;
				// Process all touch electrodes raw data
				ElectrodesTouchElecProcess();
				// Check for virtual wake up event
				ElectrodesVirtualWakeupEventCtrl();
				// Data have been processed, continue
				samplesReadyFlag = 0;


			}
			else
			{
				// Self-trim all electrodes after power-up / reset
				ElectrodesSelfTrimProcess();
				// Data have been processed, continue
				samplesReadyFlag = 0;
				// Self-trimming done?
				if (electrodesSelfTrimDoneFlag == 1)
				{
					// Reset frequencyID
					frequencyID = 0;
				}
			}

			// Are we back on the base scanning frequency?
			if (frequencyID == 0)
			{
				// Set scanning (DMA) Idle flag
				scanningIdleFlag = 1;
			}
		}
		else // No electrodes data set ready, do whatever else you want
		{

		}
}
int16_t press,preload,baseline,rawdata;//for debug
void TouchProcess(void)
{
    static uint8_t keypresslast,pressflag,slideflag,releaseflag=1,slider_delay=0;
    static uint32_t lastlocation;
    //uint16_t press,preload;
    volatile uint32_t location;
    if(TouchDetectDoneFlag == 1)
    {

        TouchDetectDoneFlag = 0;
        TouchKeyALL = 0;
        for (elecNum = 0; elecNum < NUMBER_OF_BUTTON_ELECTRODES; elecNum++)//NUMBER_OF_BUTTON_ELECTRODES
        {
            // Electrode touched?
            if (elecTouch[elecNum][0] == 1)
            {
                // Load electrode number
                TouchKeyALL |= 1<<elecNum;
                keysignal[elecNum] = 1;
            }
            else
            {
                keysignal[elecNum] = 0;
                //TouchKeyALL &= ~~(1<<elecNum);
            }

            //get touch signal value
            if(elecDCTracker[elecNum] > elecLPFilterData[elecNum][0])
            {
                TouchSensorSignalValue[elecNum] = elecDCTracker[elecNum] - elecLPFilterData[elecNum][0];
            }	
            else
            {
                TouchSensorSignalValue[elecNum] = 0;
            }
        }
        if(TouchKeyALL == 0)
        {
            PINS_DRV_WritePin(PTE,9,0);
        }
        else
        {
            PINS_DRV_WritePin(PTE,9,1);
        }
        if(keypresslast != (TouchKeyALL?1:0))
        {
            keypresslast = (TouchKeyALL?1:0);
            if(keypresslast == 1)
            {
                //MotorEnable();
            }
        }

        if((TouchKeyALL&0xf8) != 0 && pressflag == 0 && press > LIN_PressTH && slideflag == 0)
        {
            pressflag = 1;
            //MotorEnable();
            releaseflag = 0;
        }
        if((TouchKeyALL&0x05) != 0 && pressflag == 0 && press > (LIN_PressTH) && slideflag == 0)
		{
			pressflag = 1;
			//MotorEnable();
			releaseflag = 0;
		}

        if(press < (LIN_PressTH>>2) || press < 20)
        {
        	if(releaseflag == 0)
        	{
        		releaseflag = 1;

        		//MotorEnableRelease();
        	}
        	if(TouchKeyALL == 0)
            	pressflag = 0;
        }

        location = ((TouchSensorSignalValue[0]*2 + TouchSensorSignalValue[1])*50)/(TouchSensorSignalValue[0]+TouchSensorSignalValue[1]+TouchSensorSignalValue[2]);
        
            
        location = SliderFilter(location);
        if(keysignal[0] == 0 && keysignal[1] == 0 && keysignal[2] == 0)
        {
            location = 0;
            slideflag = 0;
        }       
        else
        {
        	SliderDelayCounter = 20;
        }


        if(lastlocation != location)
        {
            if(lastlocation == 0)
            {
                //if(pressflag == 0)
                	//MotorEnableSlider();
                lastlocation = location;
            }
            else if(location < 30)
            {
                    lastlocation = location;
                    //MotorDisable();
            }	
            else if( (lastlocation > location+30) || (lastlocation < location-30))
            {
                SliderDelayCounter = 20;
                slideflag = 1;
                if(lastlocation > location+30)
                {
                	if(SliderDir > 0)
                		SliderDir--;
                }
                else
                {
                    if(SliderDir < 10)
                    	SliderDir++;
                }
                
                lastlocation = location;
                //if(pressflag == 0 && press > (LIN_PressTH>>4))
                	//MotorEnableSlider();
            }	  
                      
        }                                                                                                                                                               
        if(keysignal[3]== 1 && press > LIN_PressTH)
        {
            key_OK = 1;
        }
        else if(keysignal[3] == 0)
        {
            key_OK = 0;
        }
        if(keysignal[4]== 1 && press > LIN_PressTH)
        {
            key_DOWN = 1;
        }
        else if(keysignal[4] == 0)
        {
            key_DOWN = 0;
        }

        if(keysignal[5]== 1 && press > LIN_PressTH)
        {
            key_UP = 1;
        }
        else if(keysignal[5] == 0)
        {
            key_UP = 0;
        }

        if(keysignal[6]== 1 && press > LIN_PressTH)
        {
            key_PHONE = 1;

        }
        else if(keysignal[6] == 0)
        {
            key_PHONE = 0;
        }

        if(keysignal[7]== 1 && press > LIN_PressTH)
        {
            key_RETURN = 1;
        }
        else if(keysignal[7] == 0)
        {
            key_RETURN = 0;
        }
        if(keysignal[0]== 1 && press > (LIN_PressTH/2))
		{
        	key_volplus = 1;
		}
		else if(keysignal[0] == 0)
		{
			key_volplus = 0;
		}

		if(keysignal[2]== 1 && press > (LIN_PressTH/2))
		{
			key_volminus = 1;
		}
		else if(keysignal[2] == 0)
		{
			key_volminus = 0;
		}

    }
}
