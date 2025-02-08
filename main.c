#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "pwm.h"
#include "controle.h"

// Vá em pwm.h para definir se você quer acionar o LED ou o servo-motor (apenas wokwi)

int main()
{
    // Verificar o clock períferico para configurar as contas do PWM (125 MHz)
    uint32_t clock_freq = clock_get_hz(clk_peri);
    printf("Clock periférico: %u Hz\n", clock_freq);
    
    // Inicializações
    stdio_init_all();
    pwm_setup();
    ciclos();

    // Loop Principal
    while (true)
    {
        movimento();
    }
}