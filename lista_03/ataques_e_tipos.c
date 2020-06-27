#include <stdio.h>
#include <stdlib.h>

//Struct para ataques
struct {
    int power;
    int type;
} typedef Attack;

//Lê a matriz do jogo
void readMatrix(float ***matrix, int matrixSize) {
    //Percorre as linhas
    for (int i = 0; i < matrixSize; i++) {
        //Realoca a matriz
        (*matrix) = (float **)realloc((*matrix), sizeof(float *) * (i + 1));

        //Inicializa a linha
        (*matrix)[i] = NULL;

        //Percorre as colunas
        for (int j = 0; j < matrixSize; j++) {
            //Realoca a linha da matriz
            (*matrix)[i] = (float *)realloc(((*matrix)[i]), sizeof(float) * (j + 1));

            //Recebe o valor
            scanf("%f", &(*matrix)[i][j]);
        }
    }
}

//Lê um conjunto de ataques
void readAttacks(Attack ***attacks, int *attacksSize) {
    //Auxiliar de armazenamento
    int aux = 0;

    //Inicializa o contador de ataques
    (*attacksSize) = 0;

    //Enquanto for != -1
    do {
        //Recebe o primeiro número
        scanf("%d", &aux);

        if (aux != -1) {
            //Aloca um ataque
            (*attacks) = (Attack **)realloc((*attacks), ((*attacksSize) + 1) * sizeof(Attack *));
            (*attacks)[(*attacksSize)] = (Attack *)calloc(1, sizeof(Attack));

            //Preenche o ataque
            (*attacks)[(*attacksSize)]->power = aux;
            scanf("%d", &(*attacks)[(*attacksSize)]->type);

            //Incrementa o operador
            (*attacksSize)++;
        }

    } while (aux != -1);
}

//Escolhe o melhor ataque
void chooseAttack(float ***matrix, Attack ***attacks, int attacksSize, int enemyAttack, float *damage, int *index) {
    //Inicia o dano
    (*damage) = 0.0;

    //Percorre o array de ataques
    for (int i = 0; i < attacksSize; i++) {
        //Atribui o dano do ataque atual
        float actualDamage =
            (*matrix)[(*attacks)[i]->type][enemyAttack] * (*attacks)[i]->power;

        //Se o dano atribuído for maior,
        //atribui os novos elementos
        if (actualDamage > (*damage)) {
            (*damage) = actualDamage;
            (*index) = i;
        }
    }
}

//Libera a matriz
void freeMatrix(float ***matrix, int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        free((*matrix)[i]);
    }
    free((*matrix));
}

//Libera o conjunto de ataques
void freeAttacks(Attack ***attacks, int attacksSize) {
    for (int i = 0; i < attacksSize; i++) {
        free((*attacks)[i]);
    }
    free((*attacks));
}

int main() {
    //Componentes da matriz
    int matrixSize;
    float **matrix = NULL;

    //Componentes do grupo de ataques
    int attacksSize = 0;
    Attack **attacks = NULL;

    //Ataque inimigo
    int enemyAttack;

    //Resultados do melhor ataque
    float bestAttackDamage;
    int bestAttackIndex;

    //Lê as entradas
    scanf("%d", &matrixSize);
    readMatrix(&matrix, matrixSize);
    readAttacks(&attacks, &attacksSize);
    scanf("%d", &enemyAttack);

    //Escolhe o melhor ataque
    chooseAttack(&matrix,
                 &attacks, attacksSize,
                 enemyAttack, &bestAttackDamage, &bestAttackIndex);

    //Exibe os dados do melhor ataque
    printf("O melhor ataque possui indice %d e dano %.2f\n",
           bestAttackIndex,
           bestAttackDamage);

    //Libera os dados armazenados
    freeMatrix(&matrix, matrixSize);
    freeAttacks(&attacks, attacksSize);

    return EXIT_SUCCESS;
}