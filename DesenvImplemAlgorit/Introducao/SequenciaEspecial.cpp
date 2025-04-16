/*
A sequência especial de inteiros. não decrescente, <f(1), f(2),...> é tal que f(k) significa o número de vezes que o valor k aparece na sequência.
Solomon Golomb mostrou que há apenas uma sequência com essa característica. Podemos ver a seguir os primeiros elementos da mesma:
k     |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 | 12 | 13 | 14 | 15 | …
f(k) |  1 |  2 |  2 |  3 |  3 |  4 |  4 |  4 |  5 |  5 |  5 |   6 |  6 |   6 |   6 | …
Este problema consiste apenas em, dado k, calcular f(k).



Entrada
Haverá vários casos de teste. A primeira linha contém um inteiro t (1 ≤ t ≤ 5000), que indica o número de casos de teste.
Cada teste vem em uma linha contendo um inteiro 
k (1 ≤ k ≤ 4000000000).

Saída
Para cada caso de teste, escreva um valor contendo f(k).
*/

#include <iostream>
using namespace std;

long long achaF(long long k)
{
    if (k == 1)
        return 1;

    long long somaS = 0;
    long long atual_c = 1;
    long long termosGrupo = 1;

    while (true)
    {
        long long add = atual_c * termosGrupo;
        if (somaS + add >= k)
        {
            return atual_c;
        }
        somaS += add;
        termosGrupo = atual_c;
        atual_c++;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long k;
        cin >> k;
        cout << achaF(k) << endl;
    }
    return 0;
}