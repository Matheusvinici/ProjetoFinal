Controle de Irrigação Automatizado com Servomotor e LED
Este projeto consiste em um sistema de controle de irrigação automatizado que utiliza um servomotor para simular o acionamento de uma válvula de irrigação e um LED para indicar o estado do sistema (ligado/desligado). O sistema é implementado utilizando um microcontrolador Raspberry Pi Pico, programado em C, e opera em ciclos de 20 segundos para ligar e desligar a irrigação.

Vídeo: https://youtu.be/qCsBTqIZC7U


Funcionalidades
Controle de Servomotor: Utiliza PWM (Pulse Width Modulation) para posicionar o servomotor em dois estados:

Irrigação Ligada: Servo posicionado em 2400µs (LED aceso).

Irrigação Desligada: Servo posicionado em 500µs (LED apagado).

Indicação Visual: Um LED indica o estado atual do sistema (ligado/desligado).

Ciclo Automatizado: O sistema alterna entre os estados a cada 20 segundos.

Componentes Utilizados
Raspberry Pi Pico: Microcontrolador principal.

Servomotor: Simula o acionamento de uma válvula de irrigação.

LED: Indicador visual do estado do sistema.

Resistor: Para limitar a corrente no LED.

Fios e Protoboard: Para conexão dos componentes.

Esquema do Circuito
(Opcional: Incluir uma imagem ou descrição do circuito.)

GPIO 22: Saída PWM para controle do servomotor.

GPIO 12: Saída digital para controle do LED.

Configuração do Ambiente
Ferramentas Utilizadas
Wokwi: Simulador online para desenvolvimento e teste do circuito.

Visual Studio Code (VSCode): Ambiente de desenvolvimento local.

Raspberry Pi Pico SDK: Para programação em C.

Passos para Configuração
No Wokwi:

Monte o circuito conforme o esquema.

Desenvolva e teste o código em C.

Exporte os arquivos (diagram.json, ProjetoFinal.c, wokwi.toml).

No VSCode:

Instale as extensões necessárias para programação em C e Raspberry Pi Pico.

Importe os arquivos do Wokwi.

Compile e carregue o código na Raspberry Pi Pico.

Na Raspberry Pi Pico:

Conecte a placa ao computador.

Carregue o código compilado.

Verifique o funcionamento do sistema.

Estrutura do Código
Funções Principais
setup_pwm(): Configura o PWM para controle do servomotor.

set_servo_position(): Define a posição do servomotor com base no tempo de pulso.

setup_led(): Configura o pino do LED como saída digital.

main(): Loop principal que alterna entre os estados de irrigação.

Variáveis Importantes
SERVO_PIN: Pino GPIO do servomotor.

LED_PIN: Pino GPIO do LED.

PWM_WRAP: Valor máximo do contador PWM para 50Hz.

Execução do Projeto
Compile o código no VSCode.

Carregue o código na Raspberry Pi Pico.

Observe o comportamento do servomotor e do LED:

O LED acende e o servo move para a posição de "irrigação ligada".

Após 20 segundos, o LED apaga e o servo move para a posição de "irrigação desligada".

O ciclo se repete indefinidamente.

Melhorias Futuras
Adicionar sensores de umidade do solo para controle automático da irrigação.

Implementar comunicação Wi-Fi ou Bluetooth para controle remoto.

Expandir o sistema para controlar múltiplas válvulas de irrigação.

