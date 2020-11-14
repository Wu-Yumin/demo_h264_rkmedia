#ifndef __RKMEDIA_API_
#define __RKMEDIA_API_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#include "rkmedia_adec.h"
#include "rkmedia_aenc.h"
#include "rkmedia_ai.h"
#include "rkmedia_ao.h"
#include "rkmedia_buffer.h"
#include "rkmedia_common.h"
#include "rkmedia_event.h"
#include "rkmedia_move_detection.h"
#include "rkmedia_occlusion_detection.h"
#include "rkmedia_rga.h"
#include "rkmedia_venc.h"
#include "rkmedia_vi.h"
#include "rkmedia_vo.h"

// Platform resource number configuration
#define VI_MAX_CHN_NUM 8
#define VENC_MAX_CHN_NUM 16
#define AI_MAX_CHN_NUM 1
#define AO_MAX_CHN_NUM 1
#define AENC_MAX_CHN_NUM 16
#define ADEC_MAX_CHN_NUM 16
#define ALGO_MD_MAX_CHN_NUM VI_MAX_CHN_NUM
#define ALGO_OD_MAX_CHN_NUM VI_MAX_CHN_NUM
#define RGA_MAX_CHN_NUM 16
#define VO_MAX_CHN_NUM 2

typedef RK_S32 VI_PIPE;
typedef RK_S32 VI_CHN;
typedef RK_S32 VENC_CHN;
typedef RK_S32 AI_CHN;
typedef RK_S32 AO_CHN;
typedef RK_S32 AENC_CHN;
typedef RK_S32 ADEC_CHN;
typedef RK_S32 ALGO_MD_CHN;
typedef RK_S32 ALGO_OD_CHN;
typedef RK_S32 RGA_CHN;
typedef RK_S32 VO_CHN;

typedef struct rkMPP_CHN_S {
  MOD_ID_E enModId;
  RK_S32 s32DevId;
  RK_S32 s32ChnId;
} MPP_CHN_S;

/********************************************************************
 * SYS Ctrl api
 ********************************************************************/
_CAPI RK_S32 RK_MPI_SYS_Init();
_CAPI RK_VOID RK_MPI_SYS_DumpChn(MOD_ID_E enModId);
_CAPI RK_S32 RK_MPI_SYS_Bind(const MPP_CHN_S *pstSrcChn,
                             const MPP_CHN_S *pstDestChn);
_CAPI RK_S32 RK_MPI_SYS_UnBind(const MPP_CHN_S *pstSrcChn,
                               const MPP_CHN_S *pstDestChn);

_CAPI RK_S32 RK_MPI_SYS_RegisterOutCb(const MPP_CHN_S *pstChn, OutCbFunc cb);
_CAPI RK_S32 RK_MPI_SYS_RegisterEventCb(const MPP_CHN_S *pstChn,
                                        EventCbFunc cb);

_CAPI RK_S32 RK_MPI_SYS_SendMediaBuffer(MOD_ID_E enModID, RK_S32 s32ChnID,
                                        MEDIA_BUFFER buffer);
_CAPI MEDIA_BUFFER RK_MPI_SYS_GetMediaBuffer(MOD_ID_E enModID, RK_S32 s32ChnID,
                                             RK_S32 s32MilliSec);

/********************************************************************
 * Vi api
 ********************************************************************/
_CAPI RK_S32 RK_MPI_VI_SetChnAttr(VI_PIPE ViPipe, VI_CHN ViChn,
                                  const VI_CHN_ATTR_S *pstChnAttr);
_CAPI RK_S32 RK_MPI_VI_DisableChn(VI_PIPE ViPipe, VI_CHN ViChn);
_CAPI RK_S32 RK_MPI_VI_EnableChn(VI_PIPE ViPipe, VI_CHN ViChn);
_CAPI RK_S32 RK_MPI_VI_GetChnRegionLuma(
    VI_PIPE ViPipe, VI_CHN ViChn, const VIDEO_REGION_INFO_S *pstRegionInfo,
    RK_U64 *pu64LumaData, RK_S32 s32MilliSec);
_CAPI RK_S32 RK_MPI_VI_StartStream(VI_PIPE ViPipe, VI_CHN ViChn);

/********************************************************************
 * Venc api
 ********************************************************************/
_CAPI RK_S32 RK_MPI_VENC_CreateChn(VENC_CHN VeChn,
                                   VENC_CHN_ATTR_S *stVencChnAttr);
