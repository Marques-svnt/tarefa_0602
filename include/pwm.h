#ifndef PWM_H
#define PWM_H

//Função que define o PWM
void pwm_setup();

// Definições necessárias para configurar a frequência e se o código executará no servo motor ou no pino

#define PINO 22 // Para usar o servo motor
//#define PINO 13 // Para usar o led

#define WRAP_PERIOD 19999 // Para 50 Hz
#define PWM_DIVISER 125.0    // Divisor ajustado

#endif