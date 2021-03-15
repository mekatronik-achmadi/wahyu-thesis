#include "ch.h"
#include "hal.h"

#include "usbcdc.h"
#include "cmd.h"
#include "motor.h"

static THD_WORKING_AREA(waLED, 128);
static THD_FUNCTION(thdLED, arg) {

    (void)arg;

    chRegSetThreadName("blinker");
    while (true) {
        palTogglePad(GPIOC,13);
        chThdSleepMilliseconds(100);
    }
}

int main(void) {
  halInit();
  chSysInit();

  cmd_Init();
  motor_Init();

  palSetPadMode(GPIOC,13,PAL_MODE_OUTPUT_PUSHPULL);
  chThdCreateStatic(waLED, sizeof(waLED), NORMALPRIO, thdLED, NULL);
  
  while(true){
    cmd_Loop();
    chThdSleepMilliseconds(1000);
  }
}