_CAPI RK_S32 RK_MPI_VENC_CreateJpegLightChn(VENC_CHN VeChn,
                                            VENC_CHN_ATTR_S *stVencChnAttr);
_CAPI RK_S32 RK_MPI_VENC_SetRcParam(VENC_CHN VeChn,
                                    const VENC_RC_PARAM_S *pstRcParam);
_CAPI RK_S32 RK_MPI_VENC_SetJpegParam(VENC_CHN VeChn,
                                      const VENC_JPEG_PARAM_S *pstJpegParam);

_CAPI RK_S32 RK_MPI_VENC_SetRcMode(VENC_CHN VeChn, VENC_RC_MODE_E RcMode);
_CAPI RK_S32 RK_MPI_VENC_SetRcQuality(VENC_CHN VeChn,
                                      VENC_RC_QUALITY_E RcQuality);
_CAPI RK_S32 RK_MPI_VENC_SetBitrate(VENC_CHN VeChn, RK_U32 u32BitRate,
                                    RK_U32 u32MinBitRate, RK_U32 u32MaxBitRate);
_CAPI RK_S32 RK_MPI_VENC_RequestIDR(VENC_CHN VeChn, RK_BOOL bInstant);
_CAPI RK_S32 RK_MPI_VENC_SetFps(VENC_CHN VeChn, RK_U8 u8OutNum, RK_U8 u8OutDen,
                                RK_U8 u8InNum, RK_U8 u8InDen);
_CAPI RK_S32 RK_MPI_VENC_SetGop(VENC_CHN VeChn, RK_U32 u32Gop);
_CAPI RK_S32 RK_MPI_VENC_SetAvcProfile(VENC_CHN VeChn, RK_U32 u32Profile,
                                       RK_U32 u32Level);
_CAPI RK_S32 RK_MPI_VENC_InsertUserData(VENC_CHN VeChn, RK_U8 *pu8Data,
                                        RK_U32 u32Len);
_CAPI RK_S32 RK_MPI_VENC_SetRoiAttr(VENC_CHN VeChn,
                                    const VENC_ROI_ATTR_S *pstRoiAttr,
                                    RK_S32 region_cnt);

_CAPI RK_S32 RK_MPI_VENC_SetGopMode(VENC_CHN VeChn,
                                    VENC_GOP_ATTR_S *pstGopModeAttr);

_CAPI RK_S32 RK_MPI_VENC_RGN_Init(VENC_CHN VeChn, VENC_COLOR_TBL_S *stColorTbl);

_CAPI RK_S32 RK_MPI_VENC_RGN_SetBitMap(VENC_CHN VeChn,
                                       const OSD_REGION_INFO_S *pstRgnInfo,
                                       const BITMAP_S *pstBitmap);
_CAPI RK_S32 RK_MPI_VENC_RGN_SetCover(VENC_CHN VeChn,
                                      const OSD_REGION_INFO_S *pstRgnInfo,
                                      const COVER_INFO_S *pstCoverInfo);
_CAPI RK_S32 RK_MPI_VENC_RGN_SetPaletteId(
    VENC_CHN VeChn, const OSD_REGION_INFO_S *pstRgnInfo,
    const OSD_COLOR_PALETTE_BUF_S *pstColPalBuf);
_CAPI RK_S32 RK_MPI_VENC_StartRecvFrame(
    VENC_CHN VeChn, const VENC_RECV_PIC_PARAM_S *pstRecvParam);
_CAPI RK_S32 RK_MPI_VENC_DestroyChn(VENC_CHN VeChn);

/********************************************************************
 * Ai api
 ********************************************************************/
_CAPI RK_S32 RK_MPI_AI_SetChnAttr(VENC_CHN AiChn, const AI_CHN_ATTR_S *pstAttr);
_CAPI RK_S32 RK_MPI_AI_EnableChn(AI_CHN AiChn);
_CAPI RK_S32 RK_MPI_AI_DisableChn(AI_CHN AiChn);
_CAPI RK_S32 RK_MPI_AI_SetVolume(AI_CHN AiChn, RK_S32 s32Volume);
_CAPI RK_S32 RK_MPI_AI_GetVolume(AI_CHN AiChn, RK_S32 *ps32Volume);
_CAPI RK_S32 RK_MPI_AI_SetTalkVqeAttr(AI_CHN AiChn,
                                      AI_TALKVQE_CONFIG_S *pstVqeConfig);
_CAPI RK_S32 RK_MPI_AI_GetTalkVqeAttr(AI_CHN AiChn,
                                      AI_TALKVQE_CONFIG_S *pstVqeConfig);
