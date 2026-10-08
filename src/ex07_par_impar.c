/* Exercício 7: diz se um número inteiro é par ou ímpar. */
#include <stdbool.h>
#include "entrada.h"

bool eh_par(int numero) {
    return numero % 2 == 0;
}

int main(void) {
    configurar_console();

    int valor = ler_int("Digite um número inteiro: ");
    printf("%d é um número %s.\n", valor, eh_par(valor) ? "par" : "ímpar");
    return 0;
}
