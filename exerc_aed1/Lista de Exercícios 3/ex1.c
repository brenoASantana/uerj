#include <stdio.h>
#define MAX 20

int buscaSeq(int chave, int vetor[])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (vetor[i] == chave)
            return i;
    }
    // Se nao achar, retorna -1 que representa que o valor nao esta no vetor
    return -1;
}

int main()
{
    int chave;
    int vetor[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,12,13,14,15,16,17,18,19,20};

    printf("Informe o valor a ser procurado:");
    scanf("%d", &chave);

    int result = buscaSeq(chave, vetor);

    if (result == -1)
        printf("\n Valor nao encontrado.");
    else
        printf("Valor na posicao %d", result + 1);

    return 0;
}