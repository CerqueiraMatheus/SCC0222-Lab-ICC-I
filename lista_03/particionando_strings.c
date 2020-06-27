#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define READLINE_BUFFER 2048
#define TRUE 1
#define FALSE 0
#define boolean int

//Retorna o char em minúscula
//e modifica o char original
char getLower(char *c) {
    if (*c > 64 && *c < 91) *c = (*c + 32);
    return (*c);
}

/**
 * Compara duas palavras
 * Se s1 > s2,  TRUE
 *    s2 > s1,  FALSE
*/
boolean compairStrings(char *s1, char *s2) {
    int i = 0;

    //Percorre as duas palavras e compara letra por letra
    for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (getLower(&s2[i]) > getLower(&s1[i])) {
            return FALSE;
        } else if (getLower(&s2[i]) < getLower(&s1[i])) {
            return TRUE;
        }
    }

    //Caso termine de percorrer e as duas sejam iguais,
    //retorna a menor String
    return (s1[i] == '\0' && (s2[i] == '\0')) ? FALSE
                                              : ((s1[i] == '\0') ? FALSE : TRUE);
}

//Checa se é fim de palavra
boolean isEndWord(char c) { return (c == ' '); }

//Checa se é fim de linha
boolean isEndLine(char c) { return (c == '\n' || c == '\r' || c == EOF); }

//Lê palavras de uma linha
void readWordArray(FILE *stream, char ***wordArray, int *wordCounter) {
    boolean endWord = FALSE;
    boolean endLine = FALSE;
    char *string = NULL;

    //Laço para percorrer a linha
    do {
        //Reset dos operadores
        char *string = NULL;
        int position = 0;
        endWord = FALSE;

        //Laço para percorrer a palavra
        do {
            if (position % READLINE_BUFFER == 0) {
                string =
                    (char *)realloc(string, (position / READLINE_BUFFER + 1) * READLINE_BUFFER);
            }
            string[position] = (char)fgetc(stream);

            char aux = string[position++];

            //Testa os operadores de fim de linha e palavra
            if (isEndWord(aux)) {
                endWord = TRUE;
            } else if (isEndLine(aux)) {
                endLine = TRUE;
            }

        } while (!endWord && !endLine);

        //Coloca o terminador de string
        string[position - 1] = '\0';
        string = (char *)realloc(string, position);

        //Atribui uma posição para o vetor de palavras
        (*wordArray) = (char **)realloc((*wordArray), ((++(*wordCounter)) * sizeof(char *)));
        (*wordArray)[(*wordCounter) - 1] = string;

    } while (!endLine);

    //Libera a string auxiliar
    free(string);
}

//Ordena o vetor de char
void bubbleSort(char ***inputArray, int size) {
    //Executa o bubble sort na lista
    for (int i = 1; i < size; i++) {
        for (int j = size - 1; j >= i; j--) {
            //Se a palavra anterior for "maior" que o atual
            //realiza a troca
            if (compairStrings((*inputArray)[j - 1], (*inputArray)[j])) {
                char *aux = (*inputArray)[j - 1];
                (*inputArray)[j - 1] = (*inputArray)[j];
                (*inputArray)[j] = aux;
            }
        }
    }
}

//Exibe e libera todos os elementos de um array
void printAndFreeWordArray(char ***wordArray, int wordCounter) {
    for (int i = 0; i < wordCounter; i++) {
        printf("%s\n", (*wordArray)[i]);
        free((*wordArray)[i]);
    }
    free(*wordArray);
}

int main() {
    char **wordArray = NULL;
    int wordCounter = 0, opt;

    //Lê as entradas
    readWordArray(stdin, &wordArray, &wordCounter);
    scanf("%d", &opt);

    //Executa a opção selecionada
    switch (opt) {
        case 1:
            printAndFreeWordArray(&wordArray, wordCounter);
            break;

        case 2:
            bubbleSort(&wordArray, wordCounter);
            printAndFreeWordArray(&wordArray, wordCounter);
    }

    return EXIT_SUCCESS;
}