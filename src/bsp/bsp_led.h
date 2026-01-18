/**
 * @file bsp_led.h
 * @author maxiao (maxiaogood@qq.com)
 * @brief led驱动头文件
 * @version 0.1
 * @date 2026-01-18
 * 
 * @copyright Copyright (c) 2026, maxiao. All rights reserved.
 * 
 */
#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include "hal_data.h"

// 用户指示灯PA01,核心板上的LED1
#define BSP_USER_LED1_PIN    BSP_IO_PORT_10_PIN_01
#define BSP_USER_LED1_ON()   R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_USER_LED1_PIN, BSP_IO_LEVEL_LOW)
#define BSP_USER_LED1_OFF()  R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_USER_LED1_PIN, BSP_IO_LEVEL_HIGH)
#define BSP_USER_LED1_TOGGLE() R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_USER_LED1_PIN, (bsp_io_level_t)(1 - R_BSP_PinRead(BSP_USER_LED1_PIN)))

// 用户指示灯P107,扩展板上的LED1_RED
#define BSP_USER_LED2_PIN    BSP_IO_PORT_01_PIN_07
#define BSP_USER_LED2_ON()   R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_USER_LED2_PIN, BSP_IO_LEVEL_LOW)
#define BSP_USER_LED2_OFF()  R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_USER_LED2_PIN, BSP_IO_LEVEL_HIGH)
#define BSP_USER_LED2_TOGGLE() R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_USER_LED2_PIN, (bsp_io_level_t)(1 - R_BSP_PinRead(BSP_USER_LED2_PIN)))

// 用户指示灯P600,扩展板上的LED1_BLUE
#define BSP_USER_LED3_PIN    BSP_IO_PORT_06_PIN_00
#define BSP_USER_LED3_ON()   R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_USER_LED3_PIN, BSP_IO_LEVEL_LOW)
#define BSP_USER_LED3_OFF()  R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_USER_LED3_PIN, BSP_IO_LEVEL_HIGH)
#define BSP_USER_LED3_TOGGLE() R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_USER_LED3_PIN, (bsp_io_level_t)(1 - R_BSP_PinRead(BSP_USER_LED3_PIN)))
#endif /* __BSP_LED_H__ */
