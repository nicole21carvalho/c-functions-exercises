/* Exercício 3: calcula base elevada a um expoente usando recursão. */
#include "entrada.h"

/* Usa long long para aguentar resultados maiores que um int. */
long long potencia(int base, int expoente) {
    if (expoente == 0) {
        return 1;
    }
    return base * potencia(base, expoente - 1);
}

int main(void) {
    configurar_console();

    int base = ler_int("Digite a base: ");
    int expoente = ler_int("Digite o expoente (de 0 a 30): ");

    if (expoente < 0 || expoente > 30) {
        printf("O expoente deve estar entre 0 e 30.\n");
        return 1;
    }

    printf("%d elevado a %d é: %lld\n", base, expoente, potencia(base, expoente));
    return 0;
}
