/*
Uma fazenda possui uma área retangular. O fazendeiro gostaria de escolher o maior retângulo possível dentro de sua fazenda para construir um
celeiro sem cortar nenhuma árvore. Por exemplo, na figura abaixo, o retângulo maior representa os limites da fazenda, os pontos representam as posições das árvores,
e o maior retângulo possível é como indicado na figura.

Entrada

Haverá vários casos de teste. A primeira linha contém um inteiro t (1 ≤ t ≤ 5000), que indica o número de casos de teste.
Cada teste vem em duas linhas. A primeira linha possui dois inteiros L, A representando que o retângulo da fazenda possui as
coordenadas (0,0), (L,0), (0,A), (L,A). A segunda linha começa com um inteiro 0 ≤ n ≤ 10 , representando o número de árvores,
seguido de n pares x1 y1 x2 y2 … xn yn de inteiros, cada par xi, yi contendo a coordenada de uma árvore dentro da fazenda para todo i = 1, …, n.

Saída

Para cada caso de teste, escreva a área máxima do celeiro que o fazendeiro pode construir. Você pode assumir que o celeiro pode
tangenciar tanto as árvores quanto as bordas da fazenda, mas não pode nem ultrapassar os limites da fazenda, nem ter árvores em sua área interna.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int L, A;
        cin >> L >> A;

        int n;
        cin >> n;

        vector<pair<int,int>> trees(n);
        for (int i = 0; i < n; i++) {
            cin >> trees[i].first >> trees[i].second;
        }

        // Conjunto de pontos candidatos para as coordenadas x e y
        vector<int> xs, ys;
        xs.push_back(0);
        xs.push_back(L);
        ys.push_back(0);
        ys.push_back(A);

        for (int i = 0; i < n; i++) {
            xs.push_back(trees[i].first);
            ys.push_back(trees[i].second);
        }

        // Remover duplicatas e ordenar
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        long long maxArea = 0;

        // Itera sobre todos os retângulos candidatos
        for (int i = 0; i < (int)xs.size(); i++) {
            for (int j = i+1; j < (int)xs.size(); j++) {
                for (int k = 0; k < (int)ys.size(); k++) {
                    for (int l = k+1; l < (int)ys.size(); l++) {
                        int x_left = xs[i], x_right = xs[j];
                        int y_bottom = ys[k], y_top = ys[l];

                        // Verifica se existe árvore estritamente dentro do retângulo
                        bool valid = true;
                        for (int p = 0; p < n; p++) {
                            int tx = trees[p].first, ty = trees[p].second;
                            if (tx > x_left && tx < x_right && ty > y_bottom && ty < y_top) {
                                valid = false;
                                break;
                            }
                        }

                        if (valid) {
                            long long area = (long long)(x_right - x_left) * (y_top - y_bottom);
                            if (area > maxArea)
                                maxArea = area;
                        }
                    }
                }
            }
        }

        cout << maxArea << "\n";
    }

    return 0;
}
