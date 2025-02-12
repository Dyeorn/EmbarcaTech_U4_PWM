#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_PIN     22
#define DIV         25            // Clock para reduzir a frequência do PWM
#define WRAP        (uint16_t)100000  // Valor máximo do contador PWM para 50 Hz
#define LED_RGB 12

// Definição dos ciclos ativos para cada posição do servo
#define ANG_180     12000         // WRAP * 0,12 = 12000 para aproximadamente 180 graus
#define ANG_90      7350          // WRAP * 0,0735 = 7350 para aproximadamente 90 graus
#define ANG_0       2500          // WRAP * 0,025 = 2500 para aproximadamente 0 graus

// Incremento para movimentação suave entre posições
#define STEP        25            // Quantidade de incremento para cada ajuste de posição (100.000 / 4000)

int main() {

    stdio_init_all();

    gpio_init(LED_RGB);
    gpio_set_dir(LED_RGB, GPIO_OUT);

    // Configura o pino do servo como saída PWM
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);

    // Obtém o slice PWM correspondente
    uint slice = pwm_gpio_to_slice_num(PWM_PIN);

    // Configura o PWM com frequência de 50Hz
    pwm_set_clkdiv(slice, DIV);
    pwm_set_wrap(slice, WRAP);
    pwm_set_enabled(slice, true);

    // Move o servo para as posições iniciais (180°, 90°, 0°)
    pwm_set_gpio_level(PWM_PIN, ANG_180);
    sleep_ms(5000);

    pwm_set_gpio_level(PWM_PIN, ANG_90);
    sleep_ms(5000);

    pwm_set_gpio_level(PWM_PIN, ANG_0);
    sleep_ms(5000);

    // Variáveis para movimentação cíclica
    uint level = ANG_0;
    bool positive_direction = true;

    while (true) {
        // Ajusta o nível PWM para mover o servo
        pwm_set_gpio_level(PWM_PIN, level);

        // LED indica o sentido do movimento
        if (positive_direction) {
            gpio_put(LED_RGB, 1);  // Liga o LED quando sobe
            level += STEP;         // Move para cima
        } else {
            gpio_put(LED_RGB, 0);  // Desliga o LED quando desce
            level -= STEP;         // Move para baixo
        }

        // Verifica os limites e inverte a direção
        if (level <= ANG_0) {
            positive_direction = true;
        }
        if (level >= ANG_180) {
            positive_direction = false;
        }

        // Atraso para suavizar a movimentação do servo
        sleep_ms(10);
    }
}