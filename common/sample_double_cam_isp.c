// Copyright 2020 Fuzhou Rockchip Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "sample_double_cam_isp.h"

#define IQFILES_PATH "/etc/iqfiles"
#define AIQ_WIDTH 2688
#define AIQ_HEIGHT 1520

rk_aiq_sys_ctx_t *aiq_double_cam_init(int id, rk_aiq_working_mode_t mode, char *iq_dir) {
  rk_aiq_sys_ctx_t *ctx = NULL;
  rk_aiq_static_info_t info;
  rk_aiq_uapi_sysctl_enumStaticMetas(id, &info);

  printf("%d: sensor_name is %s\n", id, info.sensor_info.sensor_name);

  ctx = rk_aiq_uapi_sysctl_init(info.sensor_info.sensor_name, iq_dir ? iq_dir : IQFILES_PATH,
                                NULL, NULL);
  if (!ctx) {
    printf("%s: rk_aiq_uapi_sysctl_init fail!\n", __func__);
    return NULL;
  }
  rk_aiq_uapi_sysctl_setMulCamConc(ctx, true);
  if (rk_aiq_uapi_sysctl_prepare(ctx, AIQ_WIDTH, AIQ_HEIGHT, mode)) {
    printf("%s: rk_aiq_uapi_sysctl_prepare fail!\n", __func__);
    rk_aiq_uapi_sysctl_deinit(ctx);
    return NULL;
  }
  if (rk_aiq_uapi_sysctl_start(ctx) < 0) {
    printf("%s: rk_aiq_uapi_sysctl_start fail!\n", __func__);
    rk_aiq_uapi_sysctl_deinit(ctx);
    return NULL;
  }
  return ctx;
}

void aiq_double_cam_exit(rk_aiq_sys_ctx_t *ctx) {
  if (ctx) {
    rk_aiq_uapi_sysctl_stop(ctx, false);
    rk_aiq_uapi_sysctl_deinit(ctx);
  }
}
