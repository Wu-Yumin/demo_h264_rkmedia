// Copyright 2020 Fuzhou Rockchip Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef __SAMPLE_DOUBLE_CAM_ISP_H__
#define __SAMPLE_DOUBLE_CAM_ISP_H__

#include <rk_aiq_user_api_imgproc.h>
#include <rk_aiq_user_api_sysctl.h>

#ifdef __cplusplus
extern "C" {
#endif

rk_aiq_sys_ctx_t *aiq_double_cam_init(int id, rk_aiq_working_mode_t mode, char *iq_dir);
void aiq_double_cam_exit(rk_aiq_sys_ctx_t *ctx);

#ifdef __cplusplus
}
#endif
#endif
