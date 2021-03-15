#ifndef _MOTOR_H_
#define _MOTOR_H_

#define MOTOR1      1

#define MOTOR2      2
#define MOTOR2_PORT GPIOB
#define MOTOR2_STEP 11
#define MOTOR2_DIR  10

#define MOTOR3      3
#define MOTOR4      4

void motor_Run(uint8_t motor, uint8_t direction, uint16_t step, uint16_t speed);
void motor_Init(void);

#endif
