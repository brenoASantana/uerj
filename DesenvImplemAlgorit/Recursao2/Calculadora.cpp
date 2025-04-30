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

#include <bits/stdc++.h>
using namespace std;

string s;
int idx;

void pulaEspacos()
{
    while (idx < (int)s.size() && isspace(s[idx]))
        idx++;
}

long long parseNumero()
{
    pulaEspacos();
    int sign = 1;
    if (s[idx] == '+' || s[idx] == '-')
    {
        if (s[idx] == '-')
            sign = -1;
        idx++;
    }
    long long num = 0;
    while (idx < (int)s.size() && isdigit(s[idx]))
    {
        num = num * 10 + (s[idx] - '0');
        idx++;
    }
    return sign * num;
}

// Lê e avalia EXPR:
//  EXPR = number
//       | '(' EXPR ')' op '(' EXPR ')'
long long parseExpr()
{
    pulaEspacos();
    if (s[idx] != '(')
    {
        // é um número isolado
        return parseNumero();
    }
    // encontrou '(', então é (EXP1) op (EXP2)
    idx++; // consome '('
    long long left = parseExpr();
    pulaEspacos();
    if (s[idx] == ')')
        idx++;
    pulaEspacos();
    char op = s[idx++]; // +, -, x ou /
    pulaEspacos();
    if (s[idx] == '(')
        idx++;
    long long right = parseExpr();
    pulaEspacos();
    if (s[idx] == ')')
        idx++;
    // aplica operação
    switch (op)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case 'x': // ou '*'
    case '*':
        return left * right;
    case '/':
        return left / right;
    }
    return 0; // nunca chega aqui
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    string line;
    getline(cin, line); // consome o \n após T

    while (T--)
    {
        getline(cin, s);
        idx = 0;
        long long ans = parseExpr();
        cout << ans << "\n";
    }
    return 0;
}
