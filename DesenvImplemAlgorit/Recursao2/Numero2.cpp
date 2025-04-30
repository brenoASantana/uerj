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

#include <bits/stdc++.h>
using namespace std;
using unsigned64 = unsigned long long;

// Conta quantos dígitos '2' há em todos os números de 0 até n
unsigned64 count2sUpTo(unsigned long long n)
{
    if (n == (unsigned64)-1)
        return 0; // caso n < 0
    unsigned64 count = 0;
    unsigned long long factor = 1;
    while (factor <= n)
    {
        unsigned long long higher = n / (factor * 10);
        unsigned long long current = (n / factor) % 10;
        unsigned long long lower = n % factor;
        // caso current < 2
        if (current < 2)
        {
            count += higher * factor;
        }
        // caso current == 2
        else if (current == 2)
        {
            count += higher * factor + lower + 1;
        }
        // caso current > 2
        else
        {
            count += (higher + 1) * factor;
        }
        factor *= 10;
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        unsigned long long x, y;
        cin >> x >> y;
        // número de '2's em (x+1..y) = C(y) - C(x)
        unsigned64 result = count2sUpTo(y) - count2sUpTo(x);
        cout << result << "\n";
    }
    return 0;
}
