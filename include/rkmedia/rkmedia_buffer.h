// Copyright 2019 Fuzhou Rockchip Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
#ifndef __RK_BUFFER_
#define __RK_BUFFER_
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "rkmedia_common.h"

typedef void *MEDIA_BUFFER;
typedef void (*OutCbFunc)(MEDIA_BUFFER mb);

#define MB_TYPE_IMAGE_MASK 0x0100
#define MB_TYPE_VIDEO_MASK 0x0200
#define MB_TYPE_AUDIO_MASK 0x0400

typedef enum rkMB_TYPE {
  // Original image, such as NV12, RGB
  MB_TYPE_IMAGE = MB_TYPE_IMAGE_MASK | 0x0000,
  // Encoded video data. Treat JPEG as a video data.
  MB_TYPE_VIDEO = MB_TYPE_VIDEO_MASK | 0x0000,
  MB_TYPE_H264 = MB_TYPE_VIDEO_MASK | 0x0001,
  MB_TYPE_H265 = MB_TYPE_VIDEO_MASK | 0x0002,
  MB_TYPE_JPEG = MB_TYPE_VIDEO_MASK | 0x0003,
  MB_TYPE_MJPEG = MB_TYPE_VIDEO_MASK | 0x0004,
  // Audio data
  MB_TYPE_AUDIO = MB_TYPE_AUDIO_MASK | 0x0000,
} MB_TYPE_E;

typedef struct rkMB_IMAGE_INFO {
  RK_U32 u32Width;
  RK_U32 u32Height;
  RK_U32 u32VerStride;
  RK_U32 u32HorStride;
  IMAGE_TYPE_E enImgType;
} MB_IMAGE_INFO_S;

_CAPI void *RK_MPI_MB_GetPtr(MEDIA_BUFFER mb);
_CAPI int RK_MPI_MB_GetFD(MEDIA_BUFFER mb);
_CAPI size_t RK_MPI_MB_GetSize(MEDIA_BUFFER mb);
_CAPI MOD_ID_E RK_MPI_MB_GetModeID(MEDIA_BUFFER mb);
_CAPI RK_S16 RK_MPI_MB_GetChannelID(MEDIA_BUFFER mb);
_CAPI RK_U64 RK_MPI_MB_GetTimestamp(MEDIA_BUFFER mb);
_CAPI RK_S32 RK_MPI_MB_ReleaseBuffer(MEDIA_BUFFER mb);
_CAPI MEDIA_BUFFER RK_MPI_MB_CreateImageBuffer(MB_IMAGE_INFO_S *pstImageInfo,
                                               RK_BOOL boolHardWare);
_CAPI MEDIA_BUFFER RK_MPI_MB_CreateAudioBuffer(RK_U32 u32BufferSize,
                                               RK_BOOL boolHardWare);
_CAPI RK_S32 RK_MPI_MB_SetSzie(MEDIA_BUFFER mb, RK_U32 size);
_CAPI RK_S32 RK_MPI_MB_SetTimestamp(MEDIA_BUFFER mb, RK_U64 timestamp);
_CAPI RK_S32 RK_MPI_MB_GetFlag(MEDIA_BUFFER mb);
_CAPI RK_S32 RK_MPI_MB_GetTsvcLevel(MEDIA_BUFFER mb);
_CAPI RK_BOOL RK_MPI_MB_IsViFrame(MEDIA_BUFFER mb);

#ifdef __cplusplus
}
#endif
#endif // #ifndef __RK_BUFFER_
