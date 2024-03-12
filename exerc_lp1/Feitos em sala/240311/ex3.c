// Faca um programa que leia tres notas, diga qual a maior e a menor e a media das notas

#include <stdio.h>

int main()
{
    float n1, n2, n3;

    printf("Informe a nota 1:\n");
    scanf("%f", &n1);

    printf("Informe a nota 2:\n");
    scanf("%f", &n2);

    printf("Informe a nota 3:\n");
    scanf("%f", &n3);

    printf("\nMedia: %f\n", ((n1 + n2 + n3) / 3));

    if (n1 > n2 && n1 > n3)
    {
        if (n2 > n3)
        {
            printf("Maior: %f, Menor: %f", n1, n3);
        }
        else
        {
            printf("Maior: %f, Menor: %f", n1, n2);
        }
    }
    if (n2 > n1 && n2 > n3)
    {
        if (n1 > n3)
        {
            printf("Maior: %f, Menor: %f", n2, n3);
        }
        else
        {
            printf("Maior: %f, Menor: %f", n1, n1);
        }
    }
    else
    {
        if (n3 > n1 && n3 > n2)
        {
            if (n1 > n2)
            {
                printf("Maior: %f, Menor: %f", n3, n2);
            }
            else
            {
                printf("Maior: %f, Menor: %f", n3, n2);
            }
        }
    }

    return 0;
}