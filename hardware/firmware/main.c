#include "ch.h"
#include "hal.h"

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
  
  uint16_t i;
  
  palSetPadMode(GPIOB,12,PAL_MODE_OUTPUT_PUSHPULL);
  palSetPadMode(GPIOB,13,PAL_MODE_OUTPUT_PUSHPULL);
  palClearPad(GPIOB,12);
  palClearPad(GPIOB,13);

  palSetPadMode(GPIOC,13,PAL_MODE_OUTPUT_PUSHPULL);
  palClearPad(GPIOC,13);
  chThdCreateStatic(waLED, sizeof(waLED), NORMALPRIO, thdLED, NULL);

  while(true){
    palClearPad(GPIOB,12);
    for(i=0;i<200;i++){
      palSetPad(GPIOB,13);
      chThdSleepMicroseconds(500);
      palClearPad(GPIOB,13);
      chThdSleepMicroseconds(500);
    }
    
    chThdSleepMilliseconds(1000);
    
    palSetPad(GPIOB,12);
    for(i=0;i<400;i++){
      palSetPad(GPIOB,13);
      chThdSleepMicroseconds(500);
      palClearPad(GPIOB,13);
      chThdSleepMicroseconds(500);
    }
    
    chThdSleepMilliseconds(1000);
  }
}
