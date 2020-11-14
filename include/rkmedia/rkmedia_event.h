// Copyright 2019 Fuzhou Rockchip Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
#ifndef __RK_EVENT_
#define __RK_EVENT_
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "rkmedia_common.h"

typedef enum rkEVENT_TYPE_E {
  RK_EVENT_ERR = 0,
  RK_EVENT_MD, // Algo::Move detection event.
  RK_EVENT_OD, // Algo::Occlusion detection event.
  RK_EVNET_BUT
} EVENT_TYPE_E;

typedef struct rkMD_EVENT_S {
  RK_U16 u16Cnt;
  RK_U32 u32Width;
  RK_U32 u32Height;
  RECT_S stRects[4096];
} MD_EVENT_S;

typedef struct rkOD_EVENT_S {
  RK_U16 u16Cnt;
  RK_U32 u32Width;
  RK_U32 u32Height;
  RECT_S stRects[10];
  RK_U16 u16Occlusion[10];
} OD_EVENT_S;

typedef struct rkEVENT_S {
  EVENT_TYPE_E type;
  MOD_ID_E mode_id;
  union {
    MD_EVENT_S md_event;
    OD_EVENT_S stOdEvent;
  };
} EVENT_S;

typedef void (*EventCbFunc)(EVENT_S *event);

#ifdef __cplusplus
}
#endif
#endif // #ifndef __RK_EVENT_
