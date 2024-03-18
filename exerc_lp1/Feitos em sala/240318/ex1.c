// Crie um alg em C que solicite ao usuario que insira um vetor de floats.
// Utilize alocacao dinamica de memoria p/ armazenar o vetor, calcule a media e imprima o resultado.

#include <stdio.h>
#define tam 2
float media(float *vetor)
{
    int i;
    float sum = 0;
    for (i = 0; i < tam; i++)
    {
        sum += vetor[i];
    }
    return (sum / tam);
}

int main()
{
    int i;
    float vetor[tam];

    for (i = 0; i < tam; i++)
    {
        printf("\nInforme um valor:\n");
        scanf("%f", &vetor[i]);
    }

    printf("Media: %.2f", media(&vetor));
    return 0;
}