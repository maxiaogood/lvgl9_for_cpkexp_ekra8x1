/**
 * @file bsp_key.h
 * @author maxiao (maxiaogood@qq.com)
 * @brief 按键驱动头文件
 * @version 0.1
 * @date 2026-01-18
 * 
 * @copyright Copyright (c) 2026, maxiao. All rights reserved.
 * 
 */
#ifndef __BSP_BSP_KEY_H__
#define __BSP_BSP_KEY_H__

#include "hal_data.h"

// 用户按键P008,核心板上的SW202
#define BSP_USER_KEY1_PIN BSP_IO_PORT_00_PIN_08

// 用户按键P006,扩展板上的S1
#define BSP_USER_KEY2_PIN BSP_IO_PORT_00_PIN_06

// 用户按键P200,扩展板上的NMI
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
