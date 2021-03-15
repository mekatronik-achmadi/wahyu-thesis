#ifndef _MOTOR_H_
#define _MOTOR_H_

#define MOTOR1      1
#define MOTOR1_PORT GPIOB
#define MOTOR1_STEP 1
#define MOTOR1_DIR  0

#define MOTOR2      2
#define MOTOR2_PORT GPIOB
#define MOTOR2_STEP 11
#define MOTOR2_DIR  10

#define MOTOR3      3
#define MOTOR3_PORT GPIOB
#define MOTOR3_STEP 13
#define MOTOR3_DIR  12

#define MOTOR4      4
#define MOTOR4_PORT GPIOB
#define MOTOR4_STEP 15
#define MOTOR4_DIR  14

void motor_Run(uint8_t motor, uint8_t direction, uint16_t step, uint16_t speed);
void motor_Init(void);

#endif
