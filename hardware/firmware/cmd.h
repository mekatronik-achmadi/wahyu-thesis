/**
 * @file    cmd.h
 * @brief   Command Shell header.
 *
 * @addtogroup Communication
 * @{
 */

#ifndef _CMD_H_
#define _CMD_H_

/**
 * @brief Shell Echo setting
 * @details if TRUE, Shell will show prompt and input echo
 */
#define SHELL_ECHO FALSE

/**
 * @brief Shell also using UART1
 */
#define SHELL_UART TRUE

void cmd_Init(void);
void cmd_Loop(void);

#endif
/** @} */
