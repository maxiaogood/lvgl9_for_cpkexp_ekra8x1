#include "bsp_key.h"



void BspKeyInit(void)
{
    // 此处可添加按键初始化代码（如果需要）
}

bsp_io_level_t BspKeyGetState(bsp_io_port_pin_t key_pin)
{
    bsp_io_level_t level;
    R_IOPORT_PinRead(&g_ioport_ctrl, key_pin, &level);
    return level;
}
