// Preebcher matriz de 10 linhas e 10 (10x10) colunas com o numero 30
#include <stdio.h>
int main()
{
    int matriz[10][10];
    int i, j;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            matriz[i][j] = 30;
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}