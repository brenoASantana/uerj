// Desenvolva um programa que confira se um numero e par ou impar

#include <stdio.h>

int main()
{
    int n;

    printf("Informe um numero:\n");
    scanf("%d", &n);

    if (n % 2 == 0)
    {
        printf("\nE par!");
    }
    else
    {
        printf("\nE impar!");
    }

    return 0;
}