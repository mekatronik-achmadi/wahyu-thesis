#include "ch.h"
#include "hal.h"

#include "chprintf.h"

#include "motor.h"

extern SerialUSBDriver SDU1;

static void motor2_run(uint8_t direction, uint16_t step, uint16_t speed){
    uint16_t stepIt;

    if(direction==0){palClearPad(MOTOR2_PORT,MOTOR2_DIR);}
    else{palSetPad(MOTOR2_PORT,MOTOR2_DIR);}

    for(stepIt=0;stepIt<step;stepIt++){
        palSetPad(MOTOR2_PORT,MOTOR2_STEP);
        chThdSleepMicroseconds(speed);
        palClearPad(MOTOR2_PORT,MOTOR2_STEP);
        chThdSleepMicroseconds(speed);
    }
}

/**
 * @brief Run Motor function
 * @param[in] uint8 Motor Index (1,2,3,4)
 * @param[in] uint8 Rotate direction (0 or 1)
 * @param[in] uint16 Number of step
 * @param[in] uint16 Step change interval in millisecond
 */
void motor_Run(uint8_t motor, uint8_t direction, uint16_t step, uint16_t speed){
    switch (motor) {
        case MOTOR1: break;
        case MOTOR2: motor2_run(direction,step,speed); break;
        case MOTOR3: break;
        case MOTOR4: break;

        default:
            chprintf((BaseSequentialStream *)&SDU1,"motor number outside intended\r\n");
            break;
    }
}

void motor_Init(void){
    palSetPadMode(MOTOR2_PORT,MOTOR2_DIR,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(MOTOR2_PORT,MOTOR2_STEP, PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(MOTOR2_PORT,MOTOR2_DIR);
    palClearPad(MOTOR2_PORT,MOTOR2_STEP);
}
