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

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int v, e, d;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<Node> nodes(n + 1);
        vector<vector<int>> parents(n + 1);
        vector<int> count(n + 1, 0);
        vector<long long> sum(n + 1, 0);

        for (int j = 0; j < n; ++j)
        {
            int i, v, e, d;
            cin >> i >> v >> e >> d;
            nodes[i] = {v, e, d};

            if (e != 0)
            {
                parents[e].push_back(i);
                count[i]++;
            }
            if (d != 0)
            {
                parents[d].push_back(i);
                count[i]++;
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; ++i)
        {
            if (count[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            sum[current] = nodes[current].v;
            if (nodes[current].e != 0)
            {
                sum[current] += sum[nodes[current].e];
            }
            if (nodes[current].d != 0)
            {
                sum[current] += sum[nodes[current].d];
            }

            for (int parent : parents[current])
            {
                if (--count[parent] == 0)
                {
                    q.push(parent);
                }
            }
        }

        long long max_sum = -1e18;
        int result_id = n + 1;
        for (int i = 1; i <= n; ++i)
        {
            if (sum[i] > max_sum)
            {
                max_sum = sum[i];
                result_id = i;
            }
            else if (sum[i] == max_sum && i < result_id)
            {
                result_id = i;
            }
        }

        cout << result_id << '\n';
    }

    return 0;
}
