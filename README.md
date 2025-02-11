# Projeto: Controle de Servomotor por PWM

## Descrição
Este projeto utiliza a placa Raspberry Pi Pico W para demonstrar o controle de um servomotor por meio de PWM (Modulação por Largura de Pulso). A simulação foi conduzida utilizando o simulador online Wokwi, e o controle de LED na placa BitDogLab.

OBS: Antes de iniciar o projeto, verifique na pasta include e no cabeçalho pwm.h qual valor está definido para o PINO, sendo 22 para funcionar o servomotor e 13 para o LED (vermelho)

---

## Funcionalidades

### Configuração do PWM
- Definição da frequência de PWM para aproximadamente **50Hz** (período de 20ms).

### Controle do Servo
- **180 graus:** Ciclo ativo de **2.400µs** (0,12%).
- **90 graus:** Ciclo ativo de **1.470µs** (0,0735%).
- **0 graus:** Ciclo ativo de **500µs** (0,025%).
- Cada posição mantida por **5 segundos**.

### Movimentação Suave do Servo
- Movimentação suave entre os ângulos de **0 e 180 graus**, com incremento de ciclo ativo de **±5µs** e atraso de ajuste de **10ms**.

### Experimento com LED RGB
- **Iluminação Dinâmica:** Utilização do LED RGB conectado à GPIO 12.
- Observação do comportamento dinâmico durante a execução do código:
  Resultado: Foi possível observar que os mesmos parâmetros de ciclos ativos usados para o controle do servo motor poderam ser aplicados no led, onde tivemos a configuração de três intensidades e logo após os intervalos tivemos uma oscilação bem suave da intensidade luminosa do led

---

## Requisitos

- Placa Raspberry Pi Pico W
- Servomotor simulado no Wokwi
- LED RGB
- Ambiente de desenvolvimento configurado com Pico SDK
- VS Code com suporte para Raspberry Pi Pico
- Integração com Wokwi

---

## Configuração

### Mapeamento de GPIOs

| Componente    | GPIO |
|---------------|------|
| Servomotor    | GPIO 22 |
| LED RGB       | GPIO 12 |

---

## Compilação e Execução

1. Certifique-se de que o SDK do RP2040 está configurado no seu ambiente.
2. Compile o programa utilizando a extensão **Raspberry Pi Pico Project** no VS Code:
   - Abra o projeto no VS Code.
   - Navegue até a extensão do **Raspberry Pi Pico Project** e clique em **Compile Project**.
3. Coloque a placa em modo boot cell e copie o arquivo `main.uf2`, que está na pasta build, para o microcontrolador conectado via USB.

---

## Emulação com Wokwi

Para testar o programa sem hardware físico, você pode utilizar o **Wokwi** para emulação no VS Code:

1. Instale a extensão **Wokwi for VS Code**.
2. Inicie a emulação:
   - Configure os componentes conforme a especificação das atividades.
3. Teste o funcionamento do programa diretamente no ambiente emulado.

---

## Demonstração no YouTube

Confira a demonstração completa deste projeto no YouTube: [Demonstração do Projeto](https://www.youtube.com/watch?v=sBOSv5qsAYQ)

---

## Colaboradores

- [Gabriel Marques](https://github.com/Marques-svnt)

---

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).

