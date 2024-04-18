// Leia os valores de uma matriz e imprima a diagonal principal
#include <stdio.h>
int main()
{
    int i, j;
    int matriz[3][3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Informe o valor da posicao %d,%d: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Loop para imprimir a matriz
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == j)
            {
                printf("%d ", matriz[i][j]);
            }
        }
    }

    return 0;
}