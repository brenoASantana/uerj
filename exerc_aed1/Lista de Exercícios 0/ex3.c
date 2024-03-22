#include <stdio.h>

int main()
{
    int op, turn, sum, sumPar, turnPar, mediaPar = 0;
    int n;

    while (op == 0)
    {
        printf("Informe um valor: ");
        scanf("%d", &n);
        sum += n;

        if (n % 2 == 0)
        {
            sumPar += n;
            turnPar++;
        }

        printf("\nDeseja continuar? 0-Sim 1-Nao\n");
        scanf("%d", &op);
        if (op == 0)
        {
            turn++;
        }
    }
    mediaPar = sumPar / turnPar;

    printf("\nSoma: %d\n", sum);
    printf("Media dos pares: %d\n", mediaPar);

    return 0;
}