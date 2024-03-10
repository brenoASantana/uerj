// Desenvolva um algoritmo que mostre as quatro operacoes matematicas basicas
// em dois valores definidos, sem utilizar scanf

#include <stdio.h>

int main()
{
    int n1 = 6;
    int n2 = 4;

    printf("N1: %d, N2: %d\n", n1, n2);
    printf("Soma: %d\n", (n1 + n2));
    printf("Diferenca: %d\n", (n1 - n2));
    printf("Produto: %d\n", (n1 * n2));
    printf("Quociente: %d\n", (n1 / n2));

    return 0;
}