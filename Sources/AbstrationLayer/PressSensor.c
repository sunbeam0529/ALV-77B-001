
#include "PressSensor.h"

lpi2c_master_state_t lpi2c1MasterState;


uint8_t ReadReg(uint8_t reg)
{
    uint8_t txbuf[2],ret;
    txbuf[0] = reg;
    ret = LPI2C_DRV_MasterSendDataBlocking(INST_LPI2C1, txbuf, 1, true, 10);
    ret = LPI2C_DRV_MasterReceiveDataBlocking(INST_LPI2C1, txbuf, 1, true, 10);

    return txbuf[0];
}

void WriteReg(uint8_t reg,uint8_t data)
{
    uint8_t txbuf[2];
    txbuf[0] = reg;
    txbuf[1] = data;
    LPI2C_DRV_MasterSendDataBlocking(INST_LPI2C1, txbuf, 2, true, 10);
}

void PressSensorInit(void)
{
    LPI2C_DRV_MasterInit(INST_LPI2C1, &lpi2c1_MasterConfig0, &lpi2c1MasterState);
    //WriteReg(0x01,0x60);
    WriteReg(0x07,0x07);//ÔëÉùãĞÖµ¸ÄÎª0x70
}

uint8_t GetPressPreload(void)
{

	uint8_t retVal=0;
	retVal = ReadReg(0x0B);

	return retVal>>3;
}

uint16_t GetPressRawdata(void)
{
	uint8_t retVal=0;
	uint16_t Rawdata=0;
	retVal = ReadReg(0x14);
	Rawdata = retVal;
	Rawdata <<= 4;
	retVal = ReadReg(0x15);
	retVal >>= 4;
	Rawdata += Rawdata;

	return Rawdata;
}

int16_t GetPressBaseline(void)
{
	uint8_t retVal=0;
	int16_t Rawdata=0;
	retVal = ReadReg(0x12);
	Rawdata = retVal;
	Rawdata <<= 4;
	retVal = ReadReg(0x13);
	retVal >>= 4;
	Rawdata += retVal;
	if(Rawdata > 2047)
	{
		Rawdata = 0-(Rawdata & 0x7ff);
	}
	return Rawdata;
}

uint16_t GetPressValue(void)
{
    uint16_t press=0;
    uint8_t ret=0;

    ret = ReadReg(0x03);
    press = ret;
    ret = ReadReg(0x04);
    ret >>=  4 ;
    press <<= 4;
    press += ret;
    if(press > 2047)
    {
        press = 0;
    }

    return press;
}
