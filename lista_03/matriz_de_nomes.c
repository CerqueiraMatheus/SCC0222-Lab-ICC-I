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
void readNames(FILE *stream, char ***names) {
    //Operadores de posição
    int namePosition = 0;
    int charPosition = 0;

    //Operadores de controle
    boolean isWord = FALSE;
    boolean endLine = FALSE;
    boolean endFile = FALSE;

    //Aloca as 5 posições previstas
    (*names) = (char **)calloc(5, sizeof(char *));

    //Percorre o arquivo
    do {
        //Reseta os operadores
        isWord = FALSE;
        endLine = FALSE;
        charPosition = 0;

        //Percorre a linha
        do {
            //Atribui o char
            char auxChar = fgetc(stdin);

            //Verifica se o char é fim de linha
            if (auxChar == '\n' || auxChar == '\r')
                endLine = TRUE;

            //Verifica se o char é fim de arquivo
            else if (auxChar == EOF)
                endFile = TRUE;

            //Caso for parte de um nome,
            //seta o operador e atribui
            else {
                isWord = TRUE;

                (*names)[(namePosition)] =
                    (char *)realloc((*names)[namePosition],
                                    (namePosition + 1) * sizeof(char));

                (*names)[namePosition][charPosition++] = auxChar;
            }
        } while (!endLine && !endFile);

        //Se o laço tiver sido executado numa palavra
        //seta o terminador de string e incrementa
        //a posição
        if (isWord) {
            (*names)[namePosition][charPosition] = '\0';
            namePosition++;
        }

    } while (!endFile);
}

//Organiza um grupo de nomes
void sortWordNames(char ***names) {
    //Percorre os nomes
    for (int i = 1; i < 5; i++) {
        for (int j = 5 - 1; j >= i; j--) {
            //Se o nome anterior for "maior" que o atual
            if (compairStrings(
                    (*names)[j - 1],
                    (*names)[j])) {
                char *aux = (*names)[j - 1];
                (*names)[j - 1] = (*names)[j];
                (*names)[j] = aux;
            }
        }
    }
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
    char **names = NULL;

    //Realiza as operações
    readNames(stdin, &names);
    sortWordNames(&names);
    printNames(&names);

    //Libera a matriz
    freeNames(&names);

    return EXIT_SUCCESS;
}