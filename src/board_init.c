#include "board_init.h"

#include "lvgl.h"
#include "common_data.h"



#if LV_USE_DRAW_DAVE2D
#define DIRECT_MODE 1
#else
#define DIRECT_MODE 0
#endif



void board_init(void)
{
    /* Need to initialise the Touch Controller before the LCD, as only a Single Reset line shared between them */
    //touch_init();
    BspKeyInit();
    BspUart3Init();
#if DIRECT_MODE
    fsp_err_t err;
    err = RM_LVGL_PORT_Open(&g_lvgl_port_ctrl, &g_lvgl_port_cfg);
    if (FSP_SUCCESS != err)
    {
        __BKPT(0);
    }
#else
    static uint8_t partial_draw_buf[64*1024] BSP_PLACE_IN_SECTION(".dtcm_bss") BSP_ALIGN_VARIABLE(1024);

    lv_display_t * disp = lv_renesas_glcdc_partial_create(partial_draw_buf, NULL, sizeof(partial_draw_buf));
#endif

#if DIRECT_MODE
    lv_display_set_default(g_lvgl_port_ctrl.p_lv_display);
#else
    lv_display_set_default(disp);
#endif


}

