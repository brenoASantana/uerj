// Faca um programa que leia um numero digitado e diga qual o dia da semana correspondente

#include <stdio.h>

int main()
{
    int n;

    printf("Informe um numero:\n");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        printf("\nDomingo!");
        break;
    case 2:
        printf("\nSegunda-Feira!");
        break;
    case 3:
        printf("\nTerca-Feira!");
        break;
    case 4:
        printf("\nQuarta-Feira!");
        break;
    case 5:
        printf("\nQuinta-Feira!");
        break;
    case 6:
        printf("\nSexta-Feira!");
        break;
    case 7:
        printf("\nSabado!");
        break;
    default:
        printf("\nNumero digitado sem dia da semana correspondente!");
        break;
    }

    return 0;
}