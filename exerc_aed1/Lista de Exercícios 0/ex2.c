#include <stdio.h>

int main()
{
    int a, b, c = 0;

    do
    {
        printf("Informe o valor de A: ");
        scanf("%d", &a);
    } while (a <= 0);

    do
    {
        printf("\nInforme o valor de B: ");
        scanf("%d", &b);
    } while (b <= 0);

    do
    {
        printf("\nInforme o valor de C: ");
        scanf("%d", &c);
    } while (c <= 0);
    if (a < (b + c))
    {
        if (b < (a + c))
        {
            if (c < (a + b))
            {
                printf("O perimetro do triangulo e: %f", (a + b + c));
                return 0;
            }
        }
    }
    printf("Os valores não formam um triangulo!");

    return 0;
}