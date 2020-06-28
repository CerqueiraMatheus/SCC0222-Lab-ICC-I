#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TERRA "Terra"
#define VENUS "Venus"
#define MERCURIO "Mercurio"
#define JUPITER "Jupiter"

//Razão entre o dia terráqueo e dos planetas
#define VENUS_TO_EARTH 24.0 / (243.0 * 24.0)
#define MERCURIO_TO_EARTH 24.0 / ((58.0 * 24.0) + 16.0)
#define JUPITER_TO_EARTH 24.0 / (9.0 + (56.0 / 60.0))

//Formato de dados desejado
#define timeType unsigned long long int

//Buffer para readLine
#define READLINE_BUFFER 2048

typedef struct {
    timeType days;
    timeType hours;
    timeType minutes;
    timeType seconds;
} Time;

//Função para ler linha
char *readLine(FILE *stream) {
    char *string = 0;
    int position = 0;

    do {
        if (position % READLINE_BUFFER == 0) {
            string =
                (char *)realloc(string, (position / READLINE_BUFFER + 1) * READLINE_BUFFER);
        }
        string[position++] = (char)fgetc(stream);
    } while (string[position - 1] != ' ' && string[position - 1] != '\n' && !feof(stream));

    string[position - 1] = '\0';
    string = (char *)realloc(string, position);

    return string;
}

//Converte os segundos para o tempo terráqueo
void convertSecondsToEarthTime(FILE *stream, timeType *seconds, char **planet, Time **time) {
    //Operadores auxiliares
    double ratio;
    double actualTime;

    (*seconds) = strtoull(readLine(stream), NULL, 10);
    (*planet) = readLine(stream);

    //Escolhe a razão de acordo com o planeta
    if (!strcmp((*planet), TERRA)) ratio = 1.0;
    if (!strcmp((*planet), VENUS)) ratio = VENUS_TO_EARTH;
    if (!strcmp((*planet), MERCURIO)) ratio = MERCURIO_TO_EARTH;
    if (!strcmp((*planet), JUPITER)) ratio = JUPITER_TO_EARTH;

    //Converte os segundos para
    //dias terráqueos
    actualTime = (((*seconds) * ratio) / 60.0 / 60.0) / 24.0;

    //Atribui as informações de tempo
    for (int i = 0; i < 4; i++) {
        switch (i) {
            case 0:
                (*time)->days = (int)floor(actualTime);
                break;

            case 1:
                (*time)->hours = (int)floor(actualTime);
                break;

            case 2:
                (*time)->minutes = (int)floor(actualTime);
                break;

            case 3:
                (*time)->seconds = (int)round(actualTime);
                break;
        }

        //Recalcula o tempo atual
        actualTime -= (int)(actualTime);

        //Recalcula o tempo para os dias
        //ou minutos ou segundos
        if (i == 0)
            actualTime *= 24 / ratio;
        else
            actualTime *= 60;
    }
}

int main() {
    timeType seconds;
    char *planet;

    //Inicializa a struct temporal
    Time *time = calloc(1, sizeof(Time));

    //Realiza as operações requisitadas
    convertSecondsToEarthTime(stdin, &seconds, &planet, &time);

    //Exibe os resultados obtidos
    printf("%llu segundos no planeta %s equivalem a:\n",
           seconds, planet);
    printf("%llu dias, %llu horas, %llu minutos e %llu segundos\n",
           time->days, time->hours, time->minutes, time->seconds);

    //Libera os ponteiros
    free(planet);
    free(time);

    return EXIT_SUCCESS;
}