#ifndef _DIAGNOSTIC_SERVICE_SLAVE_H_
#define _DIAGNOSTIC_SERVICE_SLAVE_H_

//#include "lin_commontl_api.h"
#include "lin.h"
//#include "lin_lin21tl_api.h"

/*------------------------------------------*/
#define SERIAL_NUBER_INT 			0x00
#define IO_CONTROL_STATUS_INT 0x00
#define SESSION_CONTROL_P3		0x01F4
#define SESSION_CONTROL_P3Ex  0x09C4
#define DTCSTATUSBTYE_INT			 0x00
#define DTCFORMATIDENTIFER_INT 0x01
#define COUNTDTC_INT					 0x00
/*------------------------------------------*/
/* DEFINITION */
#define MASTER_REQ_LENGTH_MAX   128
#define DEF_DIAGSERVICE_COUNT	5
/*------------------- Struct Define -----------------------*/

typedef void (*PT2FUNCTION_DEF)(void);
typedef void (*DIDSRVFUNCTION_DEF)(unsigned char,unsigned char*);


typedef struct
{
    unsigned char DiagServiceFlagOrder;
    PT2FUNCTION_DEF DiagServiceFunc;
}TYPE_DIAGSERVICEARR;

typedef union
{
    uint8_t BYTE[8];
    uint32_t DWORD[2];
    struct{
        uint8_t startflag;
        uint8_t RspData[4];
        uint8_t AckLenth;
        uint8_t boot_enable;
        uint8_t endflag;
    }data;
}TYPE_SAVEDATA;


/* diagnostic services*/
void diagsrv_read_data_by_identifier(void);
void diagsrv_write_data_by_identifier(void);
void diagsrv_session_control(void);
void diagsrv_io_control_by_identifier(void);
void diagsrv_fault_memory_read(void);
void diagsrv_fault_memory_clear(void);
void diagsrv_download_request(void);
void diagsrv_send_data(void);
void diagsrv_security_access(void);
void diagsrv_ECU_Reset(void);
void slave_diagnostic_task(void);
void SoftwareRest(void);
void slave_diagnostic_init(void);
void SaveArray_LINResp(unsigned char * buf);
void ReadArray_LINResp(unsigned char * buf);
void SetConfiguration(unsigned char c);
void resetDetect(void);
#endif /* End _DIAGNOSTIC_SERVICE_SLAVE_H_ */
