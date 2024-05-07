#include <stdio.h>

#define TAMANHO_VETOR 20

// Função para preencher o vetor com valores inteiros
void preencherVetor(int vetor[])
{
    printf("Digite %d valores inteiros:\n", TAMANHO_VETOR);
    for (int i = 0; i < TAMANHO_VETOR; i++)
    {
        scanf("%d", &vetor[i]);
    }
}

// Função para realizar busca sequencial no vetor
int buscaSequencial(int vetor[], int tamanho, int valor)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] == valor)
        {
            return i; // Retorna a posição onde o valor foi encontrado
        }
    }
    return -1; // Retorna -1 se o valor não foi encontrado
}

int main()
{
    int vetor[TAMANHO_VETOR];
    int valorBusca, posicao;

    // Preencher o vetor com valores inteiros
    preencherVetor(vetor);

    // Pedir ao usuário o valor a ser buscado
    printf("\nDigite o valor a ser buscado: ");
    scanf("%d", &valorBusca);

    // Realizar busca sequencial
    posicao = buscaSequencial(vetor, TAMANHO_VETOR, valorBusca);

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
