/*
 * Copyright (c) 2023, mr-library Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-04-23     MacRsh       first version
 */

#ifndef _MR_LIB_H_
#define _MR_LIB_H_

#include "mrdef.h"
#include "mrservice.h"

/**
 *  Export kernel functions
 */
mr_container_t mr_container_find(mr_uint8_t type);
mr_object_t mr_object_find(const char *name, mr_uint8_t type);
mr_err_t mr_object_add(mr_object_t object, const char *name, mr_uint8_t type);
mr_err_t mr_object_remove(mr_object_t object);
mr_err_t mr_object_change_type(mr_object_t object, mr_uint8_t type);
void mr_object_rename(mr_object_t object, char *name);
void mr_mutex_init(mr_mutex_t mutex);
mr_err_t mr_mutex_take(mr_mutex_t mutex, mr_object_t owner);
mr_err_t mr_mutex_release(mr_mutex_t mutex, mr_object_t owner);

#if (MR_CONF_DEVICE == MR_CONF_ENABLE)
/**
 *  Export device functions
 */
mr_device_t mr_device_find(const char *name);
mr_err_t mr_device_add(mr_device_t device, const char *name, mr_uint16_t flags);
mr_err_t mr_device_open(mr_device_t device, mr_uint16_t flags);
mr_err_t mr_device_close(mr_device_t device);
mr_err_t mr_device_ioctl(mr_device_t device, int cmd, void *args);
mr_ssize_t mr_device_read(mr_device_t device, mr_off_t pos, void *buffer, mr_size_t size);
mr_ssize_t mr_device_write(mr_device_t device, mr_off_t pos, const void *buffer, mr_size_t size);
#endif /* MR_CONF_DEVICE */

#if (MR_CONF_EVENT == MR_CONF_ENABLE)
/**
 *  Export event server functions
 */
mr_event_server_t mr_event_server_find(const char *name);
mr_err_t mr_event_server_add(mr_event_server_t server, const char *name, mr_size_t queue_length);
mr_err_t mr_event_server_remove(mr_event_server_t server);
mr_err_t mr_event_server_notify(mr_event_server_t server, mr_uint8_t id);
void mr_event_server_handle(mr_event_server_t server);
mr_event_client_t mr_event_client_find(mr_uint8_t id, mr_event_server_t server);
mr_err_t mr_event_client_create(mr_uint8_t id,
                                mr_err_t (*cb)(mr_event_server_t server, void *args),
                                void *args,
                                mr_event_server_t server);
mr_err_t mr_client_delete(mr_uint8_t id, mr_event_server_t server);
#endif /* MR_CONF_EVENT */

#if (MR_CONF_SOFT_TIMER == MR_CONF_ENABLE)
/**
 *  Export soft timer server functions
 */
mr_soft_timer_server_t mr_soft_timer_server_find(const char *name);
mr_err_t mr_soft_timer_server_add(mr_soft_timer_server_t server, const char *name);
mr_err_t mr_soft_timer_server_remove(mr_soft_timer_server_t server);
void mr_soft_timer_server_update(mr_soft_timer_server_t server, mr_uint32_t time);
void mr_soft_timer_server_handle(mr_soft_timer_server_t server);
mr_err_t mr_soft_timer_client_add(mr_soft_timer_client_t client,
                                  mr_uint32_t time,
                                  mr_err_t (*cb)(mr_soft_timer_client_t client, void *args),
                                  void *args,
                                  mr_soft_timer_server_t server);
mr_err_t mr_soft_timer_client_remove(mr_soft_timer_client_t client);
mr_err_t mr_soft_timer_client_start(mr_soft_timer_client_t client);
mr_err_t mr_soft_timer_client_stop(mr_soft_timer_client_t client);
mr_err_t mr_soft_timer_client_add_then_start(mr_soft_timer_client_t client,
                                             mr_uint32_t time,
                                             mr_err_t (*cb)(mr_soft_timer_client_t client, void *args),
                                             void *args,
                                             mr_soft_timer_server_t server);
#endif /* MR_CONF_SOFT_TIMER */

#if (MR_CONF_AT_COMMAND == MR_CONF_ENABLE)
mr_at_command_server_t mr_at_command_server_find(const char *name);
mr_err_t mr_at_command_server_add(mr_at_command_server_t server, const char *name, mr_size_t queue_length);
mr_err_t mr_at_command_remove(mr_at_command_server_t server);
void mr_at_command_server_handle(mr_at_command_server_t server);
void mr_at_command_server_isr(mr_at_command_server_t server, mr_uint8_t data);
mr_at_command_client_t mr_at_command_client_find(const char *at_command, mr_at_command_server_t server);
mr_err_t mr_at_command_client_create(const char *at_command,
                                     mr_err_t (*cb)(mr_at_command_client_t client, void *args),
                                     mr_at_command_server_t server);
mr_err_t mr_at_command_client_delete(const char *at_command, mr_at_command_server_t server);
#define mr_at_command_get_args      mr_sscanf
#endif /* MR_CONF_AT_COMMAND */

/**
 *  Export kernel service functions
 */
void mr_auto_init(void);
mr_size_t mr_printf(const char *fmt, ...);
void mr_log_output(mr_base_t level, const char *tag, const char *fmt, ...);
mr_weak void mr_assert_handle(void);
mr_weak void mr_interrupt_disable(void);
mr_weak void mr_interrupt_enable(void);
mr_weak void mr_delay_ms(mr_uint32_t ms);

/**
 *  Export fifo functions
 */
void mr_fifo_init(mr_fifo_t fifo, void *pool, mr_size_t pool_size);
void mr_fifo_reset(mr_fifo_t fifo);
mr_size_t mr_fifo_get_data_size(mr_fifo_t fifo);
mr_size_t mr_fifo_get_space_size(mr_fifo_t fifo);
mr_size_t mr_fifo_get_buffer_size(mr_fifo_t fifo);
mr_size_t mr_fifo_read(mr_fifo_t fifo, void *buffer, mr_size_t size);
mr_size_t mr_fifo_write(mr_fifo_t fifo, const void *buffer, mr_size_t size);
mr_size_t mr_fifo_write_force(mr_fifo_t fifo, const void *buffer, mr_size_t size);

/**
 *  Export avl functions
 */
void mr_avl_init(mr_avl_t node, mr_uint32_t value);
void mr_avl_insert(mr_avl_t *tree, mr_avl_t node);
void mr_avl_remove(mr_avl_t *tree, mr_avl_t node);
mr_avl_t mr_avl_find(mr_avl_t tree, mr_uint32_t value);
mr_size_t mr_avl_get_length(mr_avl_t tree);
mr_uint32_t mr_str2hash(const char *str, mr_size_t length);

#endif /* _MR_LIB_H_ */