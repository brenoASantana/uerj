#include <stdio.h>

#define TAMANHO_VETOR 20

// Função para preencher o vetor com valores inteiros de forma ordenada
void preencherVetorOrdenado(int vetor[])
{
    printf("Digite %d valores inteiros em ordem crescente:\n", TAMANHO_VETOR);
    for (int i = 0; i < TAMANHO_VETOR; i++)
    {
        scanf("%d", &vetor[i]);
    }
}

// Função para realizar busca binária no vetor ordenado
int buscaBinaria(int vetor[], int tamanho, int valor)
{
    int inicio = 0;
    int fim = tamanho - 1;
    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == valor)
        {
            return meio; // Retorna a posição onde o valor foi encontrado
        }
        else if (vetor[meio] < valor)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1; // Retorna -1 se o valor não foi encontrado
}

int main()
{
    int vetor[TAMANHO_VETOR];
    int valorBusca, posicao;

    // Preencher o vetor com valores inteiros em ordem crescente
    preencherVetorOrdenado(vetor);

    // Pedir ao usuário o valor a ser buscado
    printf("\nDigite o valor a ser buscado: ");
    scanf("%d", &valorBusca);

    // Realizar busca binária
    posicao = buscaBinaria(vetor, TAMANHO_VETOR, valorBusca);

    // Verificar se o valor foi encontrado
    if (posicao != -1)
    {
        printf("\nO valor %d foi encontrado na posição %d do vetor.\n", valorBusca, posicao);
    }
    else
    {
        printf("\nO valor %d não foi encontrado no vetor.\n", valorBusca);
    }

    return 0;
}
