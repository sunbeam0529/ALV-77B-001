/*
 * diagnostic_DID.c
 *
 *  Created on: 2020/1/24
 *      Author: Administrator
 */


#include "diagnostic_DID.h"

/*******************************配置DID*************************************/
const TYPE_DIDSRVARR DID_CheckArr[DEF_DID_NUM]={
        {0xF190,	11,	&DIDsrv_ReadVIN},
        {0xF103,    7,  &DIDsrv_ReadPartnumber},//客户件号
        {0xF186,    1,  &DIDsrv_ReadActiveSession},//当前会话
        {0xF18B,	4,	&DIDsrv_ReadManufacturingData},//制造日期
        {0xF101,	4,	&DIDsrv_ReadBootloaderVersion},//boot版本
        {0xFD01,	4,	&DIDsrv_ReadDMPartNumber},    //公司内部件号
		
		{0xF192,	6,	&DIDsrv_ReadHardwareVersion},//软件版本号
		{0xF194,	6,	&DIDsrv_ReadSoftwareVersion},//硬件版本号
        {0xF180,	1,	&DIDsrv_ReadResetSource},//读取复位源
        //{0xF000,	3,	&DIDsrv_ReadTestData},//

        //?9
		{0xFA00,	3,	&DIDsrv_ReadTestData},
		{0xFA01,	3,	&DIDsrv_ReadTestData},
		{0xFA02,	3,	&DIDsrv_ReadTestData},
		{0xFA03,	3,	&DIDsrv_ReadTestData},
		{0xFA04,	3,	&DIDsrv_ReadTestData},
		{0xFA05,	3,	&DIDsrv_ReadTestData},
		{0xFA06,	3,	&DIDsrv_ReadTestData},
		{0xFA07,	3,	&DIDsrv_ReadTestData},
        //?17
        {0xF000,	2,	&DIDsrv_ReadTouchSignal},
        {0xF001,	2,	&DIDsrv_ReadTouchSignal},
        {0xF002,	2,	&DIDsrv_ReadTouchSignal},
        {0xF003,	2,	&DIDsrv_ReadTouchSignal},
        {0xF004,	2,	&DIDsrv_ReadTouchSignal},
        {0xF005,	2,	&DIDsrv_ReadTouchSignal},
        {0xF006,	2,	&DIDsrv_ReadTouchSignal},
        {0xF007,	2,	&DIDsrv_ReadTouchSignal},
        //?25
        {0xF010,	2,	&DIDsrv_ReadTouchBaseline},
        {0xF011,	2,	&DIDsrv_ReadTouchBaseline},
        {0xF012,	2,	&DIDsrv_ReadTouchBaseline},
        {0xF013,	2,	&DIDsrv_ReadTouchBaseline},
        {0xF014,	2,	&DIDsrv_ReadTouchBaseline},
        {0xF015,	2,	&DIDsrv_ReadTouchBaseline},
        {0xF016,	2,	&DIDsrv_ReadTouchBaseline},
        {0xF017,	2,	&DIDsrv_ReadTouchBaseline},
        //?33
        {0xF020,	2,	&DIDsrv_ReadTouchTh},
        {0xF021,	2,	&DIDsrv_ReadTouchTh},
        {0xF022,	2,	&DIDsrv_ReadTouchTh},
        {0xF023,	2,	&DIDsrv_ReadTouchTh},
        {0xF024,	2,	&DIDsrv_ReadTouchTh},
        {0xF025,	2,	&DIDsrv_ReadTouchTh},
        {0xF026,	2,	&DIDsrv_ReadTouchTh},
        {0xF027,	2,	&DIDsrv_ReadTouchTh},
        //?41
        {0xF030,	2,	&DIDsrv_ReadReleaseTh},
        {0xF031,	2,	&DIDsrv_ReadReleaseTh},
        {0xF032,	2,	&DIDsrv_ReadReleaseTh},
        {0xF033,	2,	&DIDsrv_ReadReleaseTh},
        {0xF034,	2,	&DIDsrv_ReadReleaseTh},
        {0xF035,	2,	&DIDsrv_ReadReleaseTh},
        {0xF036,	2,	&DIDsrv_ReadReleaseTh},
        {0xF037,	2,	&DIDsrv_ReadReleaseTh},
        //?49
        {0xF040,	2,	&DIDsrv_ReadPressValue},
        {0xF041,	2,	&DIDsrv_ReadPressValue},
        //?51
        {0xF050,	1,	&DIDsrv_ReadPressRatio},
        {0xF051,	1,	&DIDsrv_ReadPressRatio},
        {0xF052,	1,	&DIDsrv_ReadPressRatio},
        {0xF053,	1,	&DIDsrv_ReadPressRatio},
        {0xF054,	1,	&DIDsrv_ReadPressRatio},
        {0xF055,	1,	&DIDsrv_ReadPressRatio},
        {0xF056,	1,	&DIDsrv_ReadPressRatio},
        {0xF057,	1,	&DIDsrv_ReadPressRatio},
        //?59
        {0xF060,	6,	&DIDsrv_ReadBaseAndSignal},
        {0xF061,	6,	&DIDsrv_ReadBaseAndSignal},
        {0xF062,	6,	&DIDsrv_ReadBaseAndSignal},
        {0xF063,	6,	&DIDsrv_ReadBaseAndSignal},
        {0xF064,	6,	&DIDsrv_ReadBaseAndSignal},
        {0xF065,	6,	&DIDsrv_ReadBaseAndSignal},
        {0xF066,	6,	&DIDsrv_ReadBaseAndSignal},
        {0xF067,	6,	&DIDsrv_ReadBaseAndSignal},
};
const char DIDList_VIN[11]="00000000000";
const char DIDList_SWVersion[8]="SW0101";
const char DIDList_HWVersion[8]="HW01";
const char DIDList_BootVersion[8]="NULL";
const unsigned char DIDList_DMPartNumber[8]={0x11,0x22,0x33,0x44};
const unsigned char DIDList_ManufacturingData[8]={0x20,0x21,0x12,0x19};
const char DIDList_ECUname[16]="DMK-ALV-77B";
const char DIDList_PartNum[8]="1000001 ";

