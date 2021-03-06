/** ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**
**     @file      lin_cfg.c
**
**     @date      14:57:57, 2021-12-26
**
**     @brief     Hardware configuration file
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc.
**     Copyright 2016 - 2017 NXP
**     All Rights Reserved.
**
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/

/*!
 * @file lin_cfg.c
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, Could be made static.
 * Function ld_read_by_id_callout is API and shall not be made static.
 * This API is declared in lin_cfg.c so that users can configure the response
 * for  Read by ID request.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.9, An object should be defined at block
 * scope if its identifier only appears in a single function.
 * An object with static storage duration declared at block scope cannot be
 * accessed directly from outside the block. g_lin_hardware_ifc, g_lin_tl_descriptor_array,
 * timerGetTimeIntervalCallback are dependent on user configurations,
 * so they shall be declared in lin_cfg.c.
 */

#include "lin.h"

static const l_u8 LI0_lin_diag_services_supported[LI0_DIAG_NUMBER_OF_SERVICES] = {0xB0,0xB2,0xB3,0xB4,0xB6,0xB7,0x22,0x2E,0x10,0x2F,0x19,0x14,0x11,0x27};
static l_u8 LI0_lin_diag_services_flag[LI0_DIAG_NUMBER_OF_SERVICES] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

#if (SUPPORT_TRANSPORT_LAYER == 1U)
static lin_tl_pdu_data_t      LI0_tl_tx_queue_data[11];
static lin_tl_pdu_data_t      LI0_tl_rx_queue_data[11];
#endif /* end (SUPPORT_TRANSPORT_LAYER == 1U) */

const l_ifc_handle g_lin_hardware_ifc[HARDWARE_INSTANCE_COUNT] = {INVALID_IFC, LI0};
const l_u32 g_lin_virtual_ifc[LIN_NUM_OF_IFCS] = {1};
volatile l_u8 g_buffer_backup_data[8] = {0, 0, 0, 0, 0, 0, 0, 0};

/* definition and initialization of signal array */
volatile l_u8    g_lin_frame_data_buffer[LIN_FRAME_BUF_SIZE] =
{
  0x00 /* 0 : 00000000 */ /* start of frame LI0_MFS_LIN_1 */

  ,0x70 /* 1 : 01110000 */

  ,0x00 /* 2 : 00000000 */

  ,0x00 /* 3 : 00000000 */

  ,0x00 /* 4 : 00000000 */

  ,0x00 /* 5 : 00000000 */

  ,0x00 /* 6 : 00000000 */

  ,0x00 /* 7 : 00000000 */

  ,0x00 /* 8 : 00000000 */ /* start of frame LI0_TestFrame1 */

  ,0x00 /* 9 : 00000000 */

  ,0x00 /* 10 : 00000000 */

  ,0x00 /* 11 : 00000000 */

  ,0x00 /* 12 : 00000000 */

  ,0x00 /* 13 : 00000000 */

  ,0x00 /* 14 : 00000000 */

  ,0x00 /* 15 : 00000000 */

  ,0xff /* 16 : 11111111 */ /* start of frame LI0_MFS_LIN_2 */

  ,0xff /* 17 : 11111111 */

  ,0x00 /* 18 : 00000000 */

  ,0x00 /* 19 : 00000000 */

  ,0x00 /* 20 : 00000000 */

  ,0x00 /* 21 : 00000000 */

  ,0xf0 /* 22 : 11110000 */

  ,0xff /* 23 : 11111111 */

  ,0xff /* 24 : 11111111 */ /* start of frame LI0_GW_LIN */

  ,0x00 /* 25 : 00000000 */

  ,0x00 /* 26 : 00000000 */

  ,0x00 /* 27 : 00000000 */

  ,0x00 /* 28 : 00000000 */

  ,0x00 /* 29 : 00000000 */

  ,0x00 /* 30 : 00000000 */

  ,0x00 /* 31 : 00000000 */
};

/* definition and initialization of signal array */
volatile l_u8    g_lin_flag_handle_tbl[LIN_FLAG_BUF_SIZE] =
{
  0xFF /* 0: start of flag frame LI0_MFS_LIN_1 */,0xFF /* 1: */

  ,0xFF /* 2: start of flag frame LI0_TestFrame1 */

  ,0xFF /* 3: start of flag frame LI0_MFS_LIN_2 */

  ,0xFF /* 4: */

  ,0xFF /* 5: start of flag frame LI0_GW_LIN */
};

/* definition and initialization for flag of frame */
volatile l_bool g_lin_frame_flag_handle_tbl[LIN_NUM_OF_FRMS] = {false, false, false, false, false, false};

/*************************** Frame flag for updating signal in frame ****************/
volatile l_u8 g_lin_frame_updating_flag_tbl[LIN_NUM_OF_FRMS] = {0, 0, 0, 0, 0, 0};



/**********************************  Frame table **********************************/
static const lin_frame_t lin_frame_tbl[LIN_NUM_OF_FRMS] ={

    { LIN_FRM_UNCD, 8, LIN_RES_PUB, 0, 0, 2   , (lin_associate_frame_t*)0 }

   ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 8, 2, 1 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 16, 3, 2 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 24, 5, 1 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_DIAG, 8, LIN_RES_SUB, 0, 0, 0 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_DIAG, 8, LIN_RES_PUB, 0, 0, 0 , (lin_associate_frame_t*)0 }
  
};

static l_u8 LI0_lin_configuration_RAM[LI0_LIN_SIZE_OF_CFG]= {0x00, 0x19, 0x10, 0x1A, 0x0A, 0x3C, 0x3D ,0xFF};

static const l_u16  LI0_lin_configuration_ROM[LI0_LIN_SIZE_OF_CFG]= {0x0000, 0x19, 0x10, 0x1A, 0x0A, 0x3C, 0x3D ,0xFFFF};

