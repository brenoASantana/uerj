// Escreva uma funcao que troque os valores de 2 variaveis usando ponteiros

#include <stdio.h>

void troca(int *n1, int *n2)
{
    int m;
    m = *n1;
    *n1 = *n2;
    *n2 = m;

    printf("Trocou!\n");
}

int main()
{
    int n1, n2;

    n1 = 5, n2 = 10;

    printf("N1: %d N2: %d \n", n1, n2);

    troca(&n1, &n2);

    printf("N1: %d N2: %d \n", n1, n2);

    return 0;
}