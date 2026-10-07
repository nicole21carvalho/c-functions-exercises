/* Exercício 2: calcula a distância euclidiana entre dois pontos do plano. */
#include <math.h>
#include "entrada.h"

double distancia_euclidiana(double x1, double y1, double x2, double y2) {
    return hypot(x2 - x1, y2 - y1);
}

int main(void) {
    configurar_console();

    printf("Primeiro ponto\n");
    double x1 = ler_double("  x1: ");
    double y1 = ler_double("  y1: ");
    printf("Segundo ponto\n");
    double x2 = ler_double("  x2: ");
    double y2 = ler_double("  y2: ");

    printf("A distância euclidiana é: %.2f\n", distancia_euclidiana(x1, y1, x2, y2));
    return 0;
}
