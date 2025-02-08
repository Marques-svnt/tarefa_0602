#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "pwm.h"

//função para configurar o módulo PWM
void pwm_setup() {
    gpio_set_function(PINO, GPIO_FUNC_PWM); // Configura pino para PWM
    uint slice = pwm_gpio_to_slice_num(PINO);
    pwm_set_clkdiv(slice, PWM_DIVISER);     // Define divisor de clock
    pwm_set_wrap(slice, WRAP_PERIOD);       // Define o valor de wrap
    pwm_set_enabled(slice, true);           // Habilita o PWM
}

