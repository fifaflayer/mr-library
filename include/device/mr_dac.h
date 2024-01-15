/*
 * @copyright (c) 2023-2024, MR Development Team
 *
 * @license SPDX-License-Identifier: Apache-2.0
 *
 * @date 2023-11-08    MacRsh       First version
 */

#ifndef _MR_DAC_H_
#define _MR_DAC_H_

#include "include/mr_api.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef MR_USING_DAC

/**
 * @brief DAC configuration structure.
 */
struct mr_dac_config
{
    int state;                                                      /**< Channel state */
};

/**
 * @brief DAC control command.
 */
#define MR_CTL_DAC_SET_CHANNEL          MR_CTL_SET_OFFSET           /**< Set channel */
#define MR_CTL_DAC_SET_CHANNEL_CONFIG   MR_CTL_SET_CONFIG           /**< Set channel config */

#define MR_CTL_DAC_GET_CHANNEL          MR_CTL_GET_OFFSET           /**< Get channel */
#define MR_CTL_DAC_GET_CHANNEL_CONFIG   MR_CTL_GET_CONFIG           /**< Get channel config */

/**
 * @brief DAC data type.
 */
typedef uint32_t mr_dac_data_t;                                     /**< DAC write data type */

/**
 * @brief DAC structure.
 */
struct mr_dac
{
    struct mr_dev dev;                                              /**< Device */

    uint32_t channel;                                               /**< Channel */
};

/**
 * @brief DAC operations structure.
 */
struct mr_dac_ops
{
    int (*configure)(struct mr_dac *dac, int state);
    int (*channel_configure)(struct mr_dac *dac, int channel, int state);
    void (*write)(struct mr_dac *dac, int channel, uint32_t data);
};

/**
 * @addtogroup DAC.
 * @{
 */
int mr_dac_register(struct mr_dac *dac, const char *name, struct mr_drv *drv);
/** @} */

#endif /* MR_USING_DAC */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MR_DAC_H_ */
