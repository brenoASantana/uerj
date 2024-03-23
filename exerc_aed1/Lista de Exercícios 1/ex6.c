#include <stdio.h>

int multiplicar(float primeiroFator, float segundoFator)
{   
    if
    return multiplicar();

    float produto = 0.0;
    for (int i = 0; i < segundoFator; i++)
    {
        produto += primeiroFator;
    }
    return produto;
}

int main()
{
    int a, b = 0;

    do
    {
        printf("Informe o valor de A: ");
        scanf("%d", &a);
    } while (a < 0);

    do
    {
        printf("\nInforme o valor de B: ");
        scanf("%d", &b);
    } while (b < 0);

    printf("znResultado : %.2f", multiplicar(a, b));

    return 0;
}