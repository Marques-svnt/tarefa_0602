#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"
#include "pwm.h"

int main()
{
    stdio_init_all();
    pwm_setup();

    // Verificar o clock períferico para configurar as contas do PWM (125 MHz)
    uint32_t clock_freq = clock_get_hz(clk_peri);
    printf("Clock periférico: %u Hz\n", clock_freq);

    uint up_down = 1; // variável para controlar se o nível do servo aumenta ou diminui

    while (true)
    {
        sleep_ms(1000); // Atraso de 1 segundo
    }
}
