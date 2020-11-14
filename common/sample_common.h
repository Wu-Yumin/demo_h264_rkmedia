#include <assert.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "rkmedia_common.h"

#ifdef RKAIQ
#include <rk_aiq_user_api_imgproc.h>
#include <rk_aiq_user_api_sysctl.h>
/*
 * stream on:
 * 1) ISP Init
 * 2) ISP Stop
 * 3) VI enable and stream on
 *
 * stream off:
 * 4) ISP Stop
 * 5) VI disable
 */
/*
typedef enum {
 RK_AIQ_WORKING_MODE_NORMAL,
 RK_AIQ_WORKING_MODE_ISP_HDR2    = 0x10,
 RK_AIQ_WORKING_MODE_ISP_HDR3    = 0x20,
 //RK_AIQ_WORKING_MODE_SENSOR_HDR = 10, // sensor built-in hdr mode
} rk_aiq_working_mode_t;
*/
RK_S32 SAMPLE_COMM_ISP_Init(rk_aiq_working_mode_t WDRMode, RK_BOOL bFECEnable,
                            const char *iq_file_dir);
RK_VOID SAMPLE_COMM_ISP_Stop(RK_VOID);
RK_S32 SAMPLE_COMM_ISP_Run(RK_VOID); // isp stop before vi streamoff

RK_VOID SAMPLE_COMM_ISP_DumpExpInfo(rk_aiq_working_mode_t WDRMode);
RK_VOID SAMPLE_COMM_ISP_SetFrameRate(RK_U32 uFps);
RK_VOID SAMPLE_COMM_ISP_SetLDCHLevel(RK_U32 level);
RK_VOID SAMPLE_COMM_ISP_SetWDRModeDyn(rk_aiq_working_mode_t WDRMode);
RK_VOID SAMPLE_COMM_ISP_SET_Brightness(RK_U32 value);
RK_VOID SAMPLE_COMM_ISP_SET_Contrast(RK_U32 value);
RK_VOID SAMPLE_COMM_ISP_SET_Saturation(RK_U32 value);
RK_VOID SAMPLE_COMM_ISP_SET_Sharpness(RK_U32 value);
RK_VOID SAMPLE_COMM_ISP_SET_ManualExposureAutoGain(RK_U32 u32Shutter);
RK_VOID SAMPLE_COMM_ISP_SET_ManualExposureManualGain(RK_U32 u32Shutter,
                                                     RK_U32 u32Gain);
RK_VOID SAMPLE_COMM_ISP_SET_AutoExposure();
RK_VOID SAMPLE_COMM_ISP_SET_Exposure(RK_BOOL bIsAutoExposure, RK_U32 bIsAGC,
                                     RK_U32 u32ElectronicShutter,
                                     RK_U32 u32Agc);
RK_VOID SAMPLE_COMM_ISP_SET_BackLight(RK_BOOL bEnable, RK_U32 u32Strength);
RK_VOID SAMPLE_COMM_ISP_SET_LightInhibition(RK_BOOL bEnable, RK_U8 u8Strength,
                                            RK_U8 u8Level);
RK_VOID SAMPLE_COMM_ISP_SET_CPSL_CFG(rk_aiq_cpsl_cfg_t *cpsl);
RK_VOID SAMPLE_COMM_ISP_SET_OpenColorCloseLed();
RK_VOID SAMPLE_COMM_ISP_SET_GrayOpenLed(RK_U8 u8Strength);
RK_VOID SAMPLE_COMMON_ISP_SET_AutoWhiteBalance();
RK_VOID SAMPLE_COMMON_ISP_SET_ManualWhiteBalance(RK_U32 u32RGain,
                                                 RK_U32 u32GGain,
                                                 RK_U32 u32BGain);
RK_VOID SAMPLE_COMMON_ISP_GET_WhiteBalanceGain(rk_aiq_wb_gain_t *gain);
RK_VOID SAMPLE_COMMON_ISP_SET_DNRStrength(RK_U32 u32Mode, RK_U32 u322DValue,
                                          RK_U32 u323Dvalue);
RK_VOID SAMPLE_COMMON_ISP_GET_DNRStrength(RK_U32 *u322DValue,
                                          RK_U32 *u323Dvalue);

RK_VOID SAMPLE_COMMON_ISP_SET_Flicker(RK_U8 u32Flicker);
RK_VOID SAMPLE_COMM_ISP_SET_HDR(rk_aiq_working_mode_t mode);
RK_VOID SAMPLE_COMM_ISP_SET_DefogEnable(RK_U32 u32Mode);
RK_VOID SAMPLE_COMM_ISP_SET_DefogStrength(RK_U32 u32Mode, RK_U32 u32Value);
RK_VOID SAMPLE_COMM_ISP_SET_Correction(RK_U32 u32Mode, RK_U32 u32Value);
RK_VOID SAMPLE_COMM_ISP_SET_mirror(RK_U32 u32Value);
RK_VOID SAMPLE_COMM_ISP_SET_BypassStreamRotation(RK_S32 S32Rotation);
#endif
