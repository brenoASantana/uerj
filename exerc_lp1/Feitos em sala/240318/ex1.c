// Crie um alg em C que solicite ao usuario que insira um vetor de floats
// Utilize alocacao dinamica de memoria p/ armazenar o vetor, calcule a media e imprima o resultado

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho;
    float *vetor;
    float soma = 0.0;
    float media;

    // Solicita ao usuário o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // Aloca memória dinamicamente para o vetor
    vetor = (float *)malloc(tamanho * sizeof(float));

    // Verifica se a alocação de memória foi bem sucedida
    if (vetor == NULL)
    {
        printf("Erro de alocação de memória.");
        return 1;
    }

    // Solicita ao usuário que insira os elementos do vetor
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%f", &vetor[i]);
        soma += vetor[i];
    }

    // Calcula a média
    media = soma / tamanho;

    // Imprime o resultado
    printf("A média dos elementos do vetor é: %.2f\n", media);

    // Libera a memória alocada para o vetor
    free(vetor);

    return 0;
}
