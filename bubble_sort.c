#define DIM 5
#define FALSO 0
#define VERDADE 1
#include <stdio.h>
#include <conio.h>

int main(void)
{
    int vetor[DIM], i, trocou = FALSO, fim = DIM, temp;
    printf("Primeiro, entre com um vetor de %d elementos\n", DIM);

    for (i = 0; i < DIM; i++)
    {
        printf("Elemento %d - ", i);
        scanf("%d", &vetor[i]);
    }

    do
    {
        trocou = FALSO;
        for (i = 0; i < fim - 1; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                temp = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = temp;
                trocou = VERDADE;
            }
        }
        fim--;
    } while (trocou);

    for (i = 0; i < DIM; i++)
        printf("%d\n", vetor[i]);
    getch();

    return 0;
}