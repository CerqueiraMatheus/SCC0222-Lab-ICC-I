#include <stdio.h>
#include <stdlib.h>

//Aloca os ponteiros da paleta
void initializePallete(int*** pallete) {
    (*pallete) = (int**)malloc(6 * sizeof(int*));
    for (int i = 0; i < 6; i++)
        (*pallete)[i] = (int*)malloc(3 * sizeof(int));
}

//Recebe as cores da paleta
void readPallete(int*** pallete) {
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &(*pallete)[i][j]);
}

//Mistura as cores da paleta
void mixColors(int*** pallete, int firstPosition, int secondPosition, int resultPosition) {
    int result;
    for (int i = 0; i < 3; i++) {
        /**
         * Se o resultado do componente soma da cor desejada
         * com a metade das mesclas for maior que 255,
         * assume 255. 
         * Caso contrário, assume o resultado
         * da operação.
         * */
        (*pallete)[resultPosition][i] =
            ((result =
                  (int)((*pallete)[firstPosition][i] / 2) + (int)((*pallete)[secondPosition][i] / 2) +
                  (*pallete)[resultPosition][i]) > 255)
                ? 255
                : result;
    }
}

//Exibe a paleta
void printPallete(int*** pallete) {
    for (int i = 0; i < 6; i++) {
        printf("Color(%d): [\t%d\t%d\t%d\t]\n",
               i,
               (*pallete)[i][0],
               (*pallete)[i][1],
               (*pallete)[i][2]);
    }
}

//Libera a paleta
void freePallete(int*** pallete) {
    for (int i = 0; i < 6; i++)
        free((*pallete)[i]);
    free(*pallete);
}

int main() {
    int firstColorPosition;
    int secondColorPosition;
    int resultColorPosition;
    int** pallete = NULL;

    initializePallete(&pallete);

    //Recebe as entradas
    scanf("%d", &firstColorPosition);
    scanf("%d", &secondColorPosition);
    scanf("%d", &resultColorPosition);
    readPallete(&pallete);

    //Exibe a paleta original
    printf("Start:\n");
    printPallete(&pallete);
    printf("\n");

    //Faz a mescla
    mixColors(&pallete, firstColorPosition, secondColorPosition, resultColorPosition);

    //Exibe a paleta modificada
    printf("Result:\n");
    printPallete(&pallete);

    //Libera a paleta
    freePallete(&pallete);

    return EXIT_SUCCESS;
}