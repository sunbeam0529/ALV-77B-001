#include "lin_cfg.h"     
#include "diagnostic_service_slave.h"
#include "lin_diagnostic_service.h"
#include "diagnostic_DID.h"
#include "lin_commontl_api.h"
#include "MCP4716Drv.h"
#include "ECUM.h"
/*
#pragma DATA_SEG RESP_BUF
uint8_t  reseponse_buff[8];
#pragma DATA_SEG DEFAULT_RAM
*/
TYPE_SAVEDATA eeprom_save;

//extern byte LED_value;
const unsigned long serial_number = SERIAL_NUBER_INT; 					/* for read & write serial_number services */
const unsigned char io_control_status = IO_CONTROL_STATUS_INT;  /* for read & set io */
const unsigned int session_control_P3 = SESSION_CONTROL_P3;     /* for session control service */
const unsigned int session_control_P3Ex = SESSION_CONTROL_P3Ex; /* for session control service */

const unsigned char DtcStatusByte = DTCSTATUSBTYE_INT			; 				/* for fault memory */
const unsigned char DtcFormatIdentifier = DTCFORMATIDENTIFER_INT;   /* for fault memory */
const unsigned char CountDtc = COUNTDTC_INT;						  					/* for fault memory */


const TYPE_DIAGSERVICEARR DiagServiceCheckArr[DEF_DIAGSERVICE_COUNT]={
    {LI0_DIAGSRV_READ_DATA_BY_IDENTIFIER_ORDER,&diagsrv_read_data_by_identifier},
    {LI0_DIAGSRV_ECU_RESET_ORDER,&diagsrv_ECU_Reset},
    {LI0_DIAGSRV_WRITE_DATA_BY_IDENTIFIER_ORDER,&diagsrv_write_data_by_identifier},
    {LI0_DIAGSRV_SESSION_CONTROL_ORDER,&diagsrv_session_control},
    {LI0_DIAGSRV_SECURITY_ACCESS_ORDER,&diagsrv_security_access},
    //{LI0_DIAGSRV_SENDDATA_ORDER,&diagsrv_send_data},
    //{LI0_DIAGSRV_DOWNLOADREQUEST_ORDER,&diagsrv_download_request}
};
/**/
volatile l_u8 master_req_dat[MASTER_REQ_LENGTH_MAX],ReceiveNAD;
volatile l_u16 master_req_length;

volatile l_u8 slave_resp_dat[MASTER_REQ_LENGTH_MAX];
volatile l_u16 slave_resp_length;


l_u8 resetflag=0;

extern int32_t   elecThresholdTouchDelta[], elecThresholdReleaseDelta[];
extern uint8_t TouchRatioArr[];
typedef struct
{
    uint16_t head;
    uint8_t bootReq;
    uint8_t msgLen;
    uint8_t msgdata[10];
    uint16_t end;
}APPMSG;
APPMSG * pAppMsg;
void ClearTxBuf(void)
{
    g_lin_tl_descriptor_array[0].tx_msg_status = LD_COMPLETED;
    g_lin_tl_descriptor_array[0].tl_tx_queue.queue_current_size = 0;
}
void diagsrv_read_data_by_identifier(void)
{
	unsigned char i;
	unsigned int DID_id;
    //get pdu data

	DID_id = master_req_dat[1];
	DID_id <<= 8;
	DID_id |= master_req_dat[2];

	for(i=0;i<DEF_DID_NUM;i++)
	{
		if(DID_CheckArr[i].DID_id == DID_id)
		{
			DID_CheckArr[i].DID_Func(DID_CheckArr[i].length,(unsigned char *)slave_resp_dat+3);
			slave_resp_length = 3+DID_CheckArr[i].length;
			slave_resp_dat[0] = master_req_dat[0] + 0x40;
			slave_resp_dat[1] = master_req_dat[1];
			slave_resp_dat[2] = master_req_dat[2];
			break;
		}
	}
	if(DEF_DID_NUM == i)
	{
	    /* 否定响应，不支持响应DID */
		slave_resp_length = 5;
		slave_resp_dat[0] = 0x7F;
		slave_resp_dat[1] = master_req_dat[0];
		slave_resp_dat[2] = 0x31;//否定响应码

	}
  /* get data from queue to data */
  
  ClearTxBuf();
  /* send a message to master */
  ld_send_message(LI0,slave_resp_length,ReceiveNAD,(l_u8*)slave_resp_dat);
  /*clear diagnostic flag */
}

