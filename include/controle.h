#ifndef CONTROLE_H
#define CONTROLE_H

// Funções que controlam a definição dos ciclos ativos e controle do pino
void controle(int duty_cycle, int delay_ms);
void ciclos();

extern int duty_cycle_2400;
extern int duty_cycle_1470;
extern int duty_cycle_500;

#endif