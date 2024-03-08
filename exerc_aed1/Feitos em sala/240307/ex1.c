#include <stdio.h>
#define num 15

int main()
{

    int vet[num];

    int max, min, p_max, p_min, i;

    for (i = 0; i < num; i++)
    {
        printf("\nInforme o %d numero: ");
        scanf("%d", &vet[i]);

        if (i == 0)
        {
            max, min = vet[i];
        }

        if (max < vet[i])
        {
            max = vet[i];
            p_max = i;
        }

        if (min > vet[i])
        {
            min = vet[i];
            p_min = i;
        }
    }
    printf("Maior numero: %d. Menor numero: %d. Difereca: %d", max, min, (vet[p_max] - vet[p_min]));

    return 0;
}