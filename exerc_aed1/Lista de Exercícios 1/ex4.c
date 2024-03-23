#include <stdio.h>
#define TAM 10

void leitura(int *vetor, int *somatorio)
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
        *somatorio += vetor[i];
    }
}

void impressao(int *vetor, int somatorio)
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        printf("Numero %d: %d\n", i + 1, vetor[i]);
    }
    printf("Somatorio: %d\n", somatorio);
}

int main()
{
    int vetor[TAM];
    int somatorio = 0;

    leitura(&vetor, &somatorio);
    impressao(&vetor, somatorio);

    return 0;
}