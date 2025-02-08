#ifndef PWM_H
#define PWM_H

void pwm_setup();

#define SERVO 22

extern uint16_t servo_level; // Declaração externa
extern const uint16_t SERVO_STEP; // Declaração externa
extern const uint16_t WRAP_PERIOD; // Declaração externa
extern const float PWM_DIVISER; // Declaração externa

#endif