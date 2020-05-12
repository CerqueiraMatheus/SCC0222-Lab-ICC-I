#include <stdio.h>
#include <stdlib.h>

int main() {
    //Inicializa o vetor
    int numeros[31] = {0};

    //Recebe os números
    for (int i = 0; i < 31; i++) scanf("%d", &numeros[i]);

    //Imprime os divisíveis pelo último número
    for (int j = 0; j < 30; j++) {
        if (numeros[j] % numeros[30] == 0) {
            printf("%d\n", numeros[j]);
        }
    }

    return EXIT_SUCCESS;
}