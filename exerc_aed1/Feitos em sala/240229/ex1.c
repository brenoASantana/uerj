// Faca um programa em C que leia tres numeros inteiros distintos e os coloque em ordem crescente.
#include <stdio.h>

int main()
{
    int n1, n2, n3 = 0;

    printf("Primeiro numero: ");
    scanf("%d", &n1);
    printf("\nSegundo numero: ");
    scanf("%d", &n2);
    printf("\nTerceiro numero: ");
    scanf("%d", &n3);

    if (n1 > n2)
    {
        if (n1 > n3)
        {
            if (n2 > n3)
            {
                printf("%d, %d, %d", n1, n2, n3);
            }
            else
            {
                printf("%d, %d, %d", n1, n3, n2);
            }
        }
        else
        {
            printf("%d, %d, %d", n3, n1, n2);
        }
    }
    else
    {

        if (n2 > n3)
        {
            printf("%d, %d, %d", n2, n3, n1);
        }
        else
        {
            printf("%d, %d, %d", n3, n2, n1);
        }
    }
    printf("%d, %d, %d", n2, n1, n3);

    return 0;
}
