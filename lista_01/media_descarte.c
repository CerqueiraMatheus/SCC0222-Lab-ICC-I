#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {

	double numeros[4], menor, soma;

	scanf("%lf %lf %lf %lf", &numeros[0], &numeros[1], &numeros[2], &numeros[3]);

	for (int i = 0; i <= 3; i++) {
		if (i == 0) {
			menor = numeros[i];
		}
		else if (menor > numeros[i]) {
			menor = numeros[i];
		}
	}

	for (int i = 0; i <= 3; i++) {
		if (i == 0) {
			soma = numeros[i];
		}
		else {
			soma += numeros[i];
		}
	}

	printf("%.4lf", ((soma - menor) / 3));

	return EXIT_SUCCESS;

}