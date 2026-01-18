/*
 * bsp_key.h
 *
 *  Created on: 2026年1月18日
 *      Author: mx
 */

#ifndef BSP_BSP_KEY_H_
#define BSP_BSP_KEY_H_

#include "common_data.h"

// 用户按键P008,核心板上的SW202
#define BSP_USER_KEY1_PIN BSP_IO_PORT_00_PIN_08

// 用户按键P006,扩展板上的S1
#define BSP_USER_KEY2_PIN BSP_IO_PORT_00_PIN_06

// 用户按键P005,扩展板上的NMI
#define BSP_USER_KEY3_PIN BSP_IO_PORT_02_PIN_00

void BspKeyInit(void);
bsp_io_level_t BspKeyGetState(bsp_io_port_pin_t key_pin);
#endif /* BSP_BSP_KEY_H_ */
