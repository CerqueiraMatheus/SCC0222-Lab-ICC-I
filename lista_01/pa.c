#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    long long int primeiroTermo, razao, totalTermos;

    scanf("%lld %lld %lld", &primeiroTermo, &razao, &totalTermos);

    printf("%lld\n", primeiroTermo + (totalTermos - 1) * razao);

    printf("%lld\n",
           (totalTermos *
            (primeiroTermo + (primeiroTermo + (totalTermos - 1) * razao)) / 2));

    return EXIT_SUCCESS;
}