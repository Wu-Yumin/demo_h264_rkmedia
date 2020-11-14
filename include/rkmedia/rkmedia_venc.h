// Copyright 2019 Fuzhou Rockchip Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef __RKMEDIA_VENC_
#define __RKMEDIA_VENC_
#ifdef __cplusplus
extern "C" {
#endif
// #include "media_type.h"
#include "rkmedia_common.h"

typedef RK_U32 RK_FR32;
/* rc quality */
typedef enum rkVENC_RC_QUALITY_E {
  VENC_RC_QUALITY_HIGHEST,
  VENC_RC_QUALITY_HIGHER,
  VENC_RC_QUALITY_HIGH,
  VENC_RC_QUALITY_MEDIUM,
  VENC_RC_QUALITY_LOW,
  VENC_RC_QUALITY_LOWER,
  VENC_RC_QUALITY_LOWEST,
  VENC_RC_QUALITY_BUTT,
} VENC_RC_QUALITY_E;
/* rc mode */
typedef enum rkVENC_RC_MODE_E {
  // H264
  VENC_RC_MODE_H264CBR = 1,
  VENC_RC_MODE_H264VBR,
  VENC_RC_MODE_H264AVBR,
  // MJPEG
  VENC_RC_MODE_MJPEGCBR,
  VENC_RC_MODE_MJPEGVBR,
  // H265
  VENC_RC_MODE_H265CBR,
  VENC_RC_MODE_H265VBR,
  VENC_RC_MODE_H265AVBR,
  VENC_RC_MODE_BUTT,
} VENC_RC_MODE_E;

typedef enum rkVENC_NALU_TYPE_E {
  VENC_NALU_BSLICE = 1,
  VENC_NALU_PSLICE,
  VENC_NALU_ISLICE,
  VENC_NALU_IDRSLICE,
  VENC_NALU_SEI,
  VENC_NALU_VPS,
  VENC_NALU_SPS,
  VENC_NALU_PPS,
  VENC_NALU_BUTT
} VENC_NALU_TYPE_E;

/* the attribute of h264e cbr*/
typedef struct rkVENC_H264_CBR_S {

  RK_U32 u32Gop; // RW; Range:[1, 65536]; the interval of I Frame.
  RK_U32 u32SrcFrameRateNum;
  RK_U32 u32SrcFrameRateDen;
  RK_FR32 fr32DstFrameRateNum;
  RK_FR32 fr32DstFrameRateDen;
  RK_U32 u32BitRate; // RW; Range:[2, 614400]; average bitrate
} VENC_H264_CBR_S;

/* the attribute of h264e vbr*/
typedef struct rkVENC_H264_VBR_S {
  RK_U32 u32Gop; // RW; Range:[1, 65536]; the interval of ISLICE.
  RK_U32 u32SrcFrameRateNum;
  RK_U32 u32SrcFrameRateDen;
  RK_FR32 fr32DstFrameRateNum;
  RK_FR32 fr32DstFrameRateDen;
  RK_U32 u32MaxBitRate; // RW; Range:[2, 614400];the max bitrate
} VENC_H264_VBR_S;

/* the attribute of h264e vbr*/
typedef struct rkVENC_H264_AVBR_S {
  RK_U32 u32Gop; // RW; Range:[1, 65536]; the interval of ISLICE.
  RK_U32 u32SrcFrameRateNum;
  RK_U32 u32SrcFrameRateDen;
  RK_FR32 fr32DstFrameRateNum;
  RK_FR32 fr32DstFrameRateDen;
  RK_U32 u32MaxBitRate; // RW; Range:[2, 614400];the max bitrate
} VENC_H264_AVBR_S;

/* the attribute of mjpege cbr*/
typedef struct rkVENC_MJPEG_CBR_S {
  RK_U32 u32SrcFrameRateNum;
  RK_U32 u32SrcFrameRateDen;
  RK_FR32 fr32DstFrameRateNum;
  RK_FR32 fr32DstFrameRateDen;
  RK_U32 u32BitRate; // RW; Range:[2000, 98000000]; average bitrate
} VENC_MJPEG_CBR_S;

/* the attribute of mjpege vbr*/
typedef struct rkVENC_MJPEG_VBR_S {
  RK_U32 u32SrcFrameRateNum;
  RK_U32 u32SrcFrameRateDen;
  RK_FR32 fr32DstFrameRateNum;
  RK_FR32 fr32DstFrameRateDen;
  RK_U32 u32BitRate; // RW; Range:[2000, 98000000]; average bitrate
} VENC_MJPEG_VBR_S;

typedef struct rkVENC_H264_CBR_S VENC_H265_CBR_S;
typedef struct rkVENC_H264_VBR_S VENC_H265_VBR_S;
typedef struct rkVENC_H264_AVBR_S VENC_H265_AVBR_S;

/* the attribute of rc*/
typedef struct rkVENC_RC_ATTR_S {
  /* RW; the type of rc*/
  VENC_RC_MODE_E enRcMode;
  union {
    VENC_H264_CBR_S stH264Cbr;
    VENC_H264_VBR_S stH264Vbr;
    VENC_H264_AVBR_S stH264Avbr;

    VENC_MJPEG_CBR_S stMjpegCbr;
    VENC_MJPEG_VBR_S stMjpegVbr;

    VENC_H265_CBR_S stH265Cbr;
    VENC_H265_VBR_S stH265Vbr;
    VENC_H265_AVBR_S stH265Avbr;
  };
} VENC_RC_ATTR_S;

/* the gop mode */
typedef enum rkVENC_GOP_MODE_E {
  VENC_GOPMODE_NORMALP = 0,
  VENC_GOPMODE_TSVC,
  VENC_GOPMODE_SMARTP,
  VENC_GOPMODE_BUTT,
} VENC_GOP_MODE_E;

typedef enum rkVENC_ROTATION_E {
  VENC_ROTATION_0 = 0,
  VENC_ROTATION_90 = 90,
  VENC_ROTATION_180 = 180,
  VENC_ROTATION_270 = 270,
  VENC_ROTATION_BUTT
} VENC_ROTATION_E;

/*the attribute of jpege*/
typedef struct rkVENC_ATTR_JPEG_S {
  RK_U32 u32ZoomWidth;  // Zoom to specified width
  RK_U32 u32ZoomHeight; // Zoom to specified height
  RK_U32 u32ZoomVirWidth;
  RK_U32 u32ZoomVirHeight;
} VENC_ATTR_JPEG_S;

/*the attribute of mjpege*/
typedef struct rkVENC_ATTR_MJPEG_S {
  RK_U32 u32ZoomWidth;  // Zoom to specified width
  RK_U32 u32ZoomHeight; // Zoom to specified height
  RK_U32 u32ZoomVirWidth;
  RK_U32 u32ZoomVirHeight;
} VENC_ATTR_MJPEG_S;

/*the attribute of h264e*/
typedef struct rkVENC_ATTR_H264_S {
  RK_U32 u32Level;
  // reserved
} VENC_ATTR_H264_S;

/*the attribute of h265e*/
typedef struct rkVENC_ATTR_H265_S {

  // reserved
} VENC_ATTR_H265_S;

/* the attribute of the Venc*/
typedef struct rkVENC_ATTR_S {

  CODEC_TYPE_E enType;    // RW; the type of encodec
  IMAGE_TYPE_E imageType; // the type of input image
  RK_U32 u32VirWidth;  // stride width, same to buffer_width, must greater than
                       // width, often set vir_width=(width+15)&(~15)
  RK_U32 u32VirHeight; // stride height, same to buffer_height, must greater
                       // than height, often set vir_height=(height+15)&(~15)
  RK_U32 u32Profile;   // RW;
                       // H.264:   66: baseline; 77:MP; 100:HP;
                       // H.265:   default:Main;
                       // Jpege/MJpege:   default:Baseline
  RK_BOOL bByFrame;    // RW; Range:[0,1];
                       // get stream mode is slice mode or frame mode
  RK_U32 u32PicWidth;  // RW; width of a picture to be encoded, in pixel
  RK_U32 u32PicHeight; // RW; height of a picture to be encoded, in pixel
  VENC_ROTATION_E enRotation;
  union {
    VENC_ATTR_H264_S stAttrH264e;   // attributes of H264e
    VENC_ATTR_H265_S stAttrH265e;   // attributes of H265e
    VENC_ATTR_MJPEG_S stAttrMjpege; // attributes of Mjpeg
    VENC_ATTR_JPEG_S stAttrJpege;   // attributes of jpeg
  };
} VENC_ATTR_S;

/* the attribute of the gop*/
typedef struct rkVENC_GOP_ATTR_S {
  VENC_GOP_MODE_E enGopMode;
  RK_U32 u32GopSize;
  RK_S32 s32IPQpDelta;
  RK_U32 u32BgInterval;
  RK_S32 s32ViQpDelta;
} VENC_GOP_ATTR_S;

/* the attribute of the venc chnl*/
typedef struct rkVENC_CHN_ATTR_S {
  VENC_ATTR_S stVencAttr;    // the attribute of video encoder
  VENC_RC_ATTR_S stRcAttr;   // the attribute of rate  ctrl
  VENC_GOP_ATTR_S stGopAttr; // the attribute of gop
} VENC_CHN_ATTR_S;

/* The param of H264e cbr*/
typedef struct rkVENC_PARAM_H264_S {
  RK_U32 u32StepQp;
  RK_U32 u32MaxQp; // RW; Range:[8, 51];the max QP value
  RK_U32 u32MinQp; // RW; Range:[0, 48]; the min QP value,can not be larger than
                   // u32MaxQp
  RK_U32 u32MaxIQp; // RW; max qp for i frame
  RK_U32 u32MinIQp; // RW; min qp for i frame,can not be larger
                    // than u32MaxIQp
  // RK_S32  s32MaxReEncodeTimes;        /* RW; Range:[0, 3]; Range:max number
  // of re-encode times.*/
} VENC_PARAM_H264_S;

/* The param of h265e cbr*/
typedef struct rkVENC_PARAM_H265_S {
  RK_U32 u32StepQp;
  RK_U32 u32MaxQp; // RW; Range:[8, 51];the max QP value
  RK_U32 u32MinQp; // RW; Range:[0, 48];the min QP value ,can not be larger than
                   // u32MaxQp
  RK_U32 u32MaxIQp; // RW; max qp for i frame
  RK_U32 u32MinIQp; // RW; min qp for i frame,can not be larger than u32MaxIQp

  // RK_S32  s32MaxReEncodeTimes;         /* RW; Range:[0, 3]; Range:max number
  // of re-encode times.*/
  // RK_U32  u32DeltIpQp;
} VENC_PARAM_H265_S;

/* The param of mjpege cbr*/
typedef struct rkVENC_PARAM_MJPEG_S {

} VENC_PARAM_MJPEG_S;

/* The param of rc*/
typedef struct rkVENC_RC_PARAM_S {
  RK_U32
  s32FirstFrameStartQp; // RW; Start QP value of the first frame
  union {
    VENC_PARAM_H264_S stParamH264;
    VENC_PARAM_H265_S stParamH265;
    VENC_PARAM_MJPEG_S stParamMjpeg;
  };
} VENC_RC_PARAM_S;

/* the attribute of the roi */
typedef struct rkVENC_ROI_ATTR_S {
  RK_U32 u32Index; // RW; Range:[0, 7]; Index of an ROI. The system supports
                   // indexes ranging from 0 to 7
  RK_BOOL bEnable; // RW; Range:[0, 1]; Whether to enable this ROI
  RK_BOOL bAbsQp;  // RW; Range:[0, 1]; QP mode of an ROI.RK_FALSE: relative
                   // QP.RK_TURE: absolute QP.
  RK_S32 s32Qp; // RW; Range:[-51, 51]; QP value,only relative mode can QP value
                // less than 0.
  RK_BOOL bIntra; // flag of forced intra macroblock
  RECT_S stRect;  // RW; Region of an ROI
} VENC_ROI_ATTR_S;

#define VENC_RGN_COLOR_NUM 256
typedef struct rkVENC_COLOR_TBL {
  // PixFormat: ARGB => A:bit31~bit24 R:bit23~bit16 G:bit15~bit8 B:bit7~bit0
  RK_U32 u32ArgbTbl[VENC_RGN_COLOR_NUM];
  // Enabling dichotomy will speed up the search for the color table,
  // but will sort the color table set by the user in ascending order.
  RK_BOOL bColorDichotomyEnable;
} VENC_COLOR_TBL_S;

typedef enum rkOSD_REGION_ID_E {
  REGION_ID_0 = 0,
  REGION_ID_1,
  REGION_ID_2,
  REGION_ID_3,
  REGION_ID_4,
  REGION_ID_5,
  REGION_ID_6,
  REGION_ID_7
} OSD_REGION_ID_E;

typedef enum rkOSD_PIXEL_FORMAT_E {
  PIXEL_FORMAT_ARGB_1555 = 0,
  PIXEL_FORMAT_ARGB_8888,
} OSD_PIXEL_FORMAT_E;

typedef struct rkBITMAP_S {
  OSD_PIXEL_FORMAT_E enPixelFormat; /* Bitmap's pixel format */
  RK_U32 u32Width;                  /* Bitmap's width */
  RK_U32 u32Height;                 /* Bitmap's height */
  RK_VOID *pData;                   /* Address of Bitmap's data */
} BITMAP_S;

typedef struct rkCOVER_INFO_S {
  OSD_PIXEL_FORMAT_E enPixelFormat; /* Bitmap's pixel format */
  RK_U32 u32Color;                  /* Covered area color */
} COVER_INFO_S;

typedef struct rkOSD_COLOR_PALETTE_BUF_S {
  RK_U32 u32Width;  /* buffer's width */
  RK_U32 u32Height; /* buffer's height */
  RK_VOID *pIdBuf;  /* buffer of the color palette id */
} OSD_COLOR_PALETTE_BUF_S;

typedef struct rkOSD_REGION_INFO_S {
  OSD_REGION_ID_E enRegionId;
  RK_U32 u32PosX;
  RK_U32 u32PosY;
  RK_U32 u32Width;
  RK_U32 u32Height;
  RK_U8 u8Inverse;
  RK_U8 u8Enable;
} OSD_REGION_INFO_S;

typedef struct rkVENC_RECV_PIC_PARAM_S {
  RK_S32 s32RecvPicNum;
} VENC_RECV_PIC_PARAM_S;

typedef struct rkVENC_JPEG_PARAM_S {
  RK_U32 u32Qfactor; // 1-10
  RK_U8 u8YQt[64];
  RK_U8 u8CbQt[64];
  RK_U8 u8CrQt[64];
  RK_U32 u32MCUPerECS;
} VENC_JPEG_PARAM_S;

#ifdef __cplusplus
}
#endif

#endif // #ifndef __RKMEDIA_VENC_
