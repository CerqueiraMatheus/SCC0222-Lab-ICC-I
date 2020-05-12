#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    float primeiroTermo, quociente, totalTermos;

    scanf ("%f %f %f", &primeiroTermo, &quociente, &totalTermos);

    printf("%.2f\n", primeiroTermo * (pow(quociente, totalTermos - 1)));
    
    printf("%.2f\n", (primeiroTermo * (pow(quociente, totalTermos) - 1)) / (quociente - 1));

    return EXIT_SUCCESS;

}