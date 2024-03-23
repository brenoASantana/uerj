#include <stdio.h>
#define TAM 10
int main()
{
    float vetor[TAM];
    float vetorAoQuadrado[TAM];
    int i;
    for (i = 0; i < TAM; i++)
    {
        printf("Digite o numero %d: ", i + 1);
        scanf("%f", &vetor[i]);
        vetorAoQuadrado[i] = vetor[i] * vetor[i];
    }
    printf("\nVetor original: ");
    for (int i = 0; i < TAM; i++)
    {
        printf("%.2f ", vetor[i]);
    }
    printf("\nVetor ao quadrado: ");
    for (int i = 0; i < TAM; i++)
    {
        printf("%.2f ", vetorAoQuadrado[i]);
    }
    return 0;
}