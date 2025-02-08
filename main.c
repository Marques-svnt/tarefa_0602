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

    // Posiciona em 180 graus (~2400 us)
    controle(duty_cycle_2400, 5000);

    // Posiciona em 90 graus (~1470 us)
    controle(duty_cycle_1470, 5000);

    // Posiciona em 0 graus (~500 us)
    controle(duty_cycle_500, 5000);

    // Movimentação suave entre 0 e 180 graus
    while (true)
    {
        // Incremento suave do duty cycle (~5us)
        for (int duty = duty_cycle_500; duty <= duty_cycle_2400; duty += (5 * WRAP_PERIOD) / 20000)
        {
            controle(duty, 10);
        }
        // Decremento suave do duty cycle (~5us)
        for (int duty = duty_cycle_2400; duty >= duty_cycle_500; duty -= (5 * WRAP_PERIOD) / 20000)
        {
            controle(duty, 10);
        }
    }
}