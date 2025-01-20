#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    // Inicializa a UART padrão (UART0) com a taxa de transmissão de 9600 baud
    stdio_init_all();

    // Mensagem de boas-vindas
    printf("Digite seu nome e pressione Enter:\n");

    char nome[100];  // Buffer para armazenar o nome
    int index = 0;   // Índice para armazenar os caracteres no buffer

    while (true) {
        // Aguarda até que um caractere seja recebido
        int c = getchar_timeout_us(1000000);  // Timeout de 1 segundo para aguardar entrada

        if (c != PICO_ERROR_TIMEOUT && c != EOF) {
            if (c == '\n' || c == '\r') {
                // Fim da entrada (Enter pressionado)
                nome[index] = '\0';  // Termina a string com '\0'
                printf("\nOlá, %s! Seja bem-vindo!\n", nome);
                index = 0;  // Reinicia o índice para a próxima entrada
                printf("Digite outro nome ou pressione Ctrl+C para sair:\n");
            } else {
                // Armazena o caractere no buffer
                if (index < (int)(sizeof(nome) - 1)) {
                    nome[index++] = (char)c;
                } else {
                    printf("\nO nome é muito longo! Por favor, tente novamente.\n");
                    index = 0;  // Reinicia o índice
                }
            }
        }
    }
    return 0;
}
