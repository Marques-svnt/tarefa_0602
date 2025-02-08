#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/timer.h"
#include "pwm.h"

uint16_t servo_level = 200;
const uint16_t SERVO_STEP = 200; //passo de incremento/decremento para o duty cycle do Servo motor
const uint16_t WRAP_PERIOD = 4000; //valor máximo do contador - WRAP
const float PWM_DIVISER = 4.0; //divisor do clock para o PWM

//função para configurar o módulo PWM
void pwm_setup()
{
    gpio_set_function(SERVO, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(SERVO); //obter o canal PWM da GPIO

    pwm_set_clkdiv(slice, PWM_DIVISER); //define o divisor de clock do PWM

    pwm_set_wrap(slice, WRAP_PERIOD); //definir o valor de wrap

    pwm_set_gpio_level(SERVO, 100); //definir o cico de trabalho (duty cycle) do pwm

    pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente
}

