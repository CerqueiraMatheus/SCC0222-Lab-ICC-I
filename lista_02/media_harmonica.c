#include <stdio.h>
#include <stdlib.h>

int main() {
    int qtde;
    double *notas, div;

    //Lê a qtde e inicializa o ponteiro
    scanf("%d", &qtde);
    notas = (double *)malloc(qtde * sizeof(double));

    //Recebe os valores das notas e calcula o divisor
    for (int i = 0; i < qtde; i++) {
        scanf("%lf", &notas[i]);
        div += (1 / (notas[i] + 1));
    }

    //Exibe a média harmônica amortizada
    printf("%.2lf", ((qtde / div) - 1));

    //Libera o ponteiro
    free(notas);

    return EXIT_SUCCESS;
}