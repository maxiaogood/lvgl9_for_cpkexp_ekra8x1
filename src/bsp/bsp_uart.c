/**
 * @file bsp_uart.c
 * @author maxiao (maxiaogood@qq.com)
 * @brief 串口驱动实现文件, 重定向printf和scanf到串口3
 * @version 0.1
 * @date 2026-01-18
 *
 * @copyright Copyright (c) 2026, maxiao. All rights reserved.
 *
 */
#include "board_init.h"
#include "hal_data.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/* Forward declarations for POSIX functions */
int _write(int file, char *ptr, int len);
int _read(int file, char *ptr, int len);
int _close(int file);
int _fstat(int file, struct stat *st);
int _isatty(int file);
off_t _lseek(int file, off_t ptr, int dir);

volatile bool g_data_received_flag = false;
volatile bool g_data_transmit_flag = false;

/**
 * @brief 串口3初始化
 *
 */
void BspUart3Init(void)
{
    fsp_err_t err = FSP_ERR_ASSERTION;

    err = R_SCI_B_UART_Open(&g_uart3_ctrl, &g_uart3_cfg);
    if (FSP_SUCCESS != err)
    {
        while (1)
            ;
    }
}

/**
 * @brief 串口回调函数,用于设置接收和发送完成标志,函数名需与hal_data.h中声明的保持一致
 *
 * @param p_args
 */
void user_uart3_callback(uart_callback_args_t *p_args)
{
    switch (p_args->event)
    {
    case UART_EVENT_TX_COMPLETE:
        g_data_transmit_flag = true;
        break;

    case UART_EVENT_RX_COMPLETE:
        g_data_received_flag = true;
        break;

    default:
        break;
    }
}

/**
 * @brief 写入数据到串口 (POSIX _write)
 *
 * @param file
 * @param ptr
 * @param len
 * @return int
 */
int _write(int file, char *ptr, int len)
{
    FSP_PARAMETER_NOT_USED(file);

    if (ptr == NULL || len <= 0)
    {
        return 0;
    }

    // Start Transmission - write all bytes at once
    g_data_transmit_flag = false;
    fsp_err_t err = R_SCI_B_UART_Write(&g_uart3_ctrl, (uint8_t *const)(ptr), (uint32_t)len);
    if (FSP_SUCCESS != err)
    {
        return -1;
    }

    // Wait for event transmit complete
    while (!g_data_transmit_flag)
    {
    }

    return len;
}

/**
 * @brief 从串口读取数据 (POSIX _read)
 *
 * @param file
 * @param ptr
 * @param len
 * @return int
 */
int _read(int file, char *ptr, int len)
{
    FSP_PARAMETER_NOT_USED(file);

    if (ptr == NULL || len <= 0)
    {
        return 0;
    }

    int bytes_received = 0;

    for (int i = 0; i < len; i++)
    {
        // Start Reception
        g_data_received_flag = false;
        fsp_err_t err = R_SCI_B_UART_Read(&g_uart3_ctrl, (uint8_t *const)(ptr + i), 1U);
        if (FSP_SUCCESS != err)
        {
            return -1;
        }
        /* Wait for event receive complete */
        while (!g_data_received_flag)
        {
        }

        bytes_received++;

        if ((char)(ptr[i]) == '\r') // Break out of the loop if ENTER is pressed
        {
            break;
        }
    }
    __NOP();
    return bytes_received;
}

int _close(int file)
{
    FSP_PARAMETER_NOT_USED(file);
    return 0;
}

int _fstat(int file, struct stat *st)
{
    FSP_PARAMETER_NOT_USED(file);

    if (st != NULL)
    {
        st->st_mode = S_IFCHR;
        st->st_blksize = 1024;
    }
    return 0;
}

int _isatty(int file)
{
    FSP_PARAMETER_NOT_USED(file);
    return 1; /* Character device (TTY) */
}

off_t _lseek(int file, off_t ptr, int dir)
{
    FSP_PARAMETER_NOT_USED(file);
    FSP_PARAMETER_NOT_USED(ptr);
    FSP_PARAMETER_NOT_USED(dir);
    return 0; /* Cannot seek on character device */
}
