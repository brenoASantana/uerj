#include <stdio.h>

int multiplicar(int primeiroFator, int segundoFator)
{
    if (segundoFator == 1)
        return primeiroFator;

    return multiplicar(primeiroFator, segundoFator - 1) + primeiroFator;
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

    printf("\nResultado : %d", multiplicar(a, b));

    return 0;
}