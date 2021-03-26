/**
 * @file    cmd.c
 * @brief   Command Shell code.
 *
 * @addtogroup Communication
 * @{
 */

#include <stdint.h>
#include <stdlib.h>

#include "ch.h"
#include "hal.h"

#include "chprintf.h"
#include "pal.h"
#include "pal_lld.h"
#include "serial.h"
#include "shell.h"

#include "usbcdc.h"
#include "cmd.h"
#include "motor.h"

#define SHELL_WA_SIZE   THD_WORKING_AREA_SIZE(512)

extern SerialUSBDriver SDU1;
extern const USBConfig usbcfg;
extern const SerialUSBConfig serusbcfg;

/**
 * @brief USB Serial Shell thread object
 */
static thread_t *shelltp = NULL;

/**
 * @brief UART Serial Shell thread object
 */
static thread_t *sershelltp = NULL;

/**
 * @brief Command Test
 * @details Command to test serial shell
 * @details Must be called from shell thread
 */
static void cmd_test(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void)argv;
    if(argc > 0){chprintf(chp,"Usage: test\r\n");return;}

    chprintf(chp,"Serial OK\r\n");
}

/**
 * @brief Command Motor Test
 * @details Command to test motor on motor-2
 * @details Must be called from shell thread
 */
static void cmd_motortest(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void)argv;
    if(argc > 0){chprintf(chp,"Usage: motes\r\n");return;}

    chprintf(chp,"Test on Motor 2 \r\n");
    motor_Run(MOTOR2,MOTOR2_CW,300);
}

/**
 * @brief Command Motor Run
 * @details Command to run motor
 * @details Must be called from shell thread
 */
static void cmd_motorrun(BaseSequentialStream *chp, int argc, char *argv[]) {
    uint8_t motnum;
    uint8_t motdir;
    uint16_t motstep;

    if(argc != 3){chprintf(chp,"Usage: morun <number> <direction> <steps>\r\n");return;}
    motnum = atoi(argv[0]);
    motdir = atoi(argv[1]);
    motstep = atoi(argv[2]);

    chprintf(chp,"Run on Motor %i at %i dir and %i steps\r\n",motnum,motdir,motstep);
    motor_Run(motnum,motdir,motstep);
}

/**
 * @brief Command Get Motor Run Status
 * @details Command to Get if a motor still run or not
 * @details This is just programmatically checking
 * @details Must be called from shell thread
 */
static void cmd_motorstt(BaseSequentialStream *chp, int argc, char *argv[]) {
    uint8_t motstt;

    if(argc != 3){chprintf(chp,"Usage: morun <number>\r\n");return;}

    motstt = motor_IsRun(atoi(argv[0]));

    if(motstt==MOTOR_ON){chprintf(chp,"ON\r\n");}
    else{chprintf(chp,"OFF\r\n");}
}

/**
 * @brief Shell command array
 */
static const ShellCommand commands[] = {
    {"test", cmd_test},
    {"motes",cmd_motortest},
    {"morun",cmd_motorrun},
    {"mostt",cmd_motorstt},
    {NULL, NULL}
};

/**
 * @brief USB Shell config array
 */
static const ShellConfig shell_cfg = {
    (BaseSequentialStream *)&SDU1,
    commands
};

/**
 * @brief UART Shell config array
 */
static const ShellConfig sershell_cfg = {
    (BaseSequentialStream *)&SD1,
    commands
};

/**
 * @brief Shell Initiation
 */
void cmd_Init(void){
    sduObjectInit(&SDU1);
    sduStart(&SDU1, &serusbcfg);

    usbDisconnectBus(serusbcfg.usbp);
    chThdSleepMilliseconds(1500);
    usbStart(serusbcfg.usbp, &usbcfg);
    usbConnectBus(serusbcfg.usbp);

#if SHELL_UART
    palSetPadMode(GPIOA, 9, PAL_MODE_STM32_ALTERNATE_PUSHPULL);
    palSetPadMode(GPIOA, 10, PAL_MODE_INPUT);
    sdStart(&SD1, NULL);
#endif

    shellInit();
}

/**
 * @brief Shell Loop checking
 */
void cmd_Loop(void){
    if (!shelltp && (SDU1.config->usbp->state == USB_ACTIVE))
      shelltp = shellCreate(&shell_cfg, SHELL_WA_SIZE, NORMALPRIO);
    else if (chThdTerminatedX(shelltp)) {
      chThdRelease(shelltp);
      shelltp = NULL;
    }

#if SHELL_UART
    if(!sershelltp)
        shelltp = shellCreate(&sershell_cfg, SHELL_WA_SIZE, NORMALPRIO);
    else if (chThdTerminatedX(sershelltp)) {
        chThdRelease(sershelltp);
        sershelltp = NULL;
    }
#endif

   chThdSleepMilliseconds(100);
}

/** @} */
