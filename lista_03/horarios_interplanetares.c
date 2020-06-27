#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TERRA "Terra"
#define VENUS "Venus"
#define MERCURIO "Mercurio"
#define JUPITER "Jupiter"

//Dia terráqueo em segundos
#define TERRA_TO_MINUTES (24 * 60)

//Razão entre o dia terráqueo e dos planetas em segundos
#define VENUS_TO_TERRA_MINUTES (TERRA_TO_MINUTES / (243 * 24 * 60))
#define MERCURIO_TO_TERRA_MINUTES (TERRA_TO_MINUTES / ((58 * 24) + 16) * 60)
#define JUPITER_TO_TERRA_MINUTES (TERRA_TO_MINUTES / ((9 * 60) + 56))

typedef struct {
    int days;
    int hours;
    int minutes;
    int seconds;
} Time;

void readEntry(FILE *stream, int *seconds, char **planet) {
}

void convertSecondsToEarthTime(int seconds, char *planet, Time **time) {
    //Operadores auxiliares
    double ratio;
    double actualTime;

    //Inicializa a struct temporal
    (*time) = (Time *)calloc(1, sizeof(Time));

    //Escolhe a razão de acordo com o planeta
    if (planet == TERRA) ratio = 1.0;
    if (planet == VENUS) ratio = VENUS_TO_TERRA_MINUTES;
    if (planet == MERCURIO) ratio = MERCURIO_TO_TERRA_MINUTES;
    if (planet == JUPITER) ratio = JUPITER_TO_TERRA_MINUTES;

    //Converte os segundos para
    //segundos terráqueos
    actualTime = (seconds / 60) * ratio;

    printf("%lf\n", actualTime);

    //Converte os segundos para dias em float
    actualTime /= 24;

    //Atribui as informações de tempo
    for (int i = 0; i < 4; i++) {
        switch (i) {
            case 0:
                (*time)->days = (int)floor(actualTime);
                printf("DAYS %d\n", (*time)->days);
                break;

            case 1:
                (*time)->hours = (int)floor(actualTime);
                printf("HOURS %d\n", (*time)->hours);
                break;

            case 2:
                (*time)->minutes = (int)floor(actualTime);
                printf("MINUTES %d\n", (*time)->minutes);
                break;

            case 3:
                (*time)->seconds = (int)floor(actualTime);
                printf("SECONDS %d\n", (*time)->seconds);
                break;
        }

        //Recalcula o tempo atual
        actualTime -= (int)floor(actualTime);
        if (i == 0)
            actualTime = actualTime * 24;
        else
            actualTime = actualTime * 60;
    }
}

int main() {
    int seconds;
    char *planet;
    Time *time = NULL;

    convertSecondsToEarthTime(2, "Terra", &time);

    return EXIT_SUCCESS;
}