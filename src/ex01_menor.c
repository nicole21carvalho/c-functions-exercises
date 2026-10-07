/* Exercício 1: mostra o menor entre dois números inteiros. */
#include "entrada.h"

int menor(int a, int b) {
    return (a < b) ? a : b;
}

int main(void) {
    configurar_console();

    int primeiro = ler_int("Digite o primeiro número: ");
    int segundo = ler_int("Digite o segundo número: ");

    printf("O menor número é: %d\n", menor(primeiro, segundo));
    return 0;
}
