/*
Matilde votou pela primeira vez esse ano. E mal pode esperar pelo segundo turno, para ir de novo às urnas!
Porém, uma notícia acaba de lhe perturbar: talvez não haja segundo turno nas eleições para prefeito em sua cidade.
Escreva um programa para ajudar a Matilde a saber se, de fato, haverá ou não segundo turno.

Entrada
A entrada consiste de vários casos de teste. A primeira linha representa o número de casos de teste.
Cada caso de teste consiste de duas linhas. A primeira linha de cada caso de teste consiste de um único inteiro n (1 ≤  n ≤ 1000),
denotando o número de votos. A segunda linha de cada caso de teste vem com n inteiros, representando os votos,
cada um indicando o número do candidato votado. Cada número de candidato é um número entre 0 e 1.000.000.000 (na cidade de Matilde,
contrariando Raul Seixas, muitos querem ser prefeitos).

Saída
A saída deve ser um caractere para cada entrada, com o valor 'S' se haverá o segundo turno, e 'N' caso não houver.
O segundo turno ocorre se nenhum candidato obtiver a maioria dos votos, isto é, mais que n/2 votos.
*/
#include <iostream>
using namespace std;

int main()
{
    long t, quantCand;
    long maior, quant = 0;

    cin >> t;
    while (t--)
    {
        cin >> quantCand;

        long *votos = new long[quantCand];

        for (int i = 0; i < quantCand; i++)
        {
            cin >> votos[i];
        }

        for (int i = 0; i < quantCand; i++)
        {
            cout << votos[i] << endl;
            quant += votos[i];
            if (votos[i] >= maior)
            {
                maior = &votos[i];
            }
        }
        cout << maior << endl;
        cout << quant << endl;
        cout << quantCand << endl;

        if (maior >= (quant / 2))
        {
            cout << 'N' << endl;
        }
        else
        {
            cout << 'S' << endl;
        }

        delete[] votos;
    }

        return 0;
}