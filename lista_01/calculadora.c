#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    double a, b;
    char operador;

    scanf("%lf %c %lf", &a, &operador, &b);

    switch (operador) {
        case '+':
            printf("%.6lf", a + b);
            break;

        case '-':
            printf("%.6lf", a - b);
            break;

        case '/':
            printf("%.6lf", a / b);
            break;

        case '*':
            printf("%.6lf", a * b);
            break;

        case '%':
            printf("%.6lf", (a * 100) / b);
            break;

        default:
            printf("não consegui comparar :(");
            break;
    }
    return EXIT_SUCCESS;
}