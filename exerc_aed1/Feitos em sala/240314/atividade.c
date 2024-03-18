// Implementar uma função recursiva para calcular x^n , com as seguintes características:
// 𝑥^𝑛= 𝑥 ∗ 𝑥^(𝑛−1)
// Onde:
// x^0 = 1
//  n >= 0

#include <stdio.h>

int potencial(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return x * potencial(x, n - 1);
    }
}

int main()
{
    int x, n;

    printf("Informe o valor de X:\n");
    scanf("%d", &x);

    do
    {
        printf("\nInforme o valor de N maior que ou igual a 0:\n");
        scanf("%d", &n);
    } while (n < 0);

    printf("\nResultado: %d\n", potencial(x, n));

    return 0;
}
