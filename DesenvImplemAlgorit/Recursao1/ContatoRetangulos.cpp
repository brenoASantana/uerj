/*
Dados naturais n, m, representando os lados de um retângulo ladrilhado em quadrados 1x1, determinar quantos retângulos (de quaisquer lados)
podem ser formados por tais ladrilhos. Por exemplo, se n = m = 2, então a resposta é 9. De fato, veja que

há 4 retângulos 1x1;
há 2 retângulos 2x1;
há 2 retângulos 1x2;
há 1 retângulo 2x2,

totalizando 4+2+2+1 = 9 retângulos. Elabore um programa que, dados os valores n,m,
determine a quantidade de retângulos distintos que podem ser contados dentro desse ladrilhado.

Entrada

Haverá vários casos de teste. A primeira linha contém um inteiro t (1 ≤ t ≤ 5000),, que indica o número de casos de teste.
Cada teste vem em uma única linha, contendo dois inteiros 0 ≤ n ≤ 1000, 0 ≤ m ≤ 1000.

Saída

Para cada caso de teste, escreva em umal linha a quantidade de retângulos distintos que podem ser contados dentro desse ladrilhado n x m.
*/

#include <iostream>
using namespace std;

int main()
{
    int t, n, m;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        if (n == 0 || m == 0)
            cout << 0 << endl;

        else

            cout << ((long long)n * (n + 1) / 2) * ((long long)m * (m + 1) / 2) << endl;
    }

    return 0;
}