void diagsrv_write_data_by_identifier(void)
{
	volatile unsigned int DID_id=0,DID_mask=0;
	volatile unsigned char data=0,touchID=0;
    volatile unsigned int writevalue = 0;
	//get pdu data
	DID_id = master_req_dat[1];
	DID_id <<= 8;
	DID_id |= master_req_dat[2];
	DID_mask = DID_id&0xFFF0;
	if(DID_id == 0xFA01)
	{
		data = master_req_dat[3];
		if(data == 0x01)
		{
			StartWave();
		}
		else
		{

		}
	}
    else if(DID_mask == 0xF020)
    {
        touchID = DID_id&0x000F;
        writevalue = master_req_dat[3];
        writevalue <<= 8;
        writevalue += master_req_dat[4];
        if(touchID <=7)
        {
            elecThresholdTouchDelta[touchID] = writevalue;
        }
    }
    else if(DID_mask == 0xF030)
    {
        touchID = DID_id&0x000F;
        writevalue = master_req_dat[3];
        writevalue <<= 8;
        writevalue += master_req_dat[4];
        if(touchID <=7)
        {
            elecThresholdReleaseDelta[touchID] = writevalue;
        }
    }
    else if(DID_mask == 0xF050)
    {
    	touchID = DID_id&0x000F;
		writevalue = master_req_dat[3];
		if(touchID <=7)
		{
			TouchRatioArr[touchID] = writevalue;
		}

    }
    /* send a message to master */
    slave_resp_length = 3;
	slave_resp_dat[0] = master_req_dat[0] + 0x40;
	slave_resp_dat[1] = master_req_dat[1];
	slave_resp_dat[2] = master_req_dat[2];
    ld_send_message(LI0,slave_resp_length,ReceiveNAD,(l_u8*)slave_resp_dat);

}


void diagsrv_session_control(void)
{	
	if(master_req_dat[1] == 0x01 || master_req_dat[1] == 0x03)
	{
		slave_resp_length = 2;
        slave_resp_dat[0] = master_req_dat[0] + 0x40;
        slave_resp_dat[1] = master_req_dat[1];
        ld_send_message(LI0,slave_resp_length,ReceiveNAD,(l_u8*)slave_resp_dat);
	}
	else if(master_req_dat[1] == 0x02)
	{
		pAppMsg = (APPMSG *)0x1FFFFC00;
		pAppMsg->head = 0x55AA;
		pAppMsg->end = 0XAA55;
		pAppMsg->bootReq = 1;
		resetflag=1;
		SystemSoftwareReset();
	}

	
	//diag_clear_flag(LI0,LI0_DIAGSRV_SESSION_CONTROL_ORDER);
}
void diagsrv_io_control_by_identifier(void)
{	

}
void diagsrv_fault_memory_read(void)
{

}
void diagsrv_fault_memory_clear(void)
{

}

void diagsrv_security_access(void)
{
    uint8_t subservies;
    static uint16_t sa_seed,sa_key;

    subservies = master_req_dat[1];
    switch (subservies)
    {
    case 1:
        
        break;
    case 2:
        /* code */
        break;
    default:
        break;
    }
}

void diagsrv_ECU_Reset(void)
{
    unsigned char subfunction;
    //get pdu data
    subfunction = master_req_dat[1];

    //reset
    if(subfunction == 1)
    {
        //Hard Reset
        //TODO:增加硬件复位
        SystemSoftwareReset();
    }
    else if( subfunction == 3)
    {
        //Soft Reset
        SystemSoftwareReset();
    }
    else
    {
        slave_resp_length = 5;
		slave_resp_dat[0] = 0x7F;
		slave_resp_dat[1] = master_req_dat[0];
		slave_resp_dat[2] = 0x12;//否定响应码
    }
    
    //reply
    /* send a message to master */
    ld_send_message(LI0,slave_resp_length,ReceiveNAD,(l_u8*)slave_resp_dat);
}

void diagsrv_send_data(void)
{
	//ld_receive_message((l_u16*)&master_req_length,(l_u8*)master_req_dat);
	
}
void diagsrv_download_request(void)
{
    
}

//extern volatile l_signal_handle slave_signal_handle;
extern volatile l_u8* slave_sig_data;
extern volatile unsigned char sw_flag;

void FreshRxbuf(void)
{
    master_req_length = MASTER_REQ_LENGTH_MAX;
    ReceiveNAD = 0x20;
	ld_receive_message(LI0,&master_req_length,&ReceiveNAD,master_req_dat);
}

void slave_diagnostic_task()
{
  unsigned char i = 0x00;	
  unsigned char data;

  for (i = 0; i < DEF_DIAGSERVICE_COUNT; i++)
  {
    	if (diag_get_flag(LI0,DiagServiceCheckArr[i].DiagServiceFlagOrder))
	    {
		    DiagServiceCheckArr[i].DiagServiceFunc();
            diag_clear_flag(LI0,DiagServiceCheckArr[i].DiagServiceFlagOrder);//
            FreshRxbuf();
	    }	
  }

}

void SoftwareRest(void)
{
	while(1);
}

void slave_diagnostic_init(void)
{
	
	FreshRxbuf();
	
}



void resetDetect(void)
{
    static resetcnt;
    if(resetflag == 1)
    {
        resetcnt++;
        if(resetcnt>10)
            SoftwareRest();
    }
    else
    {
        resetcnt=0;
    }
}