extern l_u8 master_req_dat[MASTER_REQ_LENGTH_MAX];
/******************************************************************************/
//for test
extern uint8_t PortMode_data,config_this_time;

extern int32_t  elecDCTracker[];
extern uint32_t TouchSensorSignalValue[];
extern int32_t  elecThresholdTouchDelta[], elecThresholdReleaseDelta[];
extern int16_t  press;
extern uint8_t  TouchRatioArr[];
/******************************************************************************/

void DIDsrv_ReadSoftwareVersion(unsigned char length,unsigned char * addr)
{
	DataCopy8bit((unsigned char *)DIDList_SWVersion,addr,length);
}
void DIDsrv_ReadHardwareVersion(unsigned char length,unsigned char * addr)
{
	DataCopy8bit((unsigned char *)DIDList_HWVersion,addr,length);
}
void DIDsrv_ReadBootloaderVersion(unsigned char length,unsigned char * addr)
{
	DataCopy8bit((unsigned char *)DIDList_BootVersion,addr,length);
}
void DIDsrv_ReadDMPartNumber(unsigned char length,unsigned char * addr)
{
	DataCopy8bit((unsigned char *)DIDList_DMPartNumber,addr,length);
}
void DIDsrv_ReadManufacturingData(unsigned char length,unsigned char * addr)
{
	DataCopy8bit((unsigned char *)DIDList_ManufacturingData,addr,length);
}
void DIDsrv_ReadECUname(unsigned char length,unsigned char * addr)
{
	DataCopy8bit((unsigned char *)(DIDList_ECUname),addr,length);
}

void DIDsrv_ReadPartnumber(unsigned char length,unsigned char * addr)
{
    DataCopy8bit((unsigned char *)(DIDList_PartNum),addr,length);
}

