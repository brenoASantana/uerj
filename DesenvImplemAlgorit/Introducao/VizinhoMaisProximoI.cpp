/*
A numeração das casas de uma rua na cidade de Confusópolis é livre, o que traz muita confusão.
A sequência de números das casas está representada em um vetor V, contendo números inteiros.
Dado o número V[i] da i-ésima casa, você quer saber qual a casa mais próxima, localizada à direita da casa i,
que tem a numeração igual ou superior à da casa i.

Você achou melhor fazer um programa para calcular, para cada casa, qual a numeração do vizinho mais próximo,
segundo o critério explicado.

Entrada
Haverá vários casos de teste. A primeira linha contém um inteiro t (1 ≤ t ≤ 1000),
que indica o número de casos de teste. Cada teste vem em duas linhas.
Na primeira, vem um número n (1 ≤ n ≤ 1000), o número de elementos do vetor. Na segunda linha,
vêm n inteiros positivos, distintos, não maiores que 1000000000, os elementos 1 a n do vetor V.

Saída
Para cada caso de teste, escreva n valores, um para cada posição do vetor,
contendo o número da casa do vizinho mais próximo, segundo o critério adotado.
Se não houver tal valor no vetor para dada posição, escreva -1.
*/

#include <iostream>
using namespace std;

int main()
{
    int t, quant;

    cin >> t;
    while (t--)
    {

        cin >> quant;

        int *vet = new int[quant];

        if (int i = 0; i < quant; i++)
        {
            cin >> vet[i];
        }

        for (int i = 0; i < quant; i++)
        {
            if (vet[i] < vet[i++])
            {
                cout i;
                else
                {
                    cout - 1;
                }
            }
        }
    }

        return 0;
}