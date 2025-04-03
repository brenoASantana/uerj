/*
Você está fazendo o movimento final em um jogo de Tetris em um tabuleiro 15×20 (15 linhas e 20 colunas).
Você deve jogar uma última peça escolhendo uma posição inicial no topo do tabuleiro.
Após isso, a peça irá descer e parar imediatamente acima da primeira peça preenchida que encontrar ou,
se não encontrar, na primeira linha.

Para sua última jogada, deve-se:

Escolher uma das peças:
Peça "I": uma barra vertical composta por 4 blocos em uma única coluna.
Peça "S": um quadrado composto por 2 linhas e 2 colunas de blocos.
Não sobrepor nenhuma célula preenchida.
Jogar inteiramente dentro dos limites do tabuleiro.
Não rotacionar a peça escolhida (a peça "I" é apenas vertical).
Não mover a peça horizontalmente após escolhida uma posição inicial.
Maximizar o número de linhas completas que você pode limpar com este movimento.


O tabuleiro será dado como uma grade onde cada célula é vazia (0) ou preenchida (1).
Apenas as 10 linhas inferiores (linhas 6 a 15) podem conter células preenchidas nessa entrada.
Então, as 5 linhas superiores (linhas 1 a 5) são garantidamente vazias (todas 0).

Dado o estado atual do tabuleiro, determine a melhor peça a ser usada e o número máximo de linhas que você pode limpar colocando essa peça.

Entrada
A entrada consiste em um inteiro t relativo ao número de casos teste tal que t ≤ 10, cada caso consiste de 15 linhas,
cada uma contendo 20 caracteres separados por espaços. Cada inteiro é 0 (célula vazia) ou 1 (célula preenchida).
A primeira linha corresponde à linha superior do tabuleiro (linha 1), e a última linha corresponde à linha inferior (linha 15).

Saída
Para cada caso de teste, imprima uma linha contendo um inteiro, o número máximo de linhas que você pode limpar e um caractere,
"I" ou "S", de acordo com a peça foi usada na última jogada. Em caso de empate, reportar o uso da peça "I".
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
