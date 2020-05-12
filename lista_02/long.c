#include <stdio.h>
#include <stdlib.h>

int main(){

    //Declara e lê o long
    long numero;
    scanf("%ld", &numero);

    //Percorre de byte em byte
    for(int i = 0; i < 64; i+=8){

        //Shift 8 * i e deixa apenas o byte menos significante
        printf("%x\n", (int)(numero >> i & 0xFF));
    }

    return EXIT_SUCCESS;
}