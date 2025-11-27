#include <iostream>
#include <vector>

using namespace std;

// Variáveis globais para evitar overhead de passagem de parâmetro
int N;
long long total_count;
int p[25];       // Vetor para armazenar a permutação atual
bool used[25];   // Vetor para marcar números usados

// Verifica se a sequência (a, b, c) NÃO é monótona
// Retorna true se for seguro (anti-monótono), false se for inválido (monótono)
inline bool is_safe(int a, int b, int c) {
    // Se for crescente (a < b < c) OU decrescente (a > b > c), é inválido
    if ((a < b && b < c) || (a > b && b > c)) return false;
    return true;
}

void backtrack(int idx) {
    // PODA: Verifica os últimos 3 elementos assim que possível
    if (idx >= 3) {
        if (!is_safe(p[idx-3], p[idx-2], p[idx-1])) return;
    }

    // CASO BASE: Permutação completa
    if (idx == N) {
        // Verifica as conexões cíclicas (bordas)
        // 1. Penúltimo, Último, Primeiro
        if (!is_safe(p[N-2], p[N-1], p[0])) return;
        // 2. Último, Primeiro, Segundo
        if (!is_safe(p[N-1], p[0], p[1])) return;

        total_count++;
        return;
    }

    // Tenta adicionar cada número disponível
    for (int i = 1; i <= N; i++) {
        if (!used[i]) {
            used[i] = true;
            p[idx] = i;
            backtrack(idx + 1);
            used[i] = false;
        }
    }
}

int main() {
    // Otimização de I/O (Input/Output)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> N && N != 0) {
        total_count = 0;

        // Limpa o vetor de usados para o novo caso de teste
        for(int i = 0; i <= N; i++) used[i] = false;

        backtrack(0);

        cout << total_count << "\n";
    }
    return 0;
}