/*
 * diagnostic_DID.h
 *
 *  Created on: Feb 16, 2019
 *      Author: Administrator
 */

#ifndef DIAGNOSTIC_DID_H_
#define DIAGNOSTIC_DID_H_

#include "diagnostic_service_slave.h"

#define DEF_DID_NUM		67

typedef struct
{
	unsigned int 		DID_id;
	unsigned char		length;
	DIDSRVFUNCTION_DEF DID_Func;		
}TYPE_DIDSRVARR;

extern const TYPE_DIDSRVARR DID_CheckArr[];





void DIDsrv_ReadSoftwareVersion(unsigned char length,unsigned char * addr);
void DIDsrv_ReadHardwareVersion(unsigned char length,unsigned char * addr);
void DIDsrv_ReadBootloaderVersion(unsigned char length,unsigned char * addr);
void DIDsrv_ReadDMPartNumber(unsigned char length,unsigned char * addr);
void DIDsrv_ReadManufacturingData(unsigned char length,unsigned char * addr);
void DIDsrv_ReadECUname(unsigned char length,unsigned char * addr);
void DataCopy8bit(unsigned char* source,unsigned char* dest,unsigned char length);
void DIDsrv_ReadConfiguration(unsigned char length,unsigned char * addr);
void DIDsrv_ReadPartnumber(unsigned char length,unsigned char * addr);
void DIDsrv_ReadResetSource(unsigned char length,unsigned char * addr);
void DIDsrv_ReadActiveSession(unsigned char length,unsigned char * addr);
void DIDsrv_ReadVIN(unsigned char length,unsigned char * addr);
void DIDsrv_ReadTestData(unsigned char length,unsigned char * addr);
void DIDsrv_ReadTouchBaseline(unsigned char length,unsigned char * addr);
void DIDsrv_ReadTouchSignal(unsigned char length,unsigned char * addr);
void DIDsrv_ReadTouchTh(unsigned char length,unsigned char * addr);
void DIDsrv_ReadReleaseTh(unsigned char length,unsigned char * addr);
void DIDsrv_ReadPressValue(unsigned char length,unsigned char * addr);
void DIDsrv_ReadPressRatio(unsigned char length,unsigned char * addr);
void DIDsrv_ReadBaseAndSignal(unsigned char length,unsigned char * addr);

#endif /* DIAGNOSTIC_DID_H_ */
