#include <stdio.h>
#include <limits.h>

// Função recursiva tail-recursion para encontrar o menor elemento
int menorRec(int arr[], int n, int tamanho, int minimo) {
    if (n == tamanho) {
        return minimo; // caso base: percorreu todo array
    }

    // atualiza o mínimo
    if (arr[n] < minimo) {
        minimo = arr[n];
    }

    // chamada tail recursion (última instrução)
    return menorRec(arr, n + 1, tamanho, minimo);
}

// Função auxiliar para inicializar com INT_MAX
int menorElemento(int arr[], int tamanho) {
    return menorRec(arr, 0, tamanho, INT_MAX);
}

int main() {
    int arr[] = {5, 2, 8, -3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int menor = menorElemento(arr, n);
    printf("Menor elemento: %d\n", menor);

    return 0;
}
X≈
