// Copyright 2019 Fuzhou Rockchip Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef __RKMEDIA_VI_
#define __RKMEDIA_VI_
#ifdef __cplusplus
extern "C" {
#endif
#include "rkmedia_common.h"

typedef enum rkVI_CHN_WORK_MODE {
  VI_WORK_MODE_NORMAL = 0,
  // for vi single caculate luma.
  // In this mode, vi has no output,
  // and data cannot be obtained from vi.
  VI_WORK_MODE_LUMA_ONLY,
  // In this mode, data can still be obtained
  // through the RK_MPI_SYS_GetMediaBuffer interface
  // after the VI is bound.
  VI_WORK_MODE_GOD_MODE,
} VI_CHN_WORK_MODE;

typedef struct rkVI_CHN_ATTR_S {
  const RK_CHAR *pcVideoNode;
  RK_U32 u32Width;
  RK_U32 u32Height;
  IMAGE_TYPE_E enPixFmt;
  RK_U32 u32BufCnt; // VI capture video buffer cnt.
  VI_CHN_WORK_MODE enWorkMode;
} VI_CHN_ATTR_S;

typedef struct rkVIDEO_REGION_INFO_S {
  RK_U32 u32RegionNum; /* count of the region */
  RECT_S *pstRegion; /* region attribute */
} VIDEO_REGION_INFO_S;

#ifdef __cplusplus
}
#endif
#endif // #ifndef __RKMEDIA_VI_