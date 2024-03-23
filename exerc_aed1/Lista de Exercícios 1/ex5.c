#include <stdio.h>
int primo(int n)
{
    int i, cont = 0;
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cont++;
        }
    }
    if (cont == 2) // eh primo
    {
        return 0;
    }
    else // nao eh primo
    {
        return 1;
    }
}

int main()
{
    int n, i;
    printf("Digite um numero: ");
    scanf("%d", &n);

    for (i = n; i > 0; i--)
    {
        if (primo(i) == 0)
            printf(" %d ", i);
    }

    return 0;
}