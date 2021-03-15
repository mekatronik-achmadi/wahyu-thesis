#include "ch.h"
#include "hal.h"

#include "chprintf.h"

#include "motor.h"

uint8_t motor1_run = MOTOR_OFF;
static uint8_t motor1_dir = MOTOR1_CW;
static uint16_t motor1_step;

uint8_t motor2_run = MOTOR_OFF;
static uint8_t motor2_dir = MOTOR2_CW;
static uint16_t motor2_step;

uint8_t motor3_run = MOTOR_OFF;
static uint8_t motor3_dir = MOTOR3_CW;
static uint16_t motor3_step;

uint8_t motor4_run = MOTOR_OFF;
static uint8_t motor4_dir = MOTOR4_CW;
static uint16_t motor4_step;

static THD_WORKING_AREA(waMot1_Run, 128);
static THD_FUNCTION(thdMot1_Run, arg) {
    (void)arg;
    uint16_t stepItr;

    palSetPadMode(MOTOR1_PORT,MOTOR1_DIR,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(MOTOR1_PORT,MOTOR1_STEP,PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(MOTOR1_PORT,MOTOR1_DIR);
    palClearPad(MOTOR1_PORT,MOTOR1_STEP);

    chRegSetThreadName("motor1_run");
    while (true) {
        if(motor1_run==MOTOR_ON){
            if(motor1_dir==MOTOR1_CW){palClearPad(MOTOR1_PORT,MOTOR1_DIR);}
            else{palSetPad(MOTOR1_PORT,MOTOR1_DIR);}

            for(stepItr=0;stepItr<motor1_step;stepItr++){
                palSetPad(MOTOR1_PORT,MOTOR1_STEP);
                chThdSleepMicroseconds(MOTOR_SPEED);
                palClearPad(MOTOR1_PORT,MOTOR1_STEP);
                chThdSleepMicroseconds(MOTOR_SPEED);
            }
            motor1_run = MOTOR_OFF;
        }
        else{motor1_run = MOTOR_OFF;}

        chThdSleepMilliseconds(100);
    }
}

static THD_WORKING_AREA(waMot2_Run, 128);
static THD_FUNCTION(thdMot2_Run, arg) {
    (void)arg;
    uint16_t stepItr;

    palSetPadMode(MOTOR2_PORT,MOTOR2_DIR,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(MOTOR2_PORT,MOTOR2_STEP,PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(MOTOR2_PORT,MOTOR2_DIR);
    palClearPad(MOTOR2_PORT,MOTOR2_STEP);

    chRegSetThreadName("motor2_run");
    while (true) {
        if(motor2_run==MOTOR_ON){
            if(motor2_dir==MOTOR2_CW){palClearPad(MOTOR2_PORT,MOTOR2_DIR);}
            else{palSetPad(MOTOR2_PORT,MOTOR2_DIR);}

            for(stepItr=0;stepItr<motor2_step;stepItr++){
                palSetPad(MOTOR2_PORT,MOTOR2_STEP);
                chThdSleepMicroseconds(MOTOR_SPEED);
                palClearPad(MOTOR2_PORT,MOTOR2_STEP);
                chThdSleepMicroseconds(MOTOR_SPEED);
            }
            motor2_run = MOTOR_OFF;
        }
        else{motor2_run = MOTOR_OFF;}

        chThdSleepMilliseconds(100);
    }
}

static THD_WORKING_AREA(waMot3_Run, 128);
static THD_FUNCTION(thdMot3_Run, arg) {
    (void)arg;
    uint16_t stepItr;

    palSetPadMode(MOTOR3_PORT,MOTOR3_DIR,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(MOTOR3_PORT,MOTOR3_STEP,PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(MOTOR3_PORT,MOTOR3_DIR);
    palClearPad(MOTOR3_PORT,MOTOR3_STEP);

    chRegSetThreadName("motor3_run");
    while (true) {
        if(motor3_run==MOTOR_ON){
            if(motor3_dir==MOTOR3_CW){palClearPad(MOTOR3_PORT,MOTOR3_DIR);}
            else{palSetPad(MOTOR3_PORT,MOTOR3_DIR);}

            for(stepItr=0;stepItr<motor3_step;stepItr++){
                palSetPad(MOTOR3_PORT,MOTOR3_STEP);
                chThdSleepMicroseconds(MOTOR_SPEED);
                palClearPad(MOTOR3_PORT,MOTOR3_STEP);
                chThdSleepMicroseconds(MOTOR_SPEED);
            }
            motor3_run = MOTOR_OFF;
        }
        else{motor3_run = MOTOR_OFF;}

        chThdSleepMilliseconds(100);
    }
}

static THD_WORKING_AREA(waMot4_Run, 128);
static THD_FUNCTION(thdMot4_Run, arg) {
    (void)arg;
    uint16_t stepItr;

    palSetPadMode(MOTOR4_PORT,MOTOR4_DIR,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(MOTOR4_PORT,MOTOR4_STEP,PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(MOTOR4_PORT,MOTOR4_DIR);
    palClearPad(MOTOR4_PORT,MOTOR4_STEP);

    chRegSetThreadName("motor4_run");
    while (true) {
        if(motor4_run==MOTOR_ON){
            if(motor4_dir==MOTOR4_CW){palClearPad(MOTOR4_PORT,MOTOR4_DIR);}
            else{palSetPad(MOTOR4_PORT,MOTOR4_DIR);}

            for(stepItr=0;stepItr<motor4_step;stepItr++){
                palSetPad(MOTOR4_PORT,MOTOR4_STEP);
                chThdSleepMicroseconds(MOTOR_SPEED);
                palClearPad(MOTOR4_PORT,MOTOR4_STEP);
                chThdSleepMicroseconds(MOTOR_SPEED);
            }
            motor4_run = MOTOR_OFF;
        }
        else{motor4_run = MOTOR_OFF;}

        chThdSleepMilliseconds(100);
    }
}

void motor_Run(uint8 mot_num, uint8_t mot_dir, uint16_t mot_step){
    switch(mot_num){
        case MOTOR1: motor1_dir = mot_dir; motor1_step = mot_step; motor1_run = MOTOR_ON; break;
        case MOTOR2: motor2_dir = mot_dir; motor2_step = mot_step; motor2_run = MOTOR_ON; break;
        case MOTOR3: motor3_dir = mot_dir; motor3_step = mot_step; motor3_run = MOTOR_ON; break;
        case MOTOR4: motor4_dir = mot_dir; motor4_step = mot_step; motor4_run = MOTOR_ON; break;
    }
}

void motor_Init(void){
    chThdCreateStatic(waMot1_Run, sizeof(waMot1_Run), NORMALPRIO, thdMot1_Run, NULL);
    chThdCreateStatic(waMot2_Run, sizeof(waMot2_Run), NORMALPRIO, thdMot2_Run, NULL);
    chThdCreateStatic(waMot3_Run, sizeof(waMot3_Run), NORMALPRIO, thdMot3_Run, NULL);
    chThdCreateStatic(waMot4_Run, sizeof(waMot4_Run), NORMALPRIO, thdMot4_Run, NULL);
}
