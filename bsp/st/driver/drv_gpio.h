/*
 * Copyright (c) 2023, mr-library Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-10-8     MacRsh       first version
 */

#ifndef _DRV_GPIO_H_
#define _DRV_GPIO_H_

#include "device/pin.h"
#include "mrboard.h"

#if (MR_CFG_PIN == MR_CFG_ENABLE)

/**
 * @struct Driver gpio data
 */
struct drv_gpio_data
{
    const char *name;
};

#endif

#endif /* _DRV_GPIO_H_ */
