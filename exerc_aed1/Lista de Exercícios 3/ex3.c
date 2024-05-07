#include <stdio.h>

// Função recursiva para busca binária em um vetor ordenado
int buscaBinariaRecursiva(int vetor[], int inicio, int fim, int valor)
{
    if (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == valor)
        {
            return meio; // Retorna a posição onde o valor foi encontrado
        }
        else if (vetor[meio] < valor)
        {
            return buscaBinariaRecursiva(vetor, meio + 1, fim, valor);
        }
        else
        {
            return buscaBinariaRecursiva(vetor, inicio, meio - 1, valor);
        }
    }
    return -1; // Retorna -1 se o valor não foi encontrado
}

int main()
{
    int vetor[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valorBusca, posicao;

    // Pedir ao usuário o valor a ser buscado
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valorBusca);

    // Realizar busca binária recursiva
    posicao = buscaBinariaRecursiva(vetor, 0, tamanho - 1, valorBusca);

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