void DIDsrv_ReadVIN(unsigned char length,unsigned char * addr)
{
    DataCopy8bit((unsigned char *)(DIDList_VIN),addr,length);
}

void DIDsrv_ReadActiveSession(unsigned char length,unsigned char * addr)
{
    addr[0] = 1;
}

void DIDsrv_ReadResetSource(unsigned char length,unsigned char * addr)
{
    addr[0] = 0;
}

void DIDsrv_ReadTestData(unsigned char length,unsigned char * addr)
{
    addr[0] = PortMode_data;
    addr[1] = config_this_time;
    addr[2] = 0;
}

void DIDsrv_ReadTouchBaseline(unsigned char length,unsigned char * addr)
{
	uint8_t touchID=0;
    uint16_t baseline;
	touchID = master_req_dat[2]&0x0f;
    if(touchID > 7)
    {
        touchID = 0;
    }
    baseline = elecDCTracker[touchID];//baseline
    addr[0] = baseline>>8;
    addr[1] = baseline&0xff;
}

void DIDsrv_ReadTouchSignal(unsigned char length,unsigned char * addr)
{
	uint8_t touchID=0;
    uint16_t signal;
	touchID = master_req_dat[2]&0x0f;
    if(touchID > 7)
    {
        touchID = 0;
    }
    signal = TouchSensorSignalValue[touchID];//signal
    addr[0] = signal>>8;
    addr[1] = signal&0xff;

}
void DIDsrv_ReadTouchTh(unsigned char length,unsigned char * addr)
{
	uint8_t touchID=0;
    uint16_t TouchTh;
	touchID = master_req_dat[2]&0x0f;
    if(touchID > 7)
    {
        touchID = 0;
    }
    TouchTh = elecThresholdTouchDelta[touchID];//TouchTh
    addr[0] = TouchTh>>8;
    addr[1] = TouchTh&0xff;
}
void DIDsrv_ReadReleaseTh(unsigned char length,unsigned char * addr)
{
	uint8_t touchID=0;
    uint16_t ReleaseTh;
	touchID = master_req_dat[2]&0x0f;
    if(touchID > 7)
    {
        touchID = 0;
    }
    ReleaseTh = elecThresholdReleaseDelta[touchID];//ReleaseTh
    addr[0] = ReleaseTh>>8;
    addr[1] = ReleaseTh&0xff;
}
extern int16_t baseline;
void DIDsrv_ReadPressValue(unsigned char length,unsigned char * addr)
{
    uint8_t touchID=0;
    touchID = master_req_dat[2]&0x0f;
    if(touchID == 0)
    {
        addr[0] = press>>8;
        addr[1] = press&0xff;
    }
    else
    {
        addr[0] = baseline>>8;
        addr[1] = baseline&0xff;
    }
    
}
void DIDsrv_ReadPressRatio(unsigned char length,unsigned char * addr)
{
	uint8_t touchID=0;
	uint16_t PressRatio;
	touchID = master_req_dat[2]&0x0f;
	if(touchID > 7)
	{
		touchID = 0;
	}
	PressRatio = TouchRatioArr[touchID];//ReleaseTh
	addr[0] = PressRatio;
}

void DIDsrv_ReadBaseAndSignal(unsigned char length,unsigned char * addr)
{
	uint8_t touchID=0;
    uint16_t baseline,signal;
	touchID = master_req_dat[2]&0x0f;
    if(touchID > 7)
    {
        touchID = 0;
    }
    baseline = elecDCTracker[touchID];//baseline
    addr[0] = baseline>>8;
    addr[1] = baseline&0xff;
    signal = TouchSensorSignalValue[touchID];//signal
    addr[2] = signal>>8;
    addr[3] = signal&0xff;
    addr[4] = press>>8;
    addr[5] = press&0xff;
}

void DataCopy8bit(unsigned char* source,unsigned char* dest,unsigned char length)
{
	while(length-- > 0)
	{
		*(dest++) = *(source++);
	}
}
