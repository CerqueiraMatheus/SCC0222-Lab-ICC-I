#include <stdio.h>
#include <stdlib.h>

int main() {
    //Declara as variáveis necessárias
    //Instancia as usadas no loop
    int n, i, j, actual = 0, iterator = 0;

    //Recebe as variáveis
    scanf("%d %d %d", &n, &i, &j);

    //Repete enquanto o iterator for menor do que nº pedido
    while (iterator < n) {
        //Se for múltiplo de um dos números, imprime e soma
        if ((actual % i == 0) || (actual % j == 0)) {
            printf("%d\n", actual);
            iterator++;
        }
        //Incrementa o número atual
        actual++;
    }

    return EXIT_SUCCESS;
}