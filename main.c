#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "pwm.h"
#include "controle.h"

int main()
{
    // Inicializações
    stdio_init_all();
    pwm_setup();
    ciclos();

    // Verificar o clock períferico para configurar as contas do PWM (125 MHz)
    uint32_t clock_freq = clock_get_hz(clk_peri);
    printf("Clock periférico: %u Hz\n", clock_freq);

    // Loop Principal
    while (true)
    {
        movimento();
    }
}