_CAPI RK_S32 RK_MPI_AI_SetRecordVqeAttr(AI_CHN AiChn,
                                        AI_RECORDVQE_CONFIG_S *pstVqeConfig);
_CAPI RK_S32 RK_MPI_AI_GetRecordVqeAttr(AI_CHN AiChn,
                                        AI_RECORDVQE_CONFIG_S *pstVqeConfig);
_CAPI RK_S32 RK_MPI_AI_EnableVqe(AI_CHN AiChn);
_CAPI RK_S32 RK_MPI_AI_StartStream(AI_CHN AiChn);
_CAPI RK_S32 RK_MPI_AI_DisableVqe(AI_CHN AiChn);

/********************************************************************
 * Ao api
 ********************************************************************/
_CAPI RK_S32 RK_MPI_AO_SetChnAttr(AO_CHN AoChn, const AO_CHN_ATTR_S *pstAttr);
_CAPI RK_S32 RK_MPI_AO_EnableChn(AO_CHN AoChn);
_CAPI RK_S32 RK_MPI_AO_DisableChn(AO_CHN AoChn);
_CAPI RK_S32 RK_MPI_AO_SetVolume(AO_CHN AoChn, RK_S32 s32Volume);
_CAPI RK_S32 RK_MPI_AO_GetVolume(AO_CHN AoChn, RK_S32 *ps32Volume);
_CAPI RK_S32 RK_MPI_AO_SetVqeAttr(AO_CHN AoChn, AO_VQE_CONFIG_S *pstVqeConfig);
_CAPI RK_S32 RK_MPI_AO_GetVqeAttr(AO_CHN AoChn, AO_VQE_CONFIG_S *pstVqeConfig);
_CAPI RK_S32 RK_MPI_AO_EnableVqe(AO_CHN AoChn);
_CAPI RK_S32 RK_MPI_AO_DisableVqe(AO_CHN AoChn);

/********************************************************************
 * Aenc api
 ********************************************************************/
_CAPI RK_S32 RK_MPI_AENC_CreateChn(AENC_CHN AencChn,
                                   const AENC_CHN_ATTR_S *pstAttr);
_CAPI RK_S32 RK_MPI_AENC_DestroyChn(AENC_CHN AencChn);

/********************************************************************
 * Algorithm::Move Detection api
 ********************************************************************/
_CAPI RK_S32 RK_MPI_ALGO_MD_CreateChn(ALGO_MD_CHN MdChn,
                                      const ALGO_MD_ATTR_S *pstChnAttr);
_CAPI RK_S32 RK_MPI_ALGO_MD_DestroyChn(ALGO_MD_CHN MdChn);
_CAPI RK_S32 RK_MPI_ALGO_MD_EnableSwitch(ALGO_MD_CHN MdChn, RK_BOOL bEnable);
/********************************************************************
 * Algorithm::Occlusion Detection api
 ********************************************************************/
_CAPI RK_S32 RK_MPI_ALGO_OD_CreateChn(ALGO_OD_CHN OdChn,
                                      const ALGO_OD_ATTR_S *pstChnAttr);
_CAPI RK_S32 RK_MPI_ALGO_OD_DestroyChn(ALGO_OD_CHN OdChn);
_CAPI RK_S32 RK_MPI_ALGO_OD_EnableSwitch(ALGO_OD_CHN OdChn, RK_BOOL bEnable);
/********************************************************************
 * Rga api
 ********************************************************************/
_CAPI RK_S32 RK_MPI_RGA_CreateChn(RGA_CHN RgaChn, RGA_ATTR_S *pstRgaAttr);
_CAPI RK_S32 RK_MPI_RGA_DestroyChn(RGA_CHN RgaChn);

/********************************************************************
 * Adec api
 ********************************************************************/
_CAPI RK_S32 RK_MPI_ADEC_CreateChn(ADEC_CHN AdecChn,
                                   const ADEC_CHN_ATTR_S *pstAttr);
_CAPI RK_S32 RK_MPI_ADEC_DestroyChn(ADEC_CHN AdecChn);

/********************************************************************
 * VO api
 ********************************************************************/
_CAPI RK_S32 RK_MPI_VO_CreateChn(VO_CHN VoChn, const VO_CHN_ATTR_S *pstAttr);
_CAPI RK_S32 RK_MPI_VO_DestroyChn(VO_CHN VoChn);

#ifdef __cplusplus
}
#endif

#endif //__RKMEDIA_API_
