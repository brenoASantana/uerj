// Colocar numeros de 1 a 5 no vetor

#include <stdio.h>

int main()
{
    int vetor[5];
    int i;

    for (i = 0; i < 5; i++)
    {
        vetor[i] = i+1;
        printf("%d\n", vetor[i]);
    }

    return 0;
}