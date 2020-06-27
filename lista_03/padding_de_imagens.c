#include <stdio.h>
#include <stdlib.h>

//Lê todos os elementos da matriz como unsigned char
void readArray(unsigned char ***array, int height, int width) {
    (*array) = (unsigned char **)malloc(sizeof(unsigned char *) * height);

    for (int i = 0; i < height; i++) {
        (*array)[i] = (unsigned char *)malloc(sizeof(unsigned char) * width);

        for (int j = 0; j < width; j++) {
            scanf("%hhu", &(*array)[i][j]);
        }
    }
}

//Realiza o padding
unsigned char **doPadding(unsigned char ***originalArray, int height, int width, int padding) {
    unsigned char **array = NULL;

    //Reserva os elementos na memória referentes à nova matriz e o padding
    array = (unsigned char **)calloc((height + (padding * 2)), sizeof(unsigned char *));
    for (int i = 0; i < (height + padding * 2); i++)
        array[i] = (unsigned char *)calloc((width + (padding * 2)), sizeof(unsigned char));

    //Insere os elementos da matriz antiga com padding
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            array[i + padding][j + padding] = (*originalArray)[i][j];

    return array;
}

//Exibe e libera os ponteiros das imagens
void printAndFreeArrays(unsigned char ***originalArray, unsigned char ***paddedArray, int height, int width, int padding) {
    //Exibe e libera a imagem com padding
    for (int i = 0; i < (height + padding * 2); i++) {
        for (int j = 0; j < (width + padding * 2); j++) {
            printf("%d ", (*paddedArray)[i][j]);
        }
        printf("\n");
        free((*paddedArray)[i]);
    }
    free(*paddedArray);

    printf("\n");

    //Exibe e libera a imagem original
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", (*originalArray)[i][j]);
        }
        printf("\n");
        free((*originalArray)[i]);
    }
    free(*originalArray);
}

int main() {
    //Ponteiros de unsigned char (até 255)
    unsigned char **originalArray = NULL;
    unsigned char **paddedArray = NULL;

    //Atributos das imagens
    int height, width, padding;

    //Lê as entradas
    scanf("%d", &width);
    scanf("%d", &height);
    readArray(&originalArray, height, width);
    scanf("%d", &padding);

    //Faz o padding, exibe o resultado e libera os ponteiros
    paddedArray = doPadding(&originalArray, height, width, padding);
    printAndFreeArrays(&originalArray, &paddedArray, height, width, padding);

    return EXIT_SUCCESS;
}