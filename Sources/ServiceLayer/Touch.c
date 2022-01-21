
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
uint8_t keysignal[8],keypress[8];
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
uint8_t TouchReleaseDelay[8]={0};

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
    volatile uint32_t location;
    uint8_t keysum=0,keynum=0;
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

        //l_u8_wr_LI0_L_BYTE1(TouchKeyALL);//
		l_u8_wr_LI0_L_BYTE2((TouchSensorSignalValue[1]>>2)<255?TouchSensorSignalValue[1]>>2:255);//UP
		l_u8_wr_LI0_L_BYTE3((TouchSensorSignalValue[2]>>2)<255?TouchSensorSignalValue[2]>>2:255);//LEFT
		l_u8_wr_LI0_L_BYTE4((TouchSensorSignalValue[3]>>2)<255?TouchSensorSignalValue[3]>>2:255);//OK
		l_u8_wr_LI0_L_BYTE5((TouchSensorSignalValue[4]>>2)<255?TouchSensorSignalValue[4]>>2:255);//RIGHT
		l_u8_wr_LI0_L_BYTE6((TouchSensorSignalValue[5]>>2)<255?TouchSensorSignalValue[5]>>2:255);//DOWN
		l_u8_wr_LI0_L_BYTE7((TouchSensorSignalValue[6]>>2)<255?TouchSensorSignalValue[6]>>2:255);//LB
		l_u8_wr_LI0_L_BYTE8((TouchSensorSignalValue[7]>>2)<255?TouchSensorSignalValue[7]>>2:255);

        if(pressflag == 0)
        {
            //keypress[0] = keysignal[0];
            keypress[1] = keysignal[1];
            keypress[2] = keysignal[2];
            keypress[3] = keysignal[3];
            keypress[4] = keysignal[4];
            keypress[5] = keysignal[5];
            keypress[6] = keysignal[6];

            keysum = 0;
            for (uint8_t i = 1; i < 7; i++)
            {
                if (keypress[i] == 1)
                {
                    keysum++;
                    keynum = i;
                }
            }
            if (keysum == 1 && press > 100)
            {
                pressflag = 1;
                StartWave();
                l_u8_wr_LI0_L_BYTE1(keynum);
                switch (keynum)
                {
                case 0:
                    
                break;
                case 1:
                    l_u8_wr_LI0_MFS_UP_switch_signal(1);
                break;
                case 2:
                    l_u8_wr_LI0_MFS_LEFT_switch_signal(1);
                break;
                case 3:
                    l_u8_wr_LI0_MFS_OK_switch_signal(1);
                break;
                case 4:
                    l_u8_wr_LI0_MFS_RIGHT_switch_signal(1);
                break;
                case 5:
                    l_u8_wr_LI0_MFS_DOWN_switch_signal(1);
                break;
                case 6:
                    l_u8_wr_LI0_L_LB(1);
                break;
                default:
                    break;
                }
            }
            
        }
        else
        {
            for (uint8_t i = 0; i < 8; i++)
            {
                if (keysignal[i] == 1)
                {
                    keysum++;
                    keynum = i;
                }
            }
            if(keysum == 0 && press < 50)
            {
                pressflag = 0;
                l_u8_wr_LI0_MFS_UP_switch_signal(0);
                l_u8_wr_LI0_MFS_LEFT_switch_signal(0);
                l_u8_wr_LI0_MFS_OK_switch_signal(0);
                l_u8_wr_LI0_MFS_RIGHT_switch_signal(0);
                l_u8_wr_LI0_MFS_DOWN_switch_signal(0);
                l_u8_wr_LI0_L_LB(0);
            }
        }
    }
}
