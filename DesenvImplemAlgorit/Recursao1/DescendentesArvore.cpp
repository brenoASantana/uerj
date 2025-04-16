/*
Os membros de uma família estão querendo saber quem na família é o mais rico. Para tanto, cada um declarou o valor do seu patrimônio,
que pode ser um valor positivo ou negativo (alguns estão com dívidas!). Eles combinaram que, nessa competição,
o patrimônio de certa pessoa consiste o valor de seu patrimônio acrescido do patrimônio de todos os seus descendentes
(filhos, netos, bisnetos, tataranetos, etc. ─ nessa família, os membros são de uma inacreditável  longevidade).
Cada membro possui no máximo dois filhos. Cada par de cônjuges conta como um único membro da família, representando o casal.

Entrada

Haverá vários casos de teste. A primeira linha contém um inteiro t (1 ≤ t ≤ 5000),, que indica o número de casos de teste.
Cada teste vem em diversas linhas. A primeira linha possui um único natural 1 ≤ n ≤ 10^6 , representando o número de membros da família.
Cada uma das próximas n linhas possui 4 inteiros i, v, e, d (i = identificador do membro da família, v = valor do patrimônio,
e = identificador de um filho, d = identificador do outro filho), onde 1 ≤ i ≤ n , 0 ≤ e, d ≤ n , -100 ≤ v ≤ 100. Os valores de e,d podem
ser 0 indicando a ausência dos respectivos filhos.

Saída

Para cada caso de teste, escreva em uma linha o identificador do membro mais rico. No caso de empates, escreva o menor dos identificadores empatados.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int v, e, d;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<Node> nodes(n + 1);
        vector<vector<int>> parents(n + 1);
        vector<int> count(n + 1, 0);
        vector<long long> sum(n + 1, 0);

        for (int j = 0; j < n; ++j) {
            int i, v, e, d;
            cin >> i >> v >> e >> d;
            nodes[i] = {v, e, d};

            if (e != 0) {
                parents[e].push_back(i);
                count[i]++;
            }
            if (d != 0) {
                parents[d].push_back(i);
                count[i]++;
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (count[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            sum[current] = nodes[current].v;
            if (nodes[current].e != 0) {
                sum[current] += sum[nodes[current].e];
            }
            if (nodes[current].d != 0) {
                sum[current] += sum[nodes[current].d];
            }

            for (int parent : parents[current]) {
                if (--count[parent] == 0) {
                    q.push(parent);
                }
            }
        }

        long long max_sum = -1e18;
        int result_id = n + 1;
        for (int i = 1; i <= n; ++i) {
            if (sum[i] > max_sum) {
                max_sum = sum[i];
                result_id = i;
            } else if (sum[i] == max_sum && i < result_id) {
                result_id = i;
            }
        }

        cout << result_id << '\n';
    }

    return 0;
}
