#include <stdio.h>

void fibIterativa(int n)
{

    int i, fib, aux1, aux2;
    for (i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            aux1 = 1;
            continue;
        }
        if (i == 2)
        {
            aux2 = 1;
            continue;
        }

        fib = aux1 + aux2;
        aux1 = aux2;
        aux2 = fib;
    }
    printf("\n %d", fib);
}

int fibRecursiva(int n)
{

    int fib;
    if (n == 1 || n == 2)
        return fib = 1;
    else
        return fib = (fibRecursiva(n - 1) + fibRecursiva(n - 2));
}

int main()
{
    int n;
    printf("Informe um numero: ");
    scanf("%d", &n);

    printf("\n Iterativa: ");
    fibIterativa(n);
    printf("\n Recursiva: ");
    printf("\n %d", fibRecursiva(n));
    return 0;
}