static l_u8 LI0_lin_configured_NAD = 0x20;

static l_u8 LI0_lin_frm_err_resp_sig[1] = {0x19};

static l_u16 LI0_lin_response_error_byte_offset[1] = {LIN_LI0_MFS_LIN_1_Error_BYTE_OFFSET};

static l_u8 LI0_lin_response_error_bit_offset[1] = {LIN_LI0_MFS_LIN_1_Error_BIT_OFFSET};

/**************** Node attributes Initialization  ****************************/
const lin_node_attribute_t      g_lin_node_attribute_array[LIN_NUM_OF_SLAVE_IFCS]= {
    /** LI0 **/
    {
        .configured_NAD_ptr = &LI0_lin_configured_NAD,        /*configured_NAD*/
        .initial_NAD = 0x20,        /*initial_NAD*/
        .serial_number = {0x1, 0x1, 0x1, 0x1},
        .product_id = {0x0000, 0x0000, 0x00},   /*{<supplier_id>,<function_id>,<variant>}*/
        .resp_err_frm_id_ptr = LI0_lin_frm_err_resp_sig,                         /*list index of frame error*/
        .num_frame_have_esignal = 1,                                 /*number of frame contain error signal*/
        .response_error = LI0_MFS_LIN_1_Error,                  /*<interface_name>_< response_error>*/
        .response_error_byte_offset_ptr = LI0_lin_response_error_byte_offset,                  /*<interface_name>_< response_error>*/
        .response_error_bit_offset_ptr = LI0_lin_response_error_bit_offset,                  /*<interface_name>_< response_error>*/

        .P2_min = 50,     /*<P2_min>*/
        .ST_min = 0,     /*<ST_min>*/
        .N_As_timeout = 1000,   /*< N_As_timeout >*/
        .N_Cr_timeout = 1000,  /*<N_Cr_timeout >*/

        .number_support_sid = LI0_DIAG_NUMBER_OF_SERVICES,
        .service_supported_ptr = LI0_lin_diag_services_supported,
        .service_flags_ptr = LI0_lin_diag_services_flag
    }
};


/****************************LIN interface configuration ****************************/
const lin_protocol_user_config_t g_lin_protocol_user_cfg_array[LIN_NUM_OF_IFCS] = {

    /* Interface_name = LI0 */
    {
        .protocol_version = LIN_PROTOCOL_21,         /*lin_protocol_version */
        .language_version = LIN_PROTOCOL_21,         /*lin_language_version */
        .diagnostic_class = LIN_DIAGNOSTIC_CLASS_III,            /* LIN Diagnostic Class */
        .function = (bool)LIN_SLAVE,                  /*  function LIN_SLAVE*/

        .number_of_configurable_frames = 6,                            /*  num_of_frames */
        .frame_start = 0,                              /*  frame_start */
        .frame_tbl_ptr = lin_frame_tbl,                                          /*  frame_tbl */

        .list_identifiers_ROM_ptr = LI0_lin_configuration_ROM,       /*  *configuration_ROM */
        .list_identifiers_RAM_ptr = LI0_lin_configuration_RAM,       /*  *configuration_RAM */
        .max_idle_timeout_cnt =  8000,     /* Max Idle Timeout Count */
        .num_of_schedules = 0,                                  /*  num_of_schedules */
        .schedule_start = 0,                                  /*  schedule_start */
        .schedule_tbl = (const lin_schedule_t *)0,             /* schedule_tbl */

        .slave_ifc_handle = LI0_Slave,
        .master_ifc_handle = INVALID_MASTER_INDEX,
        .lin_user_config_ptr = &lin1_InitConfig0,
#if (SUPPORT_TRANSPORT_LAYER == 1U)
        .tl_tx_queue_data_ptr = LI0_tl_tx_queue_data,
        .tl_rx_queue_data_ptr = LI0_tl_rx_queue_data,
        .max_message_length = 64             /* Max message length */
#endif /* end (SUPPORT_TRANSPORT_LAYER == 1U) */
    }
};

/*FUNCTION**********************************************************************
 *
 * Function Name : ld_read_by_id_callout
 * Description   : This function is an example of response; real implementation is application-dependent
 *                 You can use one of the following define to set PCI of response frame for
 *                 this service to the correct value
 * Implements    : ld_read_by_id_callout_Activity
 *END**************************************************************************/

l_u8 ld_read_by_id_callout(l_ifc_handle iii, l_u8 id, l_u8 *data)
{
    l_u8 retval = LD_NEGATIVE_RESPONSE;

    /* Get the current configuration */
    const lin_protocol_user_config_t  *prot_user_config_ptr = &g_lin_protocol_user_cfg_array[iii];

    if (prot_user_config_ptr->function == (bool)LIN_SLAVE)
    {
        /* Following code is an example - Real implementation is application-dependent */
        /* the handling does essentially depend on the id of the requested item */
        /* This example implement with ID = 32 - LIN_READ_USR_DEF_MIN */
        if (id == LIN_READ_USR_DEF_MIN)
        {
            /*
            * id received is user defined 32
            */
            /* A positive response is ready to be sent to the user defined request */
            data[0] = (l_u8) (id + 1U);    /* Data user define */
            data[1] = (l_u8) (id + 2U);    /* Data user define */
            data[2] = (l_u8) (id + 3U);    /* Data user define */
            data[3] = (l_u8) (id + 4U);    /* Data user define */
            data[4] = (l_u8) (id + 5U);    /* Data user define */
            retval = LD_POSITIVE_RESPONSE;
        }
        else
        {
            /*
            * id received is user defined 63 - no response
            */
        }
    } /* End (conf->function == _SLAVE_) */
   return retval;
}

