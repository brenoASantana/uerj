/*
Antigamente, as crianças se divertiam muito descendo a rua com o carrinho de rolimã. Mas não as crianças da cidade de
Planolândia: não havia uma só ladeira para se brincar de rolimã em toda a cidade!

Os pais, cansados de empurrarem seus filhos nos carrinhos de rolimã pela falta de ladeiras, peticionaram ao prefeito a disponibilização de um
pátio municipal que estava em desuso, de formato retangular, para servir de pista para as brincadeiras com os carrinhos de rolimã, que prontamente
atendeu o pedido (o prefeito tinha cinco filhos). A prefeitura mandou elevar o terreno desse pátio de modo que fossem criadas várias regiões de descidas,
e assim muitas crianças pudessem brincar ao mesmo tempo, cada uma descendo de um ponto de elevação até um ponto onde não houvesse mais como descer.

Joãozinho percebeu que, dependendo do ponto onde ele começasse a descida e do trajeto conduzido, poderia andar um comprimento maior ou menor.
Ele prontamente usou seu drone para mapear a altitude de cada ponto do pátio, obtendo uma imagem semelhante a seguinte:

1 2 3
8 9 4
7 6 5

O exemplo acima representa um pátio de 3m de comprimento (cada linha representa 1m), por 3m de largura (idem em relação às colunas),
onde a elevação do ponto de coordenada (i,j) é o número que aparece na i-ésima linha, j-ésima coluna. Por exemplo, o centro do pátio,
de coordenada (2,2), possui 9m de elevação. Note que é possível começar no centro e descer 9-2-1, perfazendo um trajeto de comprimento 3.
Mas é possível fazer melhor: 9-8-7-...-3-2-1, um trajeto de comprimento 9, o maior possível!

Escreva um programa para ajudar Joãozinho a traçar o trajeto de maior comprimento. O trajeto pode começar em qualquer célula,
só se pode andar ortogonalmente e sempre estritamente descendo de elevação.

Entrada

Haverá vários casos de teste. A primeira linha contém um inteiro t (1 ≤ t ≤ 5000), que indica o número de casos de teste.
Cada teste vem em diversas linhas. A primeira contém dois inteiros 1 ≤ n ≤ 1000, 1 ≤ m ≤ 1000, representando respectivamente o
comprimento e a largura do pátio. Nas próximas n linhas, há m inteiros em cada linha representando a altura da elevação de cada
ponto do pátio, de modo que o j-ésimo inteiro da i-ésima linha represente a elevação do quadrado de coordenada (i,j) do pátio.

Saída

Para cada caso de teste, escreva em uma linha o inteiro que representa o comprimento do maior trajeto de descida.
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> h;
vector<vector<int>> dp;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

// Retorna o maior comprimento de descida a partir de (r,c)
int dfs(int r, int c)
{
    if (dp[r][c] != 0)
        return dp[r][c];
    int best = 1; // já conta a própria célula
    for (int d = 0; d < 4; ++d)
    {
        int nr = r + dr[d], nc = c + dc[d];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && h[nr][nc] < h[r][c])
        {
            best = max(best, 1 + dfs(nr, nc));
        }
    }
    return dp[r][c] = best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        h.assign(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> h[i][j];

        dp.assign(n, vector<int>(m, 0));
        int answer = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                answer = max(answer, dfs(i, j));
            }
        }

        cout << answer << "\n";
    }
    return 0;
}
