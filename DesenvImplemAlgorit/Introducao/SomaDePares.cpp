/*
Considere que você tenha um vetor contendo n inteiros distintos, já ordenado.
É dado um valor s e quer-se saber quantos pares de elementos desse vetor têm a soma igual a s.
É dado um valor s e quer-se saber quantos pares de elementos desse vetor têm a soma igual a s. 

Entrada
Haverá vários casos de teste. A primeira linha contém um inteiro t (1 ≤ t ≤ 1000),que indica o número de casos de teste.
Cada teste vem em duas linhas, A primeira contêm dois inteiros, n (1 ≤ n ≤ 1000000) e s (1 ≤ s ≤ 2000000000),
significando o tamanho do vetor e a soma dada, respectivamente. A segunda linha contêm n inteiros positivos ordenados,
cada um deles representado em 32 bits.

Saída
Para cada caso de teste, escreva um inteiro contendo o número de pares que têm a soma dada.
*/

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        long s;
        cin >> n >> s;

        long *vet = new long[n];

        for (int j = 0; j < n; ++j)
        {
            cin >> vet[j];
        }

        int quant = 0;
        int esq = 0, dir = n - 1;

        while (esq < dir)
        {
            long soma = vet[esq] + vet[dir];
            if (soma == s)
            {
                quant++;
                esq++;
                dir--;
            }
            else if (soma < s)
            {
                esq++;
            }
            else
            {
                dir--;
            }
        }

        cout << quant << '\n';

        delete[] vet;
    }

    return 0;
}