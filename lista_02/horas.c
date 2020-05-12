#include <stdio.h>
#include <stdlib.h>

int main() {
    double maior, meses[12];
    int pos;

    //Percorre os 12 meses
    for (int i = 0; i < 12; i++) {
        //Lê os meses
        scanf("%lf", &meses[i]);

        //Se for a posição inicial,
        //Instancia pos e maior
        if (i == 0) {
            pos = 0;
            maior = meses[i];
        } else {
            //Caso contrário,
            //se a quantidade no mês for maior que maior
            if (meses[i] > maior) {
                //Pos e maior recebem as informações do mês atual
                pos = i;
                maior = meses[i];
            }
        }
    }

    //Exibe o mês e a quantidade
    printf("%d %.2lf", pos + 1, maior);

    return EXIT_SUCCESS;
}