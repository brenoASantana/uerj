// Faça um programa em C que leia um número N, que indique quantos números inteiros devem ser lidos.
// Para cada número lido, apresente uma relação contendo o valor e o fatorial desse valor.

#include <stdio.h>

int main()
{
    int quant, num = 0;
    do
    {
        printf("Informe a quantidade de numeros que deseja saber o fatorial: ");
        scanf("%d", &quant);
    } while (quant <= 0);

    for (int i = 0; i < quant; i++)
    {
        int fat = 1;
        do
        {
            printf("\nInforme o numero que deseja saber o fatorial: ");
            scanf("%d", &num);
        } while (num <= 0);

        for (int j = num; j > 0; j--)
        {
            fat *= j;
        };
        printf("O fatorial de %d e %d\n", num, fat);
    };

    return 0;
}
