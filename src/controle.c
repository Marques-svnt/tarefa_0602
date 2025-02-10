#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/timer.h"
#include "pwm.h"
#include "controle.h"

// Variáveis globais para cada ciclo ativo
int duty_cycle_2400;
int duty_cycle_1470;
int duty_cycle_500;

// Função para calcular o ciclo ativo correspondente a um pulso em microssegundos
int calcular_duty_cycle(int microsegundos)
{
    return (microsegundos * WRAP_PERIOD) / 20000;
}

// Função para atribuir o valor correto de cada ciclo ativo e definir as posições
void ciclos()
{
    // Calcula os duty cycles desejados
    duty_cycle_2400 = calcular_duty_cycle(2400); // ~2400 us
    duty_cycle_1470 = calcular_duty_cycle(1470); // ~1470 us
    duty_cycle_500 = calcular_duty_cycle(500);   // ~500 us

    // Vai exibir na tela no monitor mensagens associadas á posição do servo motor
    if (PINO == 22)
    {
        // Posiciona em 180 graus (~2400 us)
        printf("Posicionando o servo motor no ângulo 180º\n");
        controle(duty_cycle_2400, 5000);

        // Posiciona em 90 graus (~1470 us)
        printf("Posicionando o servo motor no ângulo 90º\n");
        controle(duty_cycle_1470, 5000);

        // Posiciona em 0 graus (~500 us)
        printf("Posicionando o servo motor no ângulo 0º\n");
        controle(duty_cycle_500, 5000);
    }

    // Vai exibir na tela no monitor mensagens associadas à intensidade do LED vermelho
    else if (PINO == 13)
    {
        // Intensidade alta devido ao ciclo maior (~2400 us)
        printf("Configurando intensidade alta com ciclo de 2400\n");
        controle(duty_cycle_2400, 5000);

        // Intensidade média devido ao ciclo médio (~1470 us)
        printf("Configurando intensidade média com ciclo de 1470\n");
        controle(duty_cycle_1470, 5000);

        // Intensidade baixa devido ao ciclo baixo (~500 us)
        printf("Configurando intensidade baixa com ciclo de 500\n");
        controle(duty_cycle_500, 5000);
    }
}

// Função que atribui o ciclo ativo ao pino com os intervalos estabelecidos
void controle(int duty_cycle, int delay_ms)
{
    uint slice = pwm_gpio_to_slice_num(PINO);
    pwm_set_gpio_level(PINO, duty_cycle);
    sleep_ms(delay_ms);
}

// Função que controla a movimentação suave entre 0 e 180 graus
void movimento()
{
    if (PINO == 22)
    {
        // Incremento suave do duty cycle (~5us)
        for (int duty = duty_cycle_500; duty <= duty_cycle_2400; duty += (5 * WRAP_PERIOD) / 20000)
        {
            controle(duty, 10);

            if (duty == duty_cycle_2400)
            {
                printf("Alternando direção\n");
            }
        }
        // Decremento suave do duty cycle (~5us)
        for (int duty = duty_cycle_2400; duty >= duty_cycle_500; duty -= (5 * WRAP_PERIOD) / 20000)
        {
            controle(duty, 10);

            if (duty == duty_cycle_500)
            {
                printf("Alternando direção\n");
            }
        }
    }
    else if (PINO == 13)
    {
        // Incremento suave do duty cycle (~5us)
        for (int duty = duty_cycle_500; duty <= duty_cycle_2400; duty += (5 * WRAP_PERIOD) / 20000)
        {
            controle(duty, 10);

            if (duty == duty_cycle_2400)
            {
                printf("Aumentando intensidade\n");
            }
        }
        // Decremento suave do duty cycle (~5us)
        for (int duty = duty_cycle_2400; duty >= duty_cycle_500; duty -= (5 * WRAP_PERIOD) / 20000)
        {
            controle(duty, 10);

            if (duty == duty_cycle_500)
            {
                printf("Abaixando intensidade\n");
            }
        }
    }
}