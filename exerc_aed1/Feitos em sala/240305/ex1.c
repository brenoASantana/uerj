// Modifique o exercicio anterior, sobre o fatorial, definindo uma
// funcao para o calculo do fatorial e fazendo uso dessa funcao
// para a solucao do exercicio

#include <stdio.h>
int fatorial(int num)
{
    int fat = 1;
    for (int i = num; i > 0; i--)
    {
        fat *= i;
    };
    return fat;
}

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
        do
        {
            printf("\nInforme o numero que deseja saber o fatorial: ");
            scanf("%d", &num);
        } while (num <= 0);

        printf("O fatorial de %d e %d\n", num, fatorial(num));
    };

    return 0;
}
