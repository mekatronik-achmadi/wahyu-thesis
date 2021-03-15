#include <stdlib.h>

#include "ch.h"
#include "hal.h"

#include "chprintf.h"
#include "shell.h"

#include "usbcdc.h"
#include "cmd.h"
#include "motor.h"

#define SHELL_WA_SIZE   THD_WORKING_AREA_SIZE(512)

extern SerialUSBDriver SDU1;
extern const USBConfig usbcfg;
extern const SerialUSBConfig serusbcfg;

static thread_t *shelltp = NULL;

static void cmd_test(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void)argv;
    if(argc > 0){chprintf(chp,"Usage: test\r\n");return;}

    chprintf(chp,"Serial OK\r\n");
}

static void cmd_motortest(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void)argv;
    if(argc > 0){chprintf(chp,"Usage: motes\r\n");return;}

    chprintf(chp,"Test on Motor 2 \r\n");
    motor_Run(MOTOR2,MOTOR2_CW,300);
}

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

static const ShellCommand commands[] = {
    {"test", cmd_test},
    {"motes",cmd_motortest},
    {"morun",cmd_motorrun},
    {NULL, NULL}
};

static const ShellConfig shell_cfg = {
    (BaseSequentialStream *)&SDU1,
    commands
};

void cmd_Init(void){
    sduObjectInit(&SDU1);
    sduStart(&SDU1, &serusbcfg);

    usbDisconnectBus(serusbcfg.usbp);
    chThdSleepMilliseconds(1500);
    usbStart(serusbcfg.usbp, &usbcfg);
    usbConnectBus(serusbcfg.usbp);

    shellInit();
}

void cmd_Loop(void){
    if (!shelltp && (SDU1.config->usbp->state == USB_ACTIVE))
      shelltp = shellCreate(&shell_cfg, SHELL_WA_SIZE, NORMALPRIO);
    else if (chThdTerminatedX(shelltp)) {
      chThdRelease(shelltp);
      shelltp = NULL;
    }
}
