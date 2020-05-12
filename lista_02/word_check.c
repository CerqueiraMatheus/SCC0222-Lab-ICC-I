#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Retorna o char em minúscula
char get_lower(char c) {
    return (c > 64 && c < 91) ? (c + 32) : (c);
}

//Lê a String e retorna um ponteiro
char *read_string() {
    char *str, read[512];

    scanf(" %s", read);
    str = (char *)malloc(strlen(read + 1));

    for (int i = 0; read[i] != '\0'; i++) {
        str[i] = read[i];
    }

    return str;
}

//Organiza por ordem alfabética
int alpha_sort(char *s1, char *s2) {
    int i = 0;

    //Percorre as duas palavras e compara letra por letra
    for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (get_lower(s2[i]) > get_lower(s1[i])) {
            return 1;
        } else if (get_lower(s2[i]) < get_lower(s1[i])) {
            return 2;
        }
    }

    //Caso termine de percorrer e as duas sejam iguais,
    //retorna a menor String
    return (s1[i] == '\0' && (s2[i] == '\0')) ? 0
                                              : ((s1[i] == '\0') ? 1 : 2);
}

//Verifica a maior soma de letras
int bigger_sum(char *s1, char *s2) {
    int sum1 = 0, sum2 = 0;

    //Percorre até o final da maior palavra
    //get_lower(x) - 97 para chegar ao range de valores do exercício.
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        //Caso a letra da primeira palavra não seja nula,
        //soma o respectivo valor.
        if (((int)s1[i]) != 0) {
            sum1 += get_lower(s1[i]) - 97;
        }

        //Caso a letra da segunda palavra não seja nula,
        //soma o respectivo valor.
        if (((int)s2[i]) != 0) {
            sum2 += get_lower(s2[i]) - 97;
        }
    }

    //Se a soma da primeira for maior, retorna 1,
    //se da segunda, 2 e, se iguais, 0.
    return (sum1 > sum2) ? 1 : ((sum2 > sum1) ? 2 : 0);
}

//Verifica a palavra com maior ocorrência de uma letra
int most_app(char c, char *s1, char *s2) {
    int sum1 = 0, sum2 = 0;

    //Percorre até o final da maior palavra
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        //Caso a letra da primeira palavra não seja nula
        //e seja igual à letra, soma-se um.
        if (((int)s1[i]) != 0) {
            if (get_lower(s1[i]) == get_lower(c)) {
                sum1++;
            }
        }

        //Caso a letra da segunda palavra não seja nula
        //e seja igual à letra, soma-se um.
        if (((int)s2[i]) != 0) {
            if (get_lower(s2[i]) == get_lower(c)) {
                sum2++;
            }
        }
    }

    //Se a soma da primeira for maior, retorna 1,
    //se da segunda, 2 e, se iguais, 0.
    return ((sum1 > sum2) ? (1) : ((sum1 < sum2) ? 2 : 0));
}

//Verifica a palavra com primeira ocorrência de uma letra
int first_app(char c, char *s1, char *s2) {
    int aux;

    //Percorre até o final da maior palavra
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        aux = 0;

        //Caso a letra da primeira palavra não seja nula
        //e seja igual à letra, soma-se um ao aux.
        if (((int)s1[i]) != 0) {
            if (get_lower(s1[i]) == get_lower(c)) {
                aux += 1;
            }
        }

        //Caso a letra da segunda palavra não seja nula
        //e seja igual à letra, soma-se dois ao aux.
        if (((int)s2[i]) != 0) {
            if (get_lower(s2[i]) == get_lower(c)) {
                aux += 2;
            }
        }

        //Se aux = 3 (ocorrência na mesma posição), retorna 0
        //Caso contrário,retorna aux
        if (aux == 3) {
            return 0;
        } else if (aux != 0) {
            return aux;
        }
    }

    //Se não houver ocorrência, retorna 0.
    return 0;
}

int main() {
    int op;
    char letter;
    char **words;

    words = (char **)malloc(2 * sizeof(char *));

    scanf("%d", &op);

    //Leitura dos ponteiros
    words[0] = read_string();
    words[1] = read_string();

    //Executa a opção selecionada
    switch (op) {
        case 1:
            //Caso a palavra 1 seja maior, retorna 1
            //Caso 2, retorna 2
            //Se iguais, 0
            printf("%d", ((strlen(words[0]) > strlen(words[1])) ? 1 : ((strlen(words[0]) < strlen(words[1])) ? 2 : 0)));
            break;

        case 2:
            printf("%d", alpha_sort(words[0], words[1]));
            break;

        case 3:
            printf("%d", bigger_sum(words[0], words[1]));
            break;

        case 4:
            scanf(" %c", &letter);
            printf("%d", most_app(letter, words[0], words[1]));
            break;

        case 5:
            scanf(" %c", &letter);
            printf("%d", first_app(letter, words[0], words[1]));
            break;
    }

    //Libera o espaço dos ponteiros
    for (int i = 0; i < 2; i++) {
        free(words[i]);
    }
    free(words);

    return EXIT_SUCCESS;
}