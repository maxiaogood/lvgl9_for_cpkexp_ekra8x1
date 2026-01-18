/*
 * Copyright (c) 2025 BekenCorp. All rights reserved.
 * 
 * This software is proprietary and confidential. No part of this software may be
 * reproduced, distributed, or transmitted in any form or by any means, including
 * photocopying, recording, or other electronic or mechanical methods, without the
 * prior written permission of BekenCorp, except in the case of brief quotations
 * embodied in critical reviews and certain other noncommercial uses permitted
 * by copyright law.
 * 
 * For permission requests, write to BekenCorp at armino_support@bekencorp.com.

 * Author: Beken LVGL Designer Tool
*/ 
#include "lvgl.h"
#include "beken_ui.h"
#include "custom_func.h"
#include "event_runtime.h"
#include <stdio.h>
#include <string.h>

/*
 * @brief: init page page_main
 */
void init_page_page_main(bk_lv_ui_t *bk_ui)
{
    if (bk_ui->page_main != NULL && lv_obj_is_valid(bk_ui->page_main)) {
        destroy_page_page_main(bk_ui);
    }
    

    bk_ui->page_main = lv_obj_create(NULL);
    lv_obj_set_scrollbar_mode(bk_ui->page_main, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_size(bk_ui->page_main, 222, 480);
    lv_obj_set_style_bg_color(bk_ui->page_main, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->page_main, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->page_main, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_ui->page_main_animimg_1 = lv_animimg_create(bk_ui->page_main);
    static const void * page_main_animimg_1_imgs[] = {
        &boot0_222x480_RGB565A8_NONE,
        &boot3_222x480_RGB565A8_NONE,
        &boot2_222x480_RGB565A8_NONE
    };
    lv_animimg_set_src(bk_ui->page_main_animimg_1, page_main_animimg_1_imgs, 3);
    lv_animimg_set_duration(bk_ui->page_main_animimg_1, 500 * 3);
    lv_animimg_set_repeat_count(bk_ui->page_main_animimg_1, 0);
    lv_animimg_start(bk_ui->page_main_animimg_1);
    lv_obj_set_x(bk_ui->page_main_animimg_1, 0);
    lv_obj_set_y(bk_ui->page_main_animimg_1, 0);
    lv_obj_set_width(bk_ui->page_main_animimg_1, 222);
    lv_obj_set_height(bk_ui->page_main_animimg_1, 480);
    lv_obj_set_style_bg_color(bk_ui->page_main_animimg_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bk_ui->page_main_animimg_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(bk_ui->page_main_animimg_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(bk_ui->page_main_animimg_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(bk_ui->page_main_animimg_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(bk_ui->page_main_animimg_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(bk_ui->page_main_animimg_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(bk_ui->page_main_animimg_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(bk_ui->page_main_animimg_1, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(bk_ui->page_main_animimg_1, lv_color_hex(0x1e7fcf), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(bk_ui->page_main_animimg_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(bk_ui->page_main_animimg_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(bk_ui->page_main_animimg_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(bk_ui->page_main_animimg_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(bk_ui->page_main_animimg_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_update_layout(bk_ui->page_main);
}

/*
 * @brief: destroy page page_main
 */
void destroy_page_page_main(bk_lv_ui_t *bk_ui)
{
    if (bk_ui == NULL) {
        return;
    }
    
    if (bk_ui->page_main != NULL) {
        lv_obj_del(bk_ui->page_main);
        bk_ui->page_main = NULL;
    }
}