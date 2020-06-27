#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define boolean int

//Retorna o char em minúscula
char getLower(char c) {
    return (c > 64 && c < 91) ? (c + 32) : (c);
}

//Verifica duas strings alfabeticamente
boolean compairStrings(char *s1, char *s2) {
    int i = 0;

    //Percorre as duas palavras e compara letra por letra
    for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (getLower(s2[i]) > getLower(s1[i])) {
            return FALSE;
        } else if (getLower(s2[i]) < getLower(s1[i])) {
            return TRUE;
        }
    }

    //Caso termine de percorrer e as duas sejam iguais,
    //retorna a menor String
    return (s1[i] == '\0' && (s2[i] == '\0')) ? FALSE
                                              : ((s1[i] == '\0') ? FALSE : TRUE);
}

//Lê um grupo de nomes
void readNames(FILE *stream, char ****names, int *namePosition, int **wordPosition) {
    //Operadores de posição
    int namePosition = 0;
    int wordPosition = 0;
    int charPosition = 0;

    //Operadores de controle
    boolean isWord = FALSE;
    boolean endWord = FALSE;
    boolean endName = FALSE;
    boolean endFile = FALSE;

    //Percorre o arquivo
    do {
        //Realoca a matriz de nomes
        (*names) = (char ***)realloc((*names), ((*namePosition) + 1) * sizeof(char **));

        //Reseta o operador de nome
        endName = FALSE;

        //Percorre o nome
        do {
            //Realoca as posições de um nome
            (*names)[(*namePosition)] =
                (char **)realloc((*names)[*namePosition],
                                 ((*wordPosition)[*namePosition] + 1) * sizeof(char *));

            //Reseta os operadores
            isWord = FALSE;
            endWord = FALSE;
            charPosition = 0;

            //Percorre a palavra do nome
            do {
                //Atribui o char
                char auxChar = fgetc(stdin);

                //Verifica se o char é fim de palavra
                if (auxChar == ' ')
                    endWord = TRUE;

                //Verifica se o char é fim de nome
                else if (auxChar == '\n' || auxChar == '\r')
                    endName = TRUE;

                //Verifica se o char é fim de arquivo
                else if (auxChar == '$')
                    endFile = TRUE;

                //Caso for parte de um nome,
                //seta o operador e atribui
                else {
                    isWord = TRUE;

                    (*names)[(*namePosition)][(*wordPosition)[(*namePosition)]] =
                        (char *)realloc((*names)[(*namePosition)][(*wordPosition)[(*namePosition)]],
                                        ((*wordPosition)[(*namePosition)] + 1) * sizeof(char));

                    (*names)[(*namePosition)][(*wordPosition)[(*namePosition)]++] = auxChar;
                }
            } while (!endWord && !endFile && !endFile);
            //Se o laço tiver sido executado numa palavra
            //seta o terminador de string e incrementa
            //a posição
            if (isWord) {
                (*names)[(*namePosition)][(*wordPosition)[(*namePosition)]] = '\0';
                (*namePosition)++;
            }
        } while (!endName && !endFile);
    } while (!endFile);
}

//Exibe um grupo de nomes
void printNames(char ***names) {
    for (int i = 0; i < 5; i++) {
        printf("%s\n", (*names)[i]);
    }
}

//Libera um grupo de nomes
void freeNames(char ***names) {
    for (int i = 0; i < 5; i++) {
        free((*names)[i]);
    }
    free((*names));
}

int main() {
    //Matriz de char para
    //nomes
    char ***names = NULL;
    int namePosition = 0;
    int *wordPosition = NULL;

    //Realiza as operações
    readNames(stdin, &names, &namePosition, &wordPosition);
    //printNames(&names);

    //Libera a matriz
    //freeNames(&names);

    return EXIT_SUCCESS;
}