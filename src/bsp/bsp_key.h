/*
 * bsp_key.h
 *
 *  Created on: 2026年1月18日
 *      Author: mx
 */

#ifndef __BSP_BSP_KEY_H__
#define __BSP_BSP_KEY_H__

#include "common_data.h"

// 用户按键P008,核心板上的SW202
#define BSP_USER_KEY1_PIN BSP_IO_PORT_00_PIN_08

// 用户按键P006,扩展板上的S1
#define BSP_USER_KEY2_PIN BSP_IO_PORT_00_PIN_06

// 用户按键P005,扩展板上的NMI
#define BSP_USER_KEY3_PIN BSP_IO_PORT_02_PIN_00

/**
 * @brief 按键初始化
 *
 */
void BspKeyInit(void);

/**
 * @brief 获取按键状态
 *
 * @param key_pin 按键引脚
 * @return bsp_io_level_t 按键状态，低电平表示按下，高电平表示未按下
 */
bsp_io_level_t BspKeyGetState(bsp_io_port_pin_t key_pin);
#endif /* __BSP_BSP_KEY_H__ */
