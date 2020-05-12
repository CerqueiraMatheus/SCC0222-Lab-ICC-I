#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    double ponto[2], ponto_anterior[2], distancia_total;

    scanf("%d", &size);

    distancia_total = 0;

    for (int i = 0; i < size; i++) {
        scanf("%lf %lf", &ponto[0], &ponto[1]);

        if (i != 0) {
            distancia_total += sqrt(pow(ponto[0] - ponto_anterior[0], 2) +
                                    pow(ponto[1] - ponto_anterior[1], 2));
        }

        ponto_anterior[0] = ponto[0];
        ponto_anterior[1] = ponto[1];
    }

    printf("%.4lf", distancia_total);

    return EXIT_SUCCESS;

}