#include <stdio.h>

#define TAM 10
int main()
{
    int vetor[10];
    int i;
    int maior = 0;

    for (i = 0; i < TAM; i++)
    {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
    }
    printf("\nVetor: ");
    
    for (int i = 0; i < TAM; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\nMaior valor: %d", maior);

    return 0;
}