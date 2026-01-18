/**
 * @file bsp_key.c
 * @author maxiao (maxiaogood@qq.com)
 * @brief 按键驱动实现文件
 * @version 0.1
 * @date 2026-01-18
 *
 * @copyright Copyright (c) 2026, maxiao. All rights reserved.
 *
 */
#include "bsp_key.h"

/**
 * @brief 按键初始化
 *
 */
void BspKeyInit(void)
{
    // 此处可添加按键初始化代码（如果需要）
}

/**
 * @brief 获取按键状态
 *
 * @param key_pin 按键引脚
 * @return bsp_io_level_t 按键状态，低电平表示按下，高电平表示未按下
 */
bsp_io_level_t BspKeyGetState(bsp_io_port_pin_t key_pin)
{
    bsp_io_level_t level;
    R_IOPORT_PinRead(&g_ioport_ctrl, key_pin, &level);
    return level;
}
