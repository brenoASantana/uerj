// Escreva um algoritmo em C que recebe um número real do usuário e armazena esse número em uma variável do tipo float usando um ponteiro.
// Em seguida, o programa deve imprimir o valor inserido pelo usuário.

#include <stdio.h>

int main()
{
    float n;
    float *p_n;

    p_n = &n;

    printf("Digite um numero real: ");
    scanf("%f", p_n);

    printf("O numero digitado foi: %.2f\n", n);
    return 0;
}
