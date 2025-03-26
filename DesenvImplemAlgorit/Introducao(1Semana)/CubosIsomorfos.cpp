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
using namespace std;

int main()
{
    int t, a, b;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;

    }
    return 0;
}