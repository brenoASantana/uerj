// Faca um programa que informe o maior e o menor valor entre x e y
#include <stdio.h>

int main()
{
    float x, y;
    printf("Informe o valor de X:\n");
    scanf("%f", &x);
    printf("\nInforme o valor de Y:\n");
    scanf("%f", &y);

    if (x > y)
    {
        printf("Maior: %f, Menor: %f", x, y);
    }
    else
    {
        if (y > x)
        {
            printf("Maior: %f, Menor: %f", y, x);
        }
        else
        {
            printf("Os valores sao iguais!");
        }
    }

    return 0;
}