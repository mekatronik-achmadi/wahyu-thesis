#ifndef _MOTOR_H_
#define _MOTOR_H_

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

#define MOTOR_SPEED 500
#define MOTOR_CW    0
#define MOTOR_CCW   1
#define MOTOR_ON    1
#define MOTOR_OFF   0

void motor_Run(uint8_t mot_num, uint8_t mot_dir, uint16_t mot_step);
void motor_Init(void);

#endif
