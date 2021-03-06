#include "ch.h"
#include "hal.h"

#include "motor.h"

static THD_WORKING_AREA(waMot1, 128);
static THD_FUNCTION(thdMot1, arg) {

    (void)arg;
    uint16_t i;

    chRegSetThreadName("motor-1");

    while (true) {
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
    }
}

void motor_Init(void){
    palSetPadMode(GPIOB,12,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,13,PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(GPIOB,12);
    palClearPad(GPIOB,13);

    palSetPadMode(GPIOC,13,PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(GPIOC,13);

    chThdCreateStatic(waMot1, sizeof(waMot1), NORMALPRIO, thdMot1, NULL);
}
