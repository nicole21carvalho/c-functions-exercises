/* Exercício 8: diz se um número é positivo, negativo ou zero. */
#include "entrada.h"

/* Devolve 1 para positivo, -1 para negativo e 0 para zero. */
int sinal(int numero) {
    return (numero > 0) - (numero < 0);
}

int main(void) {
    configurar_console();

    int valor = ler_int("Digite um número inteiro: ");

    switch (sinal(valor)) {
        case 1:  printf("%d é um número positivo.\n", valor); break;
        case -1: printf("%d é um número negativo.\n", valor); break;
        default: printf("%d é zero.\n", valor); break;
    }
    return 0;
}
