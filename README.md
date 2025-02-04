Para utiliza-lo, basta clonar o repositorio, compilar o arquivo "tarefa_semaforo.c" e executa-lo a partir do "diagram.json" - simulador Wokwi.

🚦 Temporizador Periódico – Semáforo com Raspberry Pi Pico W

Este projeto implementa um semáforo utilizando um Raspberry Pi Pico W, empregando a função add_repeating_timer_ms() do Pico SDK para gerenciar a temporização.

🔧 Funcionamento

O semáforo segue uma sequência cíclica de cores com um intervalo de 3 segundos entre cada transição:

1️⃣ Vermelho ➝ 3 segundos
2️⃣ Amarelo ➝ 3 segundos
3️⃣ Verde ➝ 3 segundos

A lógica do temporizador é controlada pela função repeating_timer_callback(), responsável por alternar os estados dos LEDs.

Paralelamente, a função principal (while) imprime uma mensagem na porta serial a cada 1 segundo, simulando um monitoramento contínuo do sistema.

SIMULAÇÃO:

Ferramenta de Simulação: Wokwi
Teste Adicional: Experimento com LED RGB (GPIOs 11, 12 e 13) via BitDogLab.
