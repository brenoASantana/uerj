/*
O irmão mais novo de Joãozinho sempre pede para ele lhe ajudar na conferência de suas soluções de seus exercícios de matemática.
Atualmente, as lições de casa desse irmão são todas relacionadas à determinação de expressões aritméticas.
Ajude o Joãozinho e seu irmão escrevendo um programa que determine o valor de expressões aritméticas simples.

Entrada

Haverá vários casos de teste. A primeira linha contém um inteiro t (1 ≤ t ≤ 5000), que indica o número de casos de teste.
Cada teste vem em única linha, contendo uma cadeia de caracteres representando uma expressão aritmética. Um expressão aritmética EXPR consiste de

EXPR = (EXPR1)op(EXPR2)            ou            = n

onde n representa um número inteiro (-100 ≤ n ≤ 100), EXPR1 e EXPR2 denotam, por sua vez, expressões aritméticas, subexpressões de EXPR, e 
op é um dos caracteres: +,-,x,/ representando respectivamente a operação de soma, subtração, multiplicação, e divisão (inteira).
Cada expressão aritmética não contém, recursivamente, mais do que 1000 subexpressões.

Saída

Para cada caso de teste, escreva em uma linha o inteiro que representa o resultado da respectiva expressão aritmética.
Assuma que não haverá divisão por 0 e que os valores de todas as expressões calculadas são no máximo 10^9.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int L, A;
        cin >> L >> A;

        int n;
        cin >> n;

        vector<pair<int, int>> trees(n);
        for (int i = 0; i < n; i++)
        {
            cin >> trees[i].first >> trees[i].second;
        }

        // Conjunto de pontos candidatos para as coordenadas x e y
        vector<int> xs, ys;
        xs.push_back(0);
        xs.push_back(L);
        ys.push_back(0);
        ys.push_back(A);

        for (int i = 0; i < n; i++)
        {
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
        for (int i = 0; i < (int)xs.size(); i++)
        {
            for (int j = i + 1; j < (int)xs.size(); j++)
            {
                for (int k = 0; k < (int)ys.size(); k++)
                {
                    for (int l = k + 1; l < (int)ys.size(); l++)
                    {
                        int x_left = xs[i], x_right = xs[j];
                        int y_bottom = ys[k], y_top = ys[l];

                        // Verifica se existe árvore estritamente dentro do retângulo
                        bool valid = true;
                        for (int p = 0; p < n; p++)
                        {
                            int tx = trees[p].first, ty = trees[p].second;
                            if (tx > x_left && tx < x_right && ty > y_bottom && ty < y_top)
                            {
                                valid = false;
                                break;
                            }
                        }

                        if (valid)
                        {
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
