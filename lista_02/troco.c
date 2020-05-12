#include <stdio.h>
#include <stdlib.h>

//Faz o troco na moeda dada enquanto possível
void do_troco(double opt, double *amount, int *counter) {
    *counter = 0;

    //Enquanto a quantidade menos a moeda (arredondados) > 0
    while (((*amount - opt) * 100 + 0.5) >= 0) {
        //Decrementa a quantidade
        *amount = *amount - opt;

        //Incrementa o contador
        ++*counter;
    }
}

int main() {
    char n[512] = {0}; //Vetor para receber o valor

    //Valor total (convertido) e valores de moeda
    double total, valor_moeda[6] = {1, 0.50, 0.25, 0.10, 0.05, 0.01};
    
    int soma_moeda[6] = {0}; //Armazena as quantidades

    //Recebe o valor e converte em decimal
    scanf("%s", n);
    total = atoi(n);
    total /= 100;

    //Executa e exibe o troco da parte decimal
    for (int i = 0; i < 6; i++) {
        //Executa o troco da moeda
        do_troco(valor_moeda[i], &total, &soma_moeda[i]);

        //Printf dos casos "real", singular e plural ("centavo")
        switch (i) {
            case 0:
                printf("O valor consiste em %d moedas de %.0lf real\n", soma_moeda[i], valor_moeda[i]);
                break;
            case 5:
                printf("O valor consiste em %d moedas de %.0lf centavo\n", soma_moeda[i], valor_moeda[i] * 100);
                break;
            default:
                printf("O valor consiste em %d moedas de %.0lf centavos\n", soma_moeda[i], valor_moeda[i] * 100);
                break;
        }
    }
    return EXIT_SUCCESS;
}