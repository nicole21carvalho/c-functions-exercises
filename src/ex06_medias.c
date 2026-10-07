/* Exercício 6: calcula a média aritmética, ponderada ou harmônica de 3 notas. */
#include <stdbool.h>
#include "entrada.h"

/* Devolve true e grava a média em *resultado, ou false se não der para calcular.
   Assim não é preciso usar -1 como "valor de erro", que também poderia ser uma média. */
bool calcular_media(double n1, double n2, double n3, char tipo, double *resultado) {
    switch (tipo) {
        case 'A':
            *resultado = (n1 + n2 + n3) / 3.0;
            return true;
        case 'P':
            *resultado = (n1 * 5 + n2 * 3 + n3 * 2) / 10.0;
            return true;
        case 'H':
            /* A média harmônica não existe se alguma nota for zero (divisão por zero). */
            if (n1 == 0 || n2 == 0 || n3 == 0) {
                return false;
            }
            *resultado = 3.0 / (1.0 / n1 + 1.0 / n2 + 1.0 / n3);
            return true;
        default:
            return false;
    }
}

int main(void) {
    configurar_console();

    double n1 = ler_double("Digite a primeira nota: ");
    double n2 = ler_double("Digite a segunda nota: ");
    double n3 = ler_double("Digite a terceira nota: ");
    char tipo = ler_opcao("Tipo de média (A = aritmética, P = ponderada, H = harmônica): ", "APH");

    double media;
    if (calcular_media(n1, n2, n3, tipo, &media)) {
        printf("A média é: %.2f\n", media);
    } else {
        printf("Não dá para calcular a média harmônica com uma nota zero.\n");
    }
    return 0;
}
