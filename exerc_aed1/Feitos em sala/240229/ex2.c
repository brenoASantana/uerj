// Faça um programa em C que leia um número N, que indique quantos números inteiros devem ser lidos.
// Para cada número lido, apresente uma relação contendo o valor e o fatorial desse valor.

#include <stdio.h>

int main()
{
    int x, y;
    printf("Quantos numeros: ");
    scanf("%d", &x);

    for (int z = 0; z < x; z++)
    {
        int soma = 1;
        printf("\nDigite um número: ");
        scanf("%d", &y);
        for (int i = y; i > 0; i--)
        {
            soma *= i;
        };
        printf("O fatorial de %d é %d\n", y, soma);
    };

    return 0;
}
