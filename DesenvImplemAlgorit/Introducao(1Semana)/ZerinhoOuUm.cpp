/*
No jogo Zerinho ou Um, três participantes apresentam zero ou um dedos.
Se um deles tiver dado um palpite diferente dos outros dois, então ele ganha.
Se os três tiverem dado o mesmo palpite, então o jogo é empate.

Entrada
Haverá vários casos de teste. A primeira linha contém um inteiro t (1 ≤ t ≤ 5000),
que indica o número de casos de teste. Cada teste vem em uma linha, contendo três
inteiros, a, b, c, cada um valendo 0 ou 1, os palpites dos jogadores 1, 2 e 3, respectivamente.

Saída
Para cada caso de teste, escreva 1, 2 ou 3 se, respectivamente, o jogador 1, 2 ou 3
deu um palpite diferente dos outros dois participantes.
Caso os três tenham dado o mesmo palpite, escreva 0.
*/

#include <iostream>
using namespace std;

int main()
{
    int t, a, b, c;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b >> c;

        if (a == b && b == c)
            cout << 0 << endl;
        else if (a != b && a != c)
            cout << 1 << endl;
        else if (b != a && b != c)
            cout << 2 << endl;
        else if (c != a && c != b)
            cout << 3 << endl;
    }

    return 0;
}
