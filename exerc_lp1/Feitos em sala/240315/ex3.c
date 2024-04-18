// Leia duas matrizes 3x3 e imprima a soma das duas.
#include <stdio.h>
int main()
{
    int matriz1[3][3];
    int matriz2[3][3];
    int i, j;

    printf("Matriz 1:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Informe o valor da posicao %d,%d:\n", i + 1, j + 1);
            scanf("%d", &matriz1[i][j]);
        }

        printf("\n");
    }

    printf("\nMatriz 2:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Informe o valor da posicao %d,%d:\n", i + 1, j + 1);
            scanf("%d", &matriz2[i][j]);
        }

        printf("\n");
    }

    printf("\nSoma:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", (matriz1[i][j] + matriz2[i][j]));
        }
        printf("\n");
    }

    return 0;
}