
#include "PressSensor.h"
#include "SW_I2C.h"

lpi2c_master_state_t lpi2c1MasterState;
flexio_i2c_master_state_t i2cMasterState;
flexio_device_state_t flexIOI2CDeviceState;
uint8_t ReadReg(uint8_t dev,uint8_t reg)
{
    uint8_t txbuf[2],ret;
    switch (dev)
    {
    case 1:
        txbuf[0] = reg;
        LPI2C_DRV_MasterSetSlaveAddr(INST_LPI2C1,0x46,false);
        ret = LPI2C_DRV_MasterSendDataBlocking(INST_LPI2C1, txbuf, 1, true, 10);
        ret = LPI2C_DRV_MasterReceiveDataBlocking(INST_LPI2C1, txbuf, 1, true, 10);
        return txbuf[0];
        break;
    case 2:
        txbuf[0] = reg;
        FLEXIO_I2C_DRV_MasterSetSlaveAddr(&i2cMasterState,0x46);
        ret = FLEXIO_I2C_DRV_MasterSendDataBlocking(&i2cMasterState, txbuf, 1, true, 10);
        ret = FLEXIO_I2C_DRV_MasterReceiveDataBlocking(&i2cMasterState, txbuf, 1, true, 10);
        return txbuf[0];
        break;
    case 3:
        txbuf[0] = reg;
        ret = SWI2C_SendDataBlocking(0x46, txbuf, 1, true);
        ret = SWI2C_ReceiveDataBlocking(0x46, txbuf, 1, true);
        return txbuf[0];
        break;
    default:
        break;
    }
    return 0;
    
}

void WriteReg(uint8_t dev,uint8_t reg,uint8_t data)
{
    uint8_t txbuf[2],ret;
    txbuf[0] = reg;
    txbuf[1] = data;
    LPI2C_DRV_MasterSendDataBlocking(INST_LPI2C1, txbuf, 2, true, 10);

    switch (dev)
    {
    case 1:
        LPI2C_DRV_MasterSetSlaveAddr(INST_LPI2C1,0x46,false);
        ret = LPI2C_DRV_MasterSendDataBlocking(INST_LPI2C1, txbuf, 2, true, 10);
        return;
        break;
    case 2:
        FLEXIO_I2C_DRV_MasterSetSlaveAddr(&i2cMasterState,0x46);
        ret = FLEXIO_I2C_DRV_MasterSendDataBlocking(&i2cMasterState, txbuf, 2, true, 10);
        return;
        break;
    case 3:
        ret = SWI2C_SendDataBlocking(0x46, txbuf, 2, true);
        return;
        break;
    default:
        break;
    }
}

void PressSensorInit(void)
{
    LPI2C_DRV_MasterInit(INST_LPI2C1, &lpi2c1_MasterConfig0, &lpi2c1MasterState);
    FLEXIO_DRV_InitDevice(INST_FLEXIO_I2C1, &flexIOI2CDeviceState);
    FLEXIO_I2C_DRV_MasterInit(INST_FLEXIO_I2C1, &flexio_i2c1_MasterConfig0, &i2cMasterState);
    //WriteReg(0x01,0x60);
    WriteReg(1,0x07,0x07);//ÔëÉùãĞÖµ¸ÄÎª0x70
}

uint8_t GetPressPreload(uint8_t dev)
{

	uint8_t retVal=0;
	retVal = ReadReg(dev,0x0B);

	return retVal>>3;
}

uint16_t GetPressRawdata(uint8_t dev)
{
	uint8_t retVal=0;
	uint16_t Rawdata=0;
	retVal = ReadReg(dev,0x14);
	Rawdata = retVal;
	Rawdata <<= 4;
	retVal = ReadReg(dev,0x15);
	retVal >>= 4;
	Rawdata += Rawdata;

	return Rawdata;
}

int16_t GetPressBaseline(uint8_t dev)
{
	uint8_t retVal=0;
	int16_t Rawdata=0;
	retVal = ReadReg(dev,0x12);
	Rawdata = retVal;
	Rawdata <<= 4;
	retVal = ReadReg(dev,0x13);
	retVal >>= 4;
	Rawdata += retVal;
	if(Rawdata > 2047)
	{
		Rawdata = 0-(Rawdata & 0x7ff);
	}
	return Rawdata;
}

uint16_t GetPressValue(uint8_t dev)
{
    uint16_t press=0;
    uint8_t ret=0;

    ret = ReadReg(dev,0x03);
    press = ret;
    ret = ReadReg(dev,0x04);
    ret >>=  4 ;
    press <<= 4;
    press += ret;
    if(press > 2047)
    {
        press = 0;
    }

    return press;
}
