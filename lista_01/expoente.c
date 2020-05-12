#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {

	float primeiro;
	float segundo;
	float resultado;

	scanf("%f", &primeiro);
	scanf("%f", &segundo);

	resultado = pow(primeiro, segundo);
	
	printf("%.4f", resultado);

	return EXIT_SUCCESS;

}