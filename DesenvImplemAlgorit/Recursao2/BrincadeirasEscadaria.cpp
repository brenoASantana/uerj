/*
A igreja de certo bairro ficava no alto de um morro, por onde os fiéis que iam a pé só tinham acesso através de uma grande escadaria,
que vinha do pé do morro e subia até quase à porta da igreja. Para os mais idosos, a escadaria era um motivo de tortura.
Para a criançada, uma fonte de brincadeiras.

A mais nova inventada foi a seguinte: colaram em cada degrau um número inteiro, que representa a recompensa de pisar naquele degrau.
Cada um, em sua vez, sobe a escadaria pulando quantos degraus quiser, mas sem nunca retroceder,
necessariamente começando do primeiro degrau e terminando no último.
A recompensa de uma dada maneira de subir é dada pela soma dos inteiros associados aos degraus pisados.
 Aquele que conseguir a maior recompensa em sua subida, é o vencedor!

Ajude o Joãozinho a ganhar da molecada!

Entrada

Haverá vários casos de teste. A primeira linha contém um inteiro t (1 ≤ t ≤ 5000), que indica o número de casos de teste.
Cada teste vem em duas linhas. A primeira contém dois inteiros 2 ≤ n ≤ 1000, 1 ≤ k ≤ n-1, representando respectivamente o número de degraus da
escadaria e o maior número de degraus que Joãozinho consegue pular em um só salto.
Na segunda linha, há n inteiros x_1, x_2, …, x_n, onde, para todo 1 ≤ i ≤ n, -100 ≤ x_i ≤ 100 representa o inteiro associado ao i-ésimo degrau.

Saída

Para cada caso de teste, escreva em uma linha o inteiro que representa a maior recompensa possível de se obter em uma subida.
*/

#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MIN / 2;
vector<int> x;
vector<long long> memo;
int k;

long long resolve(int i)
{
    if (i == 1)
        return x[1];
    if (memo[i] != INF)
        return memo[i];

    long long melhor = LLONG_MIN;
    // tenta vir de qualquer degrau i–j, j=1..k
    for (int j = 1; j <= k; j++)
    {
        if (i - j >= 1)
        {
            melhor = max(melhor, resolve(i - j));
        }
    }
    return memo[i] = x[i] + melhor;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n >> k;
        x.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
            cin >> x[i];

        memo.assign(n + 1, INF);

        cout << resolve(n) << "\n";
    }
    return 0;
}
