#include <stdio.h>
#include <stdlib.h>

//Lê int
int readInt() {
    int n;
    scanf("%d", &n);
    return n;
}

//Lê double
double readDouble() {
    double d;
    scanf("%lf", &d);
    return d;
}

//Exibe double com 2 decimais
double printDouble(double d) {
    printf("%.2lf", d);
    return d;
}

int main() {
    //Lê a qtde e cria as demais variáveis
    int qtde = readInt();
    double *notas, div;

    //Inicializa o ponteiro
    notas = (double *)malloc(qtde * sizeof(double));

    //Recebe os valores das notas e calcula o divisor
    for (int i = 0; i < qtde; i++) {
        notas[i] = readDouble();
        div += (1 / (notas[i] + 1));
    }

    //Exibe a média harmônica amortizada
    printDouble((qtde / div) - 1);

    //Libera o ponteiro
    free(notas);

    return EXIT_SUCCESS;
}