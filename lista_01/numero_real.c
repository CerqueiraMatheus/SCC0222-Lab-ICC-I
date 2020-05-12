#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {

	double numero;

	scanf("%lf", &numero);

	printf("%d\n%.4lf\n%.0lf",  abs(numero), (numero - floor(numero)), round(numero));

	return EXIT_SUCCESS;

}