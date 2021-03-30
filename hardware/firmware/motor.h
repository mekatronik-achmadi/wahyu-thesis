/**
 * @file    motor.h
 * @brief   Stepper Motor header.
 *
 * @addtogroup Mechatronic
 * @{
 */
#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <stdint.h>
#define MOTOR1      1
#define MOTOR1_PORT GPIOB
#define MOTOR1_STEP 1
#define MOTOR1_DIR  0
#define MOTOR1_CW   0
#define MOTOR1_CCW  1

#define MOTOR2      2
#define MOTOR2_PORT GPIOB
#define MOTOR2_STEP 11
#define MOTOR2_DIR  10
#define MOTOR2_CW   0
#define MOTOR2_CCW  1

#define MOTOR3      3
#define MOTOR3_PORT GPIOB
#define MOTOR3_STEP 13
#define MOTOR3_DIR  12
#define MOTOR3_CW   0
#define MOTOR3_CCW  1

#define MOTOR4      4
#define MOTOR4_PORT GPIOB
#define MOTOR4_STEP 15
#define MOTOR4_DIR  14
#define MOTOR4_CW   0
#define MOTOR4_CCW  1

/**
 * @brief Default Motor Speed as a microsecond delay
 */
#define MOTOR_SPEED 500

/**
 * @brief Default Clock-Wise value
 */
#define MOTOR_CW    0

/**
 * @brief Default Counter Clock-Wise value
 */
#define MOTOR_CCW   1

/**
 * @brief Default Motor On/Run value
 */
#define MOTOR_ON    1

/**
 * @brief Default Motor Off/Stop value
 */
#define MOTOR_OFF   0

void motor_Run(uint8_t mot_num, uint8_t mot_dir, uint16_t mot_step, uint16_t mot_spd);
uint8_t motor_IsRun(uint8_t mot_num);
void motor_Init(void);

#endif
/** @} */
