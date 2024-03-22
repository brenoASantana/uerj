#include <stdio.h>

int main()
{
    int n = 0;
    do
    {
        printf("Informe o valor de N: ");
        scanf("%d", &n);
    } while (n <= 0);

    int i;
    float s = 0;
    for (i = 1; i <= n; i++)
    {
        s += 1.0 / i;
    }

    printf("\nSoma: %.2f\n", s);
    return 0;
}
