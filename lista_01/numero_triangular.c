#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero;
    int proximo;
    int soma = 0;
    int soma_proximo = 0;

    scanf("%d", &numero);

    for (int i = 1; soma < numero; i++) {
        soma += i;
    }

    if (soma == numero) {
       
        printf("SIM\n");

        proximo = numero + 1;

        while (proximo != soma_proximo) {
            
            soma_proximo = 0;

            for (int i = 1; soma_proximo < proximo; i++) {

                soma_proximo += i;

            }

            proximo++;

        }

        printf("%d\n", proximo);

        if (sqrt(numero + proximo) == abs(sqrt(numero + proximo))) {
        
            printf("SIM\n");

        } else {
            
            printf("NAO\n");
        
        }

    } else {

        printf("NAO");

    }

    return EXIT_SUCCESS;
}