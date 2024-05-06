// Escreva um algoritmo em C que recebe uma lista de números inteiros do usuário e armazena esses números em um vetor dinâmico usando alocação de memória.
// Em seguida, o programa deve imprimir os números inseridos pelo usuário.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, quant;

    do
    {
        printf("Insira a quantidade positiva de numeros que deseja inserir: ");
        scanf("%d", &quant);
    } while (quant <= 0);

    int *vetor = (int *)malloc(quant * sizeof(int));

    // Verificação da alocação de memória
    if (vetor == NULL)
    {
        printf("Erro ao alocar memória.");
        return 1;
    }

    for (i = 0; i < quant; i++)
    {
        printf("\nInforme o valor desejado na posicao %d do vetor:", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor:");
    for (i = 0; i < quant; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);

    return 0;
}
