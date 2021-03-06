/*
This software is subject to the license described in the license.txt file included with
this software distribution.
You may not use this file except in compliance with this license.

Copyright © Dynastream Innovations Inc. 2015
All rights reserved.
*/


#ifndef ANT_ADVANCED_BURST_H__
#define ANT_ADVANCED_BURST_H__

#include <stdint.h>
#include "ant_stack_handler_types.h"
#include "bsp.h"

/**@brief Function for configuring channel for advanced burst
 *
 */
void ant_advanced_burst_setup(void);


/**@brief Handles BSP events.
 *
 * @param[in] evt   BSP event.
 */
void ant_advanced_burst_bsp_evt_handler(bsp_event_t evt);


/**@brief Handle ANT events
 *
 * @param[in] p_ant_evt A pointer to the received ANT event to handle.
 */
void ant_advanced_burst_event_handler(ant_evt_t * p_ant_evt);

#endif // ANT_ADVANCED_BURST_H__


