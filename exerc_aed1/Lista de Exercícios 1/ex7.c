#include <stdio.h>

int funcao(int n)
{
    if (n < 0)
    {
        return n;
    }
    else
    {
        funcao(n - 1);
        printf("%d ", n);
    }
}

int main()
{
    int n;
    printf("Informe o valor de N: ");
    scanf("%d", &n);
    funcao(n);

    return 0;
}