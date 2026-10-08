/* Exercício 4: lê 5 números inteiros e mostra o valor absoluto de cada um. */
#include "entrada.h"

#define QUANTIDADE 5

int absoluto(int numero) {
    return (numero < 0) ? -numero : numero;
}

int main(void) {
    configurar_console();

    printf("Digite %d valores inteiros:\n", QUANTIDADE);
    for (int i = 1; i <= QUANTIDADE; i++) {
        char mensagem[32];
        snprintf(mensagem, sizeof mensagem, "Valor %d: ", i);
        int valor = ler_int(mensagem);
        printf("Valor absoluto de %d é: %d\n", valor, absoluto(valor));
    }
    return 0;
}
