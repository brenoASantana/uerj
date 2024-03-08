#include <stdio.h>
#define n_notas 10

int main()
{
    float A[n_notas], s;
    int i;
    for (i = 0; i < n_notas; i++)
    {
        printf("\nInforme a %d nota: ", (i + 1));
        scanf("%d", &A[i]);
    }
    printf("\nInforme o numero que deseja procurar: ");
    scanf("%f", s);

    for (i = 0; i < n_notas; i++)
    {
        if (A[i] == s)
        {
            printf("Achei!");
            break;
        }
        if (i == (n_notas - 1))
        {
            printf("Nao achei");
        }
    }
    return 0;
}