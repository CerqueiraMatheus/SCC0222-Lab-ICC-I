#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define boolean int

/**
 * Para construção do exercício, considerei
 * nomes como arrays de strings, assim, com
 * cada nome, a construção se dá como abaixo
 * 
 *      Leonardo    Tortoro
 *      |string|    |string|
 *      |       nome       |
 * 
 * */
//Lê um grupo de nomes
void readNames(FILE *stream, char ****names, int *nameCounter, int **wordNameCounter) {
    //Operador de posição
    int charPosition = 0;

    //Operadores de controle
    boolean isWord = FALSE;
    boolean endWord = FALSE;
    boolean endName = FALSE;
    boolean endFile = FALSE;

    //Inicializa o contador de nomes
    (*nameCounter) = 0;

    //Percorre o arquivo
    do {
        //Realoca a matriz de nomes
        (*names) = (char ***)realloc((*names), ((*nameCounter) + 1) * sizeof(char **));
        (*wordNameCounter) = (int *)realloc((*wordNameCounter), ((*nameCounter) + 1) * sizeof(int));

        //Reseta o operador de nome
        endName = FALSE;

        //Zera o operador de contagem de palavras do nome
        (*wordNameCounter)[(*nameCounter)] = 0;

        (*names)[(*nameCounter)] = NULL;

        //Percorre o nome
        do {
            //Realoca as posições de um nome
            (*names)[(*nameCounter)] =
                (char **)realloc((*names)[*nameCounter],
                                 (((*wordNameCounter)[*nameCounter]) + 1) * sizeof(char *));

            //Reseta os operadores
            isWord = FALSE;
            endWord = FALSE;
            charPosition = 0;

            (*names)
                [(*nameCounter)]
                [(*wordNameCounter)[(*nameCounter)]] = NULL;
            //Percorre a palavra do nome
            do {
                //Atribui o char
                char auxChar = fgetc(stdin);

                //Realoca a palavra de um nome
                (*names)
                    [(*nameCounter)]
                    [(*wordNameCounter)[(*nameCounter)]] =
                        (char *)realloc(
                            (*names)[(*nameCounter)]
                                    [(*wordNameCounter)[(*nameCounter)]],
                            ++charPosition * sizeof(char));

                //Atribui um char à palavra do nome
                (*names)
                    [(*nameCounter)]
                    [(*wordNameCounter)[(*nameCounter)]]
                    [charPosition - 1] = auxChar;

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
                //seta o operador
                else
                    isWord = TRUE;
            } while (!endWord && !endName && !endFile);

            //Se o laço tiver sido executado numa palavra
            //seta o terminador de string e incrementa
            //a posição do contador de palavra
            if (isWord)
                (*names)
                    [(*nameCounter)]
                    [(*wordNameCounter)[(*nameCounter)]++]
                    [charPosition - 1] = '\0';

        } while (!endName && !endFile);
        //Incrementa o contador de nomes
        (*nameCounter)++;
    } while (!endFile);
}

//Troca os nomes de acordo com a lógica do exercício
void swapNames(char ***names, int nameCounter, int **wordNameCounter) {
    for (int i = 0, j = nameCounter - 1; i <= j; i++, j--) {
        //Adiciona o conteúdo da esquerda à string auxiliar
        char *auxString = malloc(strlen(names[i][(*wordNameCounter)[i] - 1]) + 1);
        strcpy(auxString, names[i][(*wordNameCounter)[i] - 1]);

        //Adiciona o conteúdo da direita à string da esquerda
        names[i][(*wordNameCounter)[i] - 1] = realloc(names[i][(*wordNameCounter)[i] - 1],
                                                      strlen(names[j][(*wordNameCounter)[j] - 1]) + 1);
        strcpy(names[i][(*wordNameCounter)[i] - 1], names[j][(*wordNameCounter)[j] - 1]);

        //Adiciona o conteúdo da auxiliar à string da direita
        names[j][(*wordNameCounter)[j] - 1] = realloc(names[j][(*wordNameCounter)[j] - 1],
                                                      strlen(auxString) + 1);
        strcpy(names[j][(*wordNameCounter)[j] - 1], auxString);

        //Libera a string auxiliar
        free(auxString);
    }
}

//Exibe um grupo de nomes
void printNames(char ***names, int nameCounter, int *wordNameCounter) {
    for (int i = 0; i < nameCounter; i++) {
        for (int j = 0; j < wordNameCounter[i]; j++) {
            printf("%s ", names[i][j]);
        }
        printf("\n");
    }
}

//Libera um grupo de nomes
void freeNames(char ****names, int nameCounter, int *wordNameCounter) {
    for (int i = 0; i < nameCounter; i++) {
        for (int j = 0; j < wordNameCounter[i]; j++)
            free((*names)[i][j]);
        free((*names)[i]);
    }
    free(*names);
}

int main() {
    char ***names = NULL;
    int nameCounter = 0;
    int *wordNameCounter = NULL;

    //Realiza as operações
    readNames(stdin, &names, &nameCounter, &wordNameCounter);
    swapNames(names, nameCounter, &wordNameCounter);
    printNames(names, nameCounter, wordNameCounter);

    //Libera os ponteiros
    freeNames(&names, nameCounter, wordNameCounter);
    free(wordNameCounter);

    return EXIT_SUCCESS;
}