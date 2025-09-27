#include <stdio.h>

// --- Funções aritméticas ---
int inc(const int n) { return n + 1; }
int dec(const int n) { return n - 1; }

// --- Funções de comparação ---
int menor(const int n1, const int n2) { return n1 < n2; }
int menor_igual(const int n1, const int n2) { return n1 <= n2; }
int maior(const int n1, const int n2) { return n1 > n2; }
int maior_igual(const int n1, const int n2) { return n1 >= n2; }
int igual(const int n1, const int n2) { return n1 == n2; }
int diferente(const int n1, const int n2) { return n1 != n2; }

// --- Funções lógicas ---
int e(const int b1, const int b2) { return b1 && b2; }
int ou(const int b1, const int b2) { return b1 || b2; }
int nao(const int b) { return !b; }

// Soma recursiva
int soma(const int a, const int b)
{
    if (equals(a, b))
        return a;
    return soma(inc(a), b);
}

// --- Função main para testes ---
int main()
{
    printf("inc(5) = %d\n", inc(5));
    printf("dec(5) = %d\n", dec(5));
    printf("menor(3, 5) = %d\n", menor(3, 5));
    printf("menor_igual(5, 5) = %d\n", menor_igual(5, 5));
    printf("maior(7, 2) = %d\n", maior(7, 2));
    printf("maior_igual(7, 7) = %d\n", maior_igual(7, 7));
    printf("igual(4, 4) = %d\n", igual(4, 4));
    printf("diferente(4, 5) = %d\n", diferente(4, 5));
    printf("e(1, 0) = %d\n", e(1, 0));
    printf("ou(1, 0) = %d\n", ou(1, 0));
    printf("nao(0) = %d\n", nao(0));
    printf("soma(3, 6) = %d\n", soma(3, 6));
    return 0;
}
