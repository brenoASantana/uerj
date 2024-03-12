//Faca um programa que arredonde a nota para 9.5 caso esteja entre 9 e 9.4

#include <stdio.h>

int main()
{
    float n;
    printf("Informe a nota:\n");
    scanf("%f", &n);

    if (n >= 9 && n < 9.5)
    {
        n = 9.5;
    }
    printf("\nNota: %.1f", n);

    return 0;
}