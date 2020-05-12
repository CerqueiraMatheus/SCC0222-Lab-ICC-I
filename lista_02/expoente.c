#include <stdio.h>
#include <stdlib.h>

int main() {
    int exp;
    double n, s;

    //Recebe os números
    scanf("%lf %d", &n, &exp);

    if (exp > 0) { //Expoente maior que 0
        s = n;
    } else if (exp < 0) { //Expoente menor que 0
        n = 1 / n; //Inverso de n
        s = n;
        exp *= -1; //Torna exp positivo
    } else if (exp == 0) { //Expoente igual a 0
        if (n != 0) {
            s = 1; //Saída 1
        }
    }

    //Executa as repetições para potenciação
    for (int i = 1; i < exp; i++) s *= n;

    //Retorna os números
    printf("%.4lf", s);

    return EXIT_SUCCESS;
}