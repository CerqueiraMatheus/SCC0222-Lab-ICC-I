#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;

    scanf ("%d %d %d", &a, &b, &c);

    if (
        ((pow(a, 2) == pow(b, 2) + pow(c, 2)) ||
        (pow(b, 2) == pow(c, 2) + pow(a, 2)) ||
        (pow(c, 2) == pow(b, 2) + pow(a, 2))) &&
        (a != 0 && b != 0 && c != 0)
    ) {
        printf("SIM");
    } else {
        printf("NAO");
    }
    return EXIT_SUCCESS;
}