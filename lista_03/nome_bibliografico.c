#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READLINE_BUFFER 2048
#define TRUE 1
#define FALSE 0
#define boolean int

//Checa se é fim de palavra
boolean isEndWord(char c) { return (c == ' '); }

//Checa se é fim de linha
boolean isEndLine(char c) { return (c == '\n' || c == '\r' || c == EOF); }

//Função para palavras de uma linha
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

int main() {
    char **wordArray = NULL;
    int wordCounter;

    readWordArray(stdin, &wordArray, &wordCounter);

    //Imprime o último nome, convertendo char por char para maiúsculas
    for (int i = 0; i < strlen(wordArray[wordCounter - 1]); i++) {
        printf("%c", toupper(wordArray[wordCounter - 1][i]));
    }
    free(wordArray[wordCounter - 1]);

    //Imprime os demais nomes precedidos por vírgula
    printf(", ");
    for (int i = 0; i < wordCounter - 1; i++) {
        printf("%s ", wordArray[i]);
        free(wordArray[i]);
    }

    //Libera o array
    free(wordArray);

    return EXIT_SUCCESS;
}