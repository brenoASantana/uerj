/*
Seu irmão mais novo está aprendendo a fazer origamis (dobraduras de papel) e pede sua ajuda para cortar um retângulo de papel,
de forma a obter quatro quadrados de papel com o mesmo lado, pois normalmente as dobraduras são feitas a partir de pedaços com essa forma.
Os quadrados devem ter o maior lado possível.

Entrada
Haverá vários casos de teste. A primeira linha contém um inteiro t (1 ≤ t ≤ 5000), que indica o número de casos de teste.
Cada teste vem em uma linha com dois inteiros a e b, as dimensões do retângulo.

Saída
Para cada caso de teste, escreva um valor contendo o lado dos maiores quadrados possíveis cortados a partir do retângulo.
Você pode admitir que a resposta será sempre um valor inteiro.
*/

#include <iostream>
using namespace std;

int main()
{
    int t, a, b;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        int caso1 = min(a / 2, b / 2);
        int caso2 = min(a / 4, b);
        int caso3 = min(a, b / 4);
        int res = max(caso1, max(caso2, caso3));
        cout << res << endl;
    }

    return 0;
}