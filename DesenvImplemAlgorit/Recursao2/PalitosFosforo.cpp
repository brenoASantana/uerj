/*
A representação decimal dos números pode ser facilmente feita com palitos de fósforo. Cada algarismo pode ser representado conforme ilustra a figura abaixo.



Elabore um programa para, dados dois naturais n,k, determinar quantos números de exatamente k algarismos podem ser escritos com no máximo n palitos.

Haverá vários casos de teste. A primeira linha contém um inteiro t (1 ≤ t ≤ 5000), que indica o número de casos de teste. Cada teste vem em uma única linha,
contendo dois inteiros 0 ≤ n ≤ 10^9, 1 ≤ k ≤ 18.

Saída

Para cada caso de teste, escreva em uma linha com a quantidade de números com exatamente k algarismos podem ser representados com no máximo n palitos.
*/

#include <bits/stdc++.h>
using namespace std;

// custos de palitos para cada dígito de 0 a 9:
static const int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

using ll = long long;
int K;
vector<vector<ll>> dp;

// Função recursiva top-down:
// pos = posição atual (1..K), rem = palitos restantes (0..7*K)
ll go(int pos, int rem)
{
    // caso base: preencheu todas as posições
    if (pos == K + 1)
        return 1;
    ll &ans = dp[pos][rem];
    if (ans != -1)
        return ans;
    ans = 0;
    // intervalo de dígitos válidos
    int start = (pos == 1 ? 1 : 0);
    for (int d = start; d <= 9; ++d)
    {
        int c = cost[d];
        if (c <= rem)
        {
            ans += go(pos + 1, rem - c);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        long long n;
        cin >> n >> K;

        // limite real de palitos: não faz sentido ter mais que 7*K
        int maxSticks = 7 * K;
        int rem = (n > maxSticks ? maxSticks : int(n));

        // inicializa dp com -1
        dp.assign(K + 2, vector<ll>(rem + 1, -1));

        // computa resposta
        cout << go(1, rem) << "\n";
    }
    return 0;
}
