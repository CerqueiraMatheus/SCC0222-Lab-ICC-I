#include <stdio.h>
#include <stdlib.h>

//Lê o vetor de inteiros
void readArray(int **inputArray, int size) {
    (*inputArray) = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &(*inputArray)[i]);
    }
}

//Ordena o vetor de inteiros
void bubbleSort(int **inputArray, int size) {
    //Executa o bubble sort na lista
    for (int i = 1; i < size; i++) {
        for (int j = size - 1; j >= i; j--) {
            
            //Se o número anterior for maior que o atual
            //realiza a troca
            if ((*inputArray)[j - 1] > (*inputArray)[j]) {
                int aux = (*inputArray)[j - 1];
                (*inputArray)[j - 1] = (*inputArray)[j];
                (*inputArray)[j] = aux;
            }

        }
    }
}

//Busca um elemento num vetor de inteiros (retorna -1 se não encontrado)
int binarySearch(int **inputArray, int begin, int end, int value) {
    if(end >= begin){
        int middle = (begin + end) / 2;

        //Caso 1: valor encontrado
        if (value == (*inputArray)[middle]) return middle;

        //Caso 2: busca pela "direita"
        if (value > (*inputArray)[middle]){
            return binarySearch(inputArray, middle + 1, end, value);
        } else {
            //Caso 3: busca pela "esquerda"
            return binarySearch(inputArray, begin, middle - 1, value);
        }
    } else return -1; //Caso 4: valor não encontrado
}

int main() {
    int *inputArray = NULL, size, value, position;

    //Lê as entradas
    scanf("%d", &size);
    scanf("%d", &value);
    readArray(&inputArray, size);

    //Executa as operações requeridas
    bubbleSort(&inputArray, size);
    position = binarySearch(&inputArray, 0, size - 1, value);

    //Exibe o resultado
    if (position == -1) {
        printf("Chave inexistente\n");
    } else {
        printf("%d", position);
    }

    free(inputArray);

    return EXIT_SUCCESS;
}