#include <stdio.h>
#include <stdlib.h>

int main() {
    int maior, menor, qtde, *numbers;

    //Recebe qtde e inicializa o ponteiro
    scanf("%d", &qtde);
    numbers = (int *)malloc(qtde * sizeof(int));

    //Percorre o ponteiro
    for (int i = 0; i < qtde; i++) {
        //Recebe o valor do ponteiro em i
        scanf(" %d", &numbers[i]);

        //Caso seja a primeira execução:
        //Seta maior e menor
        if (i == 0) {
            maior = numbers[i];
            menor = numbers[i];
        } else {
            //Do contrário, compara com o número atual
            if (maior < numbers[i]) maior = numbers[i];
            if (menor > numbers[i]) menor = numbers[i];
        }
    }

    //Exibe maior e menor
    printf("max: %d\nmin: %d", maior, menor);

    //Libera o ponteiro
    free(numbers);
}