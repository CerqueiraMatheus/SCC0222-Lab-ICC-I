#include <stdio.h>
#include <stdlib.h>

//Checa se é primo (s = 1, n = 0)
int is_prime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, j, size, last_position;
    int *primos;

    //Alocação do ponteiro e scan da entrada
    primos = (int *)malloc(sizeof(int));
    scanf("%d", &n);

    //Percorre com i o número
    //Com j divide
    for (int i = 0; i <= n; i++) {
        for (j = 2; j <= n; j++) {

            //Se n for divisível por um primo
            if (n % j == 0 && is_prime(j)) {

                //O tamanho recebe o valor de j caso i = 0
                //Caso contrário, se j for maior que size, recebe size
                size = ((i == 0) ? (j) : ((j > size) ? j : size));
                
                //Realoca o ponteiro e incrementa a posição
                primos = (int *)realloc(primos, (size + 1) * sizeof(int));
                primos[j]++;
                
                //Limpa as novas posições do ponteiro
                for (int k = last_position + 1; k < j; k++) primos[k] = 0;
                
                //A última posição alterada recebe j
                last_position = j;

                //O número passa a valer sua divisão por j
                n /= j;
            }
        }
    }

    //Impressão do resultado
    for (int i = 1; i <= size; i++) {
        if (primos[i] != 0) {
            printf("%d %d\n", i, primos[i]);
        }
    }

    //Libera o ponteiro
    free(primos);

    return EXIT_SUCCESS;
}