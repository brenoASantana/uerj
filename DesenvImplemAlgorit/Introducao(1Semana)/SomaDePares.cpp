/*
Considere que você tenha um vetor contendo n inteiros distintos, já ordenado.
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
#include <vector>

using namespace std;

int main()
{
    int t, n, s;
    int quant = 0;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> s;

        vector<int> vet(n);

        for (int j = 0; j < n; j++)
        {
            cin >> vet[j];
        }

        int k = 0;
        while (k != n - 1)
        {
            // Caso chege no final do vetor e não tem mais nenhum item próximo
            if (k + 1 >= n)
                break;

            if (vet[k] + vet[k + 1] == s)
            {
                k++;
                quant++;
                continue;
            }
            k++;
        }
        continue;
    }

    cout << quant;

    return 0;
}