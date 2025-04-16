/*
Joãozinho está enfurecido: todas as vezes que algum professor de matemática quer exemplificar um problema de combinatória,
ele vem com o mesmo velho problema: "De quantas maneiras distintas se pode tomar um subconjunto de p elementos de um conjunto de n elementos?"
Será que não há coisa mais interessante para se perguntar, não?! Ele decidiu escrever um programa para seus professores,
para acabar com esse interesse de uma vez por todas.

Entrada

Haverá vários casos de teste. A primeira linha contém um inteiro t (1 ≤ t ≤ 5000), que indica o número de casos de teste.
Cada teste vem em uma única linha, com dois inteiros n,p (0 ≤ p ≤ n ≤ 1000).

Saída

Para cada caso de teste, escreva em uma linha o valor o número de combinações distintas que se pode fazer ao tomar p elementos de
um conjunto de n elementos. Pode-se assumir que todos os números de combinações solicitadas são no máximo 2^62.
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
