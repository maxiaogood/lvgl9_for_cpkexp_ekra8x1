#include "dsi_layer.h"

/* This table of commands was adapted from sample code provided by FocusLCD
 * Page Link: https://focuslcds.com/product/4-5-tft-display-capacitive-tp-e45ra-mw276-c/
 * File Link: https://focuslcds.com/content/E45RA-MW276-C_init_code.txt
 */
LCD_setting_table lcd_init_focuslcd[] =
{

         {2,     {0x11, 0x00},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_0_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},

         {2,     {0xF0, 0xC3},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_1_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},
         {2,     {0xF0, 0x96},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_1_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},
         {2,     {0x36, 0x48},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_1_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},
         {2,     {0x3A, 0x55},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_1_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},
         {2,     {0xB4, 0x01},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_1_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},

         //0xB5, VFP=2,VBP=6, HBP=48
//          {5,     {0xB5, 0x02,0x06,0x00,0x30},                           MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},

         {4,     {0xB6, 0x8A, 0x07, 0x3B},   MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},
//          {9,     {0xB6, 0x8A, 0x8A, 0x00,0x00,0x29,0x19,0xA5,0x33},   MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},
         {2,     {0xB7, 0xC6},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_1_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},
         {3,     {0xB9, 0x02,0xE0},                           MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},
         {3,     {0xC0, 0xC0,0x64},                           MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},
         {2,     {0xC1, 0x1D},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_1_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},
         {2,     {0xC2, 0xA7},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_1_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},
         {2,     {0xC5, 0x18},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_1_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},
         {9,     {0xE8, 0x40, 0x8A, 0x00,0x00,0x29,0x19,0xA5,0x33},/*0x25,0x0A,0x38,0x33},*//*0x29,0x19,0xA5,0x33},*/   MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},
         //0xE0, positive gamma 控制
         {15,    {0xE0, 0xF0, 0x0B, 0x12,0x09,0x0A,0x26,0x39,0x54,0x4E,0x38,0x13,0x13,0x2E,0x34},   MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},
         //0xE1, negative gamma 控制
         {15,    {0xE1, 0xF0, 0x10, 0x15,0x0D,0x0C,0x07,0x38,0x43,0x4D,0x3A,0x16,0x15,0x30,0x35},   MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},
         {2,     {0xF0, 0x3C},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_1_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},
         {2,     {0xF0, 0x69},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_1_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},
         {2,     {0x35, 0x00},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_1_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},
//          {1,     {0x29},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_1_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},
//          {1,     {0x21},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_1_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},
         {2,     {0x29, 0x00},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_0_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},

         {2,     {0x21, 0x00},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_0_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},

         {5,     {0x2A, 0x00, 0x31, 0x01,0x0E},   MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},
         {5,     {0x2B, 0x00, 0x00, 0x01,0xDF},   MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},
//          {5,     {0x2B, 0x00, 0x02, 0x01,0xE1},   MIPI_DSI_CMD_ID_DCS_LONG_WRITE, MIPI_DSI_CMD_FLAG_LOW_POWER},

         {2,     {0x2C, 0x00},                           MIPI_DSI_CMD_ID_DCS_SHORT_WRITE_0_PARAM, MIPI_DSI_CMD_FLAG_LOW_POWER},
         {0x00,  {0},                                    MIPI_DSI_DISPLAY_CONFIG_DATA_END_OF_TABLE, (mipi_dsi_cmd_flag_t)0},


};


