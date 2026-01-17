/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hal_data.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int user_read(char *buffer, int file, int count);
int user_write(char ptr, FILE* file);

/* Forward declarations for POSIX functions */
int _write(int file, char *ptr, int len);
int _read(int file, char *ptr, int len);
int _close(int file);
int _fstat(int file, struct stat *st);
int _isatty(int file);
off_t _lseek(int file, off_t ptr, int dir);

volatile bool g_data_received_flag = false;
volatile bool g_data_transmit_flag = false;

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

int user_read(char *buffer, int file, int count)
{
    FSP_PARAMETER_NOT_USED(file);

    int bytesReceived = 0;


    for (int i = 0; i < count; i++)
    {
        // Start Transmission
        g_data_received_flag = false;
        fsp_err_t err = R_SCI_B_UART_Read(&g_uart3_ctrl, (uint8_t * const)(buffer + i), 1U);
        if (FSP_SUCCESS != err)
        {
             return -1;
        }
        /* Wait for event receive complete */
        while (!g_data_received_flag)
        {
        }

        bytesReceived++;

        if ((char)(buffer[i]) == '\r') //Break out of the loop if ENTER is pressed
        {
            break;
        }
    }
    __NOP();
    return bytesReceived;
}

int user_write(char ptr, FILE* file)
{
  FSP_PARAMETER_NOT_USED(file);

  // Start Transmission
  g_data_transmit_flag = false;
  if(ptr != 0)
  {
      fsp_err_t err = R_SCI_B_UART_Write(&g_uart3_ctrl, (uint8_t * const)(&ptr), 1U);
      if (FSP_SUCCESS != err)
      {
           return -1;
      }
  }
  else
      return 0;

  // Wait for event receive complete
  while (!g_data_transmit_flag)
  {
  }

  return FSP_SUCCESS;
}

/* Redirect stdout/stderr to UART for printf support */
int _write(int file, char *ptr, int len)
{
    FSP_PARAMETER_NOT_USED(file);
    
    if (ptr == NULL || len <= 0)
    {
        return 0;
    }
    
    for (int i = 0; i < len; i++)
    {
        user_write(ptr[i], NULL);
    }
    
    return len;
}

/* Minimal POSIX file operations for embedded systems */
int _read(int file, char *ptr, int len)
{
    FSP_PARAMETER_NOT_USED(file);
    
    if (ptr == NULL || len <= 0)
    {
        return 0;
    }
    
    return user_read(ptr, file, len);
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
    return 1;  /* Character device (TTY) */
}

off_t _lseek(int file, off_t ptr, int dir)
{
    FSP_PARAMETER_NOT_USED(file);
    FSP_PARAMETER_NOT_USED(ptr);
    FSP_PARAMETER_NOT_USED(dir);
    return 0;  /* Cannot seek on character device */
}
