#include <stdio.h>
#include <stdlib.h>

//Calcula o movimento e retorna a posição
//Direita += 1 / Esquerda -=1
//Caso negativo, retorna 3; Maior que 4, 0.
int calcula_mov(int p, char c) {
    int mov = ((c == 'D') ? (1) : (-1)) + p;
    return ((mov >= 0 && mov <= 3) ? (mov) : ((mov < 0) ? 3 : 0));
}

int main() {
    char mov[200] = {0};
    int position = 0;

    //Lê os movimentos e calcula a posição
    scanf("%s", mov);
    for (int i = 0; mov[i] != '\0'; i++) position = calcula_mov(position, mov[i]);

    //Imprime a posição final
    switch (position) {
        case 0:
            printf("Norte");
            break;

        case 1:
            printf("Leste");
            break;

        case 2:
            printf("Sul");
            break;

        case 3:
            printf("Oeste");
            break;
    }

    return EXIT_SUCCESS;
}