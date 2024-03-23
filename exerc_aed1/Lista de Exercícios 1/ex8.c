#include <stdio.h>
#define TAM 10

int main()
{
    int vetor[TAM], vetorFat[TAM];
    int i;

    for (i = 0; i < TAM; i++)
    {
        printf("Digite o valor para a posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < TAM; i++)
    {
        vetorFat[i] = 1;
        for (int j = 1; j <= vetor[i]; j++)
        {
            vetorFat[i] *= j;
        }
    }

    for (i = 0; i < TAM; i++)
    {
        printf("Fatorial de %d: %d\n", vetor[i], vetorFat[i]);
    }

    return 0;
}