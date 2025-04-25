/*
Desde que a irmãzinha de Maria nasceu, às 22:22 do dia 2/2/2022, Maria passou a adorar o número 2. Agora, ela percebe o número 2 em tudo que pode!

A mais nova mania de Maria é escolher dois naturais x ≤ y, e contar quantos 2 aparecem na escrita dos números x+1,x+2,...,y, escritos todos em representação decimal.
Elabore um programa para ajudar Maria.

Entrada

Haverá vários casos de teste. A primeira linha contém um inteiro t (1 ≤ t ≤ 5000), que indica o número de casos de teste. Cada teste vem em única linha,
contendo dois inteiros 0 ≤ x ≤ y ≤ 2^50.

Saída

Para cada caso de teste, escreva em uma linha o inteiro que representa a quantidade de algarismos 2 nos números x+1, x+2, ..., y escritos em representação decimal.
*/

#include <iostream>
using namespace std;

long long combinacoes(int n, int p)
{
    if (p > n - p)
        p = n - p;
    long long res = 1;
    for (int i = 1; i <= p; i++)
    {
        res *= (n - p + i);
        res /= i;
    }
    return res;
}

int main()
{
    int t, n, p;
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        if (p == 0 || p == n)
            cout << 1 << endl;
        else
            cout << combinacoes(n, p) << endl;
    }
    return 0;
}
