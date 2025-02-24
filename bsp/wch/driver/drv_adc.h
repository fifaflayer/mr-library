/*
 * Copyright (c) 2023, mr-library Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-05-22     MacRsh       first version
 */

#ifndef _DRV_ADC_H_
#define _DRV_ADC_H_

#include "device/adc.h"
#include "mrboard.h"

#if (MR_CFG_ADC == MR_CFG_ENABLE)

/**
 * @struct Driver adc data
 */
struct drv_adc_data
{
    const char *name;

    ADC_TypeDef *instance;
    mr_uint32_t periph_clock;
};

#endif

#endif /* _DRV_ADC_H_ */
