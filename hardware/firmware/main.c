/**
 * @file    main.c
 * @brief   Main code.
 *
 * @addtogroup Main
 * @{
 */

#include "ch.h"
#include "hal.h"

#include "usbcdc.h"
#include "cmd.h"
#include "motor.h"

static THD_WORKING_AREA(waLED, 128);
#define runLED_Loop THD_FUNCTION

/**
 * @brief LED thread
 * @details LED run indicator thred
 */
static runLED_Loop(thdLED, arg) {

    (void)arg;

    chRegSetThreadName("blinker");
    while (true) {
        palTogglePad(GPIOC,13);
        chThdSleepMilliseconds(100);
    }
}

/**
 * @brief Main Function
 * @details First entry of all
 * @return Never reached
 */
int main(void) {
  halInit();
  chSysInit();

  cmd_Init();
  motor_Init();

  palSetPadMode(GPIOC,13,PAL_MODE_OUTPUT_PUSHPULL);
  chThdCreateStatic(waLED, sizeof(waLED), NORMALPRIO, thdLED, NULL);

  while(true){
    cmd_Loop();
    chThdSleepMilliseconds(500);
  }
}

/** @} */
