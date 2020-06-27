#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define boolean int
#define TRUE 1
#define FALSE 0

/**
 * Para tratar os grupos de quatro chars
 * como int, preferi usar uma union
 * */
typedef union {
    int number;
    char charArray[4];
} Data;

//Lê os dados até x
char *readCharArray(FILE *stream) {
    //Inicializa o operador
    boolean endLine = FALSE;

    //Inicializa o contador
    int pos = 0;

    //Inicializa o array
    char *charArray = NULL;

    do {
        //Recebe o char e apenas atribui se não for '\n' e '\r'
        char c = fgetc(stream);

        if (c != '\n' && c != '\r') {
            //Incrementa o array de char
            charArray =
                (char *)realloc(charArray, (pos + 2) * sizeof(char));

            //Recebe o char
            charArray[pos++] = c;

            //Se for x, termina a execução
            //e a string
            if (c == 'x') {
                endLine = TRUE;
                charArray[pos] = '\0';
            }
        }

        //Enquanto não for 'x'
    } while (!endLine);

    return charArray;
}

//Organiza os dados por Bubble Sort
void sortCharArray(char **charArray) {
    for (int i = 1; i < strlen(*charArray); i++) {
        for (int j = strlen(*charArray) - 1; j >= i; j--) {
            //Se A > B, invertem-se as posições
            if ((*charArray)[j - 1] > (*charArray)[j]) {
                int aux = (*charArray)[j - 1];
                (*charArray)[j - 1] = (*charArray)[j];
                (*charArray)[j] = aux;
            }
        }
    }
}

//Converte um array de char na union Data
void charArrayToData(char **charArray, Data ***dataArray, int *dataCounter) {
    //Vai de 4 em 4 posições (tamanho do int)
    for (int i = 0; i < strlen(*charArray); i += 4) {
        //Readapta o array de Data e aloca um item
        (*dataArray) = (Data **)realloc((*dataArray), ++(*dataCounter) * sizeof(Data *));
        (*dataArray)[(*dataCounter) - 1] = (Data *)malloc(sizeof(Data));

        //Insere os 4 chars na posição de Data
        int k = i;
        for (int j = 0; j < 4 && i < strlen(*charArray); j++, k++) {
            (*dataArray)[(*dataCounter) - 1]->charArray[j] = (*charArray)[k];
        }
    }
}

//Exibe os dados de array de data
void printData(Data **data, int dataCounter) {
    for (int i = 0; i < dataCounter; i++) {
        printf("%d\n", data[i]->number);
    }
}

//Libera o array de data
void freeDataArray(Data ***dataArray, int counter) {
    for (int i = 0; i < counter; i++) {
        free((*dataArray)[i]);
    }
    free(*dataArray);
}

int main() {
    Data **dataArray = NULL;
    char *charArray = NULL;
    int dataCounter = 0;

    //Lê o array
    charArray = readCharArray(stdin);

    //Organiza e converte em Data
    sortCharArray(&charArray);
    charArrayToData(&charArray, &dataArray, &dataCounter);
    printData(dataArray, dataCounter);

    //Libera os ponteiros
    freeDataArray(&dataArray, dataCounter);
    free(charArray);

    return EXIT_SUCCESS;
}