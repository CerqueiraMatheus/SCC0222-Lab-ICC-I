#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//Para operar com booleanos
#define boolean int
#define TRUE 1
#define FALSE 0

//Lê e aloca a matriz de acordo com as dimensões dadas
void readMatrix(int ***matrix, int dimension_n, int dimension_m) {
    (*matrix) = (int **)realloc((*matrix), dimension_n * sizeof(int *));
    for (int i = 0; i < dimension_n; i++) {
        (*matrix)[i] = (int *)realloc((*matrix)[i], dimension_m * sizeof(int));
        for (int j = 0; j < dimension_m; j++) {
            scanf("%d", &(*matrix)[i][j]);
        }
    }
}

//Checa o escape do usuário a partir de sua posição e da base
boolean checkEscape(int ***matrix, int position_x, int position_y, int dimension_n, int dimension_m, double movement) {
    //Operadores de localização da base
    int base_y;
    int base_x;

    //Operador de execução
    boolean baseFound = FALSE;

    //Percorre a matriz em busca da base
    for (base_x = 0; base_x < dimension_n && !baseFound; base_x++)
        for (base_y = 0; base_y < dimension_m && !baseFound; base_y++)
            if ((*matrix)[base_x][base_y] == 1)
                baseFound = TRUE;

    //Executa a distância euclidiana
    double euclidian_distance = sqrt(
        pow((position_x - (base_x - 1)), 2) +
        pow((position_y - (base_y - 1)), 2));

    //Verifica se a distância é menor ou igual ao movimento
    return (euclidian_distance <= movement) ? TRUE : FALSE;
}

//Libera a matriz
void freeMatrix(int ***matrix, int dimension_n) {
    for (int i = 0; i < dimension_n; i++) {
        free((*matrix)[i]);
    }
    free(*matrix);
}

int main() {
    //Matriz do jogo
    int **matrix = NULL;

    //Operadores da dimensão
    int dimension_n;
    int dimension_m;

    //Posição atual
    int position_x;
    int position_y;

    //Movimento possível
    double movement;

    //Recebe os valores
    scanf("%d %d", &dimension_n, &dimension_m);
    scanf("%d %d %lf", &position_x, &position_y, &movement);

    //Lê a matriz
    readMatrix(&matrix, dimension_n, dimension_m);

    //Exibe se o jogador escapou ou não
    printf("%s", (checkEscape(
                      &matrix, position_x, position_y, dimension_n, dimension_m, movement)
                      ? "Voce escapou!"
                      : "Game Over!"));

    //Libera a matriz
    freeMatrix(&matrix, dimension_n);

    return EXIT_SUCCESS;
}