#include <stdio.h>

float multiplicar(float primeiroFator, float segundoFator)
{
    float produto = 0.0;
    for (int i = 0; i < segundoFator; i++)
    {
        produto += primeiroFator;
        }
    return produto;
}

int main()
{
    float primeiroFator, segundoFator = 0.0;

    printf("Informe o valor do primeiro fator: ");
    scanf("%f", &primeiroFator);

    printf("Informe o valor do segundo fator: ");
    scanf("%f", &segundoFator);

    printf("O produto dos fatores : %.2f", multiplicar(primeiroFator, segundoFator));

    return 0;
}