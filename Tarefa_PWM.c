#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22    // Pino do servomotor com saída PWM
#define LED_PIN 12      // Pino do LED
#define PWM_WRAP 20000  // Valor máximo do contador PWM para 50Hz (20ms)

// Configuração do PWM para o servomotor
void setup_pwm() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);  // Define a GPIO como PWM
    uint slice = pwm_gpio_to_slice_num(SERVO_PIN); // Obtém o slice correspondente ao pino

    pwm_set_clkdiv(slice, 125.0);  // Ajusta o divisor de clock para gerar 50Hz
    pwm_set_wrap(slice, PWM_WRAP); // Configura o valor máximo do contador
    pwm_set_enabled(slice, true);  // Ativa o PWM
}

// Define a posição do servomotor
void set_servo_position(uint slice, uint16_t pulse_width_us) {
    uint duty_cycle = (pulse_width_us * PWM_WRAP) / 20000;  // Calcula o ciclo de trabalho baseado no tempo do pulso
    pwm_set_gpio_level(SERVO_PIN, duty_cycle);  // Aplica o valor calculado ao PWM
}

// Inicializa o LED
void setup_led() {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

int main() {
    stdio_init_all();   // Configura a comunicação padrão
    setup_pwm();        // Inicializa o PWM do servo
    setup_led();        // Configura a GPIO do LED

    uint slice = pwm_gpio_to_slice_num(SERVO_PIN); // Obtém o slice do PWM

    while (true) {
        // Posição do servo para cima (2400µs) - Irrigação LIGADA
        set_servo_position(slice, 2400); // Servo para cima
        gpio_put(LED_PIN, 1); // Liga o LED (indica que a irrigação está ligada)
        printf("Irrigação LIGADA - LED aceso\n"); // Mensagem no console
        sleep_ms(20000);  // Mantém a irrigação ligada por 20 segundos

        // Posição do servo para baixo (500µs) - Irrigação DESLIGADA
        set_servo_position(slice, 500); // Servo para baixo
        gpio_put(LED_PIN, 0); // Desliga o LED (indica que a irrigação está desligada)
        printf("Irrigação DESLIGADA - LED apagado\n"); // Mensagem no console
        sleep_ms(20000);  // Mantém a irrigação desligada por 20 segundos
    }

    return 0;
}