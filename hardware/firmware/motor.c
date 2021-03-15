#include "ch.h"
#include "hal.h"

#include "chprintf.h"

#include "motor.h"

extern SerialUSBDriver SDU1;

static void motor1_run(uint8_t direction, uint16_t step, uint16_t speed){
    uint16_t stepItr;

    if(direction==0){palClearPad(MOTOR1_PORT,MOTOR1_DIR);}
    else{palSetPad(MOTOR1_PORT,MOTOR1_DIR);}

    for(stepItr=0;stepItr<step;stepItr++){
        palSetPad(MOTOR1_PORT,MOTOR1_STEP);
        chThdSleepMicroseconds(speed);
        palClearPad(MOTOR1_PORT,MOTOR1_STEP);
        chThdSleepMicroseconds(speed);
    }
}

static void motor2_run(uint8_t direction, uint16_t step, uint16_t speed){
    uint16_t stepItr;

    if(direction==0){palClearPad(MOTOR2_PORT,MOTOR2_DIR);}
    else{palSetPad(MOTOR2_PORT,MOTOR2_DIR);}

    for(stepItr=0;stepItr<step;stepItr++){
        palSetPad(MOTOR2_PORT,MOTOR2_STEP);
        chThdSleepMicroseconds(speed);
        palClearPad(MOTOR2_PORT,MOTOR2_STEP);
        chThdSleepMicroseconds(speed);
    }
}

static void motor3_run(uint8_t direction, uint16_t step, uint16_t speed){
    uint16_t stepItr;

    if(direction==0){palClearPad(MOTOR3_PORT,MOTOR3_DIR);}
    else{palSetPad(MOTOR3_PORT,MOTOR3_DIR);}

    for(stepItr=0;stepItr<step;stepItr++){
        palSetPad(MOTOR3_PORT,MOTOR3_STEP);
        chThdSleepMicroseconds(speed);
        palClearPad(MOTOR3_PORT,MOTOR3_STEP);
        chThdSleepMicroseconds(speed);
    }
}

static void motor4_run(uint8_t direction, uint16_t step, uint16_t speed){
    uint16_t stepItr;

    if(direction==0){palClearPad(MOTOR4_PORT,MOTOR4_DIR);}
    else{palSetPad(MOTOR4_PORT,MOTOR4_DIR);}

    for(stepItr=0;stepItr<step;stepItr++){
        palSetPad(MOTOR4_PORT,MOTOR4_STEP);
        chThdSleepMicroseconds(speed);
        palClearPad(MOTOR4_PORT,MOTOR4_STEP);
        chThdSleepMicroseconds(speed);
    }
}

void motor_Init(void){
    palSetPadMode(MOTOR2_PORT,MOTOR2_DIR,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(MOTOR2_PORT,MOTOR2_STEP, PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(MOTOR2_PORT,MOTOR2_DIR);
    palClearPad(MOTOR2_PORT,MOTOR2_STEP);
}
