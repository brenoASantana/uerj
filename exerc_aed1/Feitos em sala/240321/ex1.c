// Construa um algoritmo,

#include <stdio.h>

int main()
{
    int n;
    int matriz[n][n];
    int maior;
    int i, j;

    // Melhor Caso: nao existe
    // Pior Caso: nao existe
    // nao existe pois eh uma funcao continua
    // pior e melhor eh a mesma coisa
    for (i = 0; i < n; i++)
    {
        for (j = 0; i < n; i++)
        {
            if (maior < matriz[i, j])
            {
                maior = matriz[i, j];
            }
        }
    }
    // O(n^2)
    return 0;
}