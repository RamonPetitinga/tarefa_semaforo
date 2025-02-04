#include <stdio.h>
#include "pico/stdlib.h"    // Inclui a biblioteca padrão para funcionalidades básicas como GPIO, temporização e comunicação serial.
#include "hardware/timer.h" // Inclui a biblioteca para gerenciamento de temporizadores de hardware.

#define led_vermelho 11
#define led_amarelo 12
#define led_verde 13
bool led_on = false;

int contador = 1;

// Função de callback que será chamada repetidamente pelo temporizador
// O tipo bool indica que a função deve retornar verdadeiro ou falso para continuar ou parar o temporizador.
bool repeating_timer_callback_3S(struct repeating_timer *t)
{
    // Imprime uma mensagem na saída serial indicando que 3 segundos se passaram.
    printf("3 segundos passaram\n");
    // Liga ou desliga o led.
    switch (contador)
    {
    case 1:
        gpio_put(led_vermelho, true);
        gpio_put(led_amarelo, false);
        gpio_put(led_verde, false);
        printf("LED vermelho ligado\n");
        contador++;
        break;
    case 2:
        gpio_put(led_vermelho, false);
        gpio_put(led_amarelo, true);
        gpio_put(led_verde, false);
        printf("LED amarelo ligado\n");
        contador++;
        break;
    case 3:
        gpio_put(led_vermelho, false);
        gpio_put(led_amarelo, false);
        gpio_put(led_verde, true);
        printf("LED verde ligado\n");
        contador = 1;
        break;
    }
    // Retorna true para manter o temporizador repetindo. Se retornar false, o temporizador para.
    return true;
}

bool repeating_timer_callback_1S(struct repeating_timer *t)
{
    // Imprime uma mensagem na saída serial indicando que 1 segundo se passou.
    printf("1 segundo se passou\n");
    // Retorna true para manter o temporizador repetindo. Se retornar false, o temporizador para.
    return true;
}

int main()
{
    int tempo = 1;

    // Inicializa a comunicação serial, permitindo o uso de funções como printf.
    stdio_init_all();

    // Inicializar os pinos GPIO
    gpio_init(led_vermelho);
    gpio_set_dir(led_vermelho, GPIO_OUT);
    gpio_init(led_amarelo);
    gpio_set_dir(led_amarelo, GPIO_OUT);
    gpio_init(led_verde);
    gpio_set_dir(led_verde, GPIO_OUT);

    // Declaração de uma estrutura de temporizador de repetição.
    // Esta estrutura armazenará informações sobre o temporizador configurado.
    struct repeating_timer timer1, timer2;

    // Configura o temporizador para chamar a função de callback a cada 3 segundos.
    add_repeating_timer_ms(3000, repeating_timer_callback_3S, NULL, &timer1);
    // Configura o temporizador para chamar a função de callback a cada 1 segundo.
    add_repeating_timer_ms(1000, repeating_timer_callback_1S, NULL, &timer2);

    // Loop infinito que mantém o programa em execução.
    while (true)
    {
        // Pausa de 1 segundo para reduzir o uso da CPU.
        sleep_ms(1000);
        printf("Se passou %d segundo(s)\n", tempo);
        tempo++;
    }
    return 0;
}