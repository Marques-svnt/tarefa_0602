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
int calcular_duty_cycle(int microsegundos) {
    return (microsegundos * WRAP_PERIOD) / 20000;
}

// Função para atribuir o valor correto de cada ciclo ativo
void ciclos(){
    // Calcula os duty cycles desejados
    duty_cycle_2400 = calcular_duty_cycle(2400);  // ~2400 us
    duty_cycle_1470 = calcular_duty_cycle(1470);  // ~1470 us
    duty_cycle_500 = calcular_duty_cycle(500);    // ~500 us
}

// Função que atribui o ciclo ativo ao pino com os intervalos estabelecidos
void controle(int duty_cycle, int delay_ms) {
    uint slice = pwm_gpio_to_slice_num(PINO);
    pwm_set_gpio_level(PINO, duty_cycle);
    sleep_ms(delay_ms);
}