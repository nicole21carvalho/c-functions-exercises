/* Exercício 5: lê 5 números positivos e mostra a soma dos divisores de cada um. */
#include "entrada.h"

#define QUANTIDADE 5

int ler_numero_positivo(void) {
    for (;;) {
        int numero = ler_int("Digite um número inteiro positivo: ");
        if (numero > 0) {
            return numero;
        }
        printf("O número deve ser positivo. Tente novamente.\n");
    }
}

/* Soma os divisores próprios (todos menos o próprio número).
   Só precisa testar até a raiz quadrada: cada divisor i tem o par numero / i. */
int soma_divisores(int numero) {
    if (numero == 1) {
        return 0;
    }
    int soma = 1;
    for (int i = 2; (long long)i * i <= numero; i++) {
        if (numero % i == 0) {
            soma += i;
            int par = numero / i;
            if (par != i) {
                soma += par;
            }
        }
    }
    return soma;
}

int main(void) {
    configurar_console();

    int numeros[QUANTIDADE];
    for (int i = 0; i < QUANTIDADE; i++) {
        numeros[i] = ler_numero_positivo();
    }

    printf("\nSoma dos divisores (exceto o próprio número):\n");
    for (int i = 0; i < QUANTIDADE; i++) {
        printf("Soma dos divisores de %d: %d\n", numeros[i], soma_divisores(numeros[i]));
    }
    return 0;
}
