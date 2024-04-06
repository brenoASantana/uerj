// Escreva uma funcao que troque os valores de 2 variaveis usando ponteiros

#include <stdio.h>

void troca(int *n1, int *n2)
{
    printf("Trocou!\n");

    int m;
    m = *n1;
    *n1 = *n2;
    *n2 = m;
}

int main()
{
    int n1, n2;

    printf("Informe o primerio valor\n");
    scanf("%d", &n1);

    printf("Informe o segundo valor\n");
    scanf("%d", &n2);

    printf("N1: %d N2: %d \n", n1, n2);

    troca(&n1, &n2);

    printf("N1: %d N2: %d \n", n1, n2);

    return 0;
}