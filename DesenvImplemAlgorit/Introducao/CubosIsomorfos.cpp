/*
Você tem dois cubos, onde cada uma das faces está pintada com uma das cores V(verde), R(rosa) ou A(azul).
Agora você quer saber se esses cubos são isomorfos, isto é, se tomarmos um deles e girarmos convenientemente,
as cores de todas as faces correspondentes nos dois cubos coincidem. O esquema de numeração das faces pode ser visto na figura a seguir

Se, por exemplo, o primeiro cubo for descrito como VVRRAA e o segundo como VRAVRA, então os cubos são isomorfos,
pois o segundo pode ser obtido girando  o primeiro cubo 90° no sentido anti-horário, em torno do eixo perpendicular às faces 1 e 6.

Entrada
Haverá vários casos de teste. A primeira linha contém um inteiro t (1 ≤ t ≤ 5000), que indica o número de casos de teste.
Cada teste vem em duas linhas, cada uma delas descrevendo, com 6 caracteres, um dos cubos em teste.

Saída
Para cada caso de teste, escreva S se os cubos forem isomorfos ou N, caso contrário
*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

string rotacionarY(const string &cube)
{
    string res = cube;
    res[1] = cube[2];
    res[2] = cube[4];
    res[4] = cube[3];
    res[3] = cube[1];
    return res;
}

string rotacionarX(const string &cube)
{
    string res = cube;
    res[0] = cube[1];
    res[1] = cube[5];
    res[5] = cube[4];
    res[4] = cube[0];
    return res;
}

string rotacionarZ(const string &cube)
{
    string res = cube;
    res[0] = cube[3];
    res[3] = cube[5];
    res[5] = cube[2];
    res[2] = cube[0];
    return res;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string cubo1, cubo2;
        cin >> cubo1;
        cin >> cubo2;

        bool isIsomorfo = false;

        set<string> configs;

        for (int i = 0; i < 4; i++)
        {
            string r1 = cubo1;

            for (int a = 0; a < i; a++)
            {
                r1 = rotacionarX(r1);
            }
            for (int j = 0; j < 4; j++)
            {
                string r2 = r1;

                for (int b = 0; b < j; b++)
                {
                    r2 = rotacionarY(r2);
                }
                for (int k = 0; k < 4; k++)
                {
                    string r3 = r2;

                    for (int c = 0; c < k; c++)
                    {
                        r3 = rotacionarZ(r3);
                    }
                    configs.insert(r3);
                }
            }
        }
        if (configs.find(cubo2) != configs.end())
        {
            isIsomorfo = true;
        }
        cout << (isIsomorfo ? 'S' : 'N') << "\n";
    }
    return 0;
}
