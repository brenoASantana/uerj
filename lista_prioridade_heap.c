// Feito por Breno Alexandre Santana Silva e Matheus da Silva de Oliveira

#include <stdio.h>

// Variável para o controle do tamanho do vetor de entrada
int tamanho = 0;

// Enumeração para os tipos de heap
typedef enum { MAX_HEAP, MIN_HEAP } TipoHeap;

// Procedimento para trocar os valores de duas variáveis
void trocar(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

// Procedimento para tornar o vetor em uma estrutura heap válida, seguindo sua
// propriedade
void amontoar(int vetor[], int tamanho, int i, TipoHeap tipo) {
  if (tamanho == 1) {
    printf("Há um só elemento.\n");
  } else {
    int extremo = i; // Consideramos o primeiro elemento da sub-árvore o extremo
                     // (maior ou menor)
    int noEsquerdo = 2 * i + 1; // Índice do filho à esquerda
    int noDireita = 2 * i + 2;  // Índice do filho à direita

    if (tipo == MAX_HEAP) {
      // Max-Heap: Verifica se o filho à esquerda é maior que o nó atual
      if (noEsquerdo < tamanho && vetor[noEsquerdo] > vetor[extremo])
        extremo = noEsquerdo;
      // Verifica se o filho à direita é maior que o nó atual
      if (noDireita < tamanho && vetor[noDireita] > vetor[extremo])
        extremo = noDireita;
    } else {
      // Min-Heap: Verifica se o filho à esquerda é menor que o nó atual
      if (noEsquerdo < tamanho && vetor[noEsquerdo] < vetor[extremo])
        extremo = noEsquerdo;
      // Verifica se o filho à direita é menor que o nó atual
      if (noDireita < tamanho && vetor[noDireita] < vetor[extremo])
        extremo = noDireita;
    }

    // Se o extremo não é o nó atual, troca e continua amontoando
    if (extremo != i) {
      trocar(&vetor[i], &vetor[extremo]);
      amontoar(vetor, tamanho, extremo, tipo);
    }
  }
}

// Procedimento para modificar a prioridade de um elemento na lista de
// prioridades
void modificar(int vetor[], int alvo, int valor, TipoHeap tipo) {
  for (int i = 0; i < tamanho; i++) {
    if (vetor[i] == alvo) {
      vetor[i] = valor;
      // Reorganiza o heap após a modificação
      for (int j = tamanho / 2 - 1; j >= 0; j--) {
        amontoar(vetor, tamanho, j, tipo);
      }
      return;
    }
  }
}

// Procedimento para inserir um elemento na árvore
void inserir(int vetor[], int valor, TipoHeap tipo) {
  // Verifica se o valor já existe no vetor
  for (int i = 0; i < tamanho; i++) {
    if (vetor[i] == valor) {
      printf("Valor %d já existente\n\n", valor);
      return;
    }
  }
  vetor[tamanho] = valor;
  tamanho += 1;

  // Reorganiza o heap após a inserção
  for (int i = tamanho / 2 - 1; i >= 0; i--) {
    amontoar(vetor, tamanho, i, tipo);
  }
}

// Procedimento para deletar o elemento raiz da lista de prioridade
void deletar(int vetor[], TipoHeap tipo) {
  if (tamanho == 0) {
    printf("O heap está vazio.\n");
    return;
  }
  trocar(&vetor[0], &vetor[tamanho - 1]);
  tamanho -= 1;

  // Reorganiza o heap após a exclusão
  for (int i = tamanho / 2 - 1; i >= 0; i--) {
    amontoar(vetor, tamanho, i, tipo);
  }
}

// Procedimento para exibir o vetor
void exibir(int vetor[], int tamanho) {
  for (int i = 0; i < tamanho; ++i)
    printf("%d ", vetor[i]);
  printf("\n");
}

// Função para imprimir o heap em forma de árvore binária
void exibirHeap(int vetor[], int n, int i, int profundidade) {
  if (i >= n)
    return;

  // Imprime o filho à direita primeiro (topo da árvore)
  exibirHeap(vetor, n, 2 * i + 2, profundidade + 1);

  // Imprime o nó atual
  for (int j = 0; j < profundidade; j++)
    printf("   ");
  printf("%d\n", vetor[i]);

  // Imprime o filho à esquerda
  exibirHeap(vetor, n, 2 * i + 1, profundidade + 1);
}

int main() {
  int vetor[10] = {0}; // Inicializa o vetor com zeros

  // Demonstrando Max-Heap
  TipoHeap tipo = MAX_HEAP;
  printf("Max-Heap:\n");
  exibir(vetor, tamanho);

  inserir(vetor, 3, tipo);
  inserir(vetor, 9, tipo);
  inserir(vetor, 2, tipo);
  inserir(vetor, 1, tipo);
  inserir(vetor, 4, tipo);
  inserir(vetor, 5, tipo);

  exibir(vetor, tamanho);
  printf("\n");
  exibirHeap(vetor, tamanho, 0, 0);
  printf("\n\n");

  inserir(vetor, 1, tipo);

  deletar(vetor, tipo);

  exibir(vetor, tamanho);
  printf("\n");
  exibirHeap(vetor, tamanho, 0, 0);

  inserir(vetor, 20, tipo);

  exibir(vetor, tamanho);
  printf("\n");
  exibirHeap(vetor, tamanho, 0, 0);

  // Resetando o vetor e o tamanho para demonstrar Min-Heap
  tamanho = 0;
  for (int i = 0; i < 10; i++)
    vetor[i] = 0;

  // Demonstrando Min-Heap
  tipo = MIN_HEAP;
  printf("Min-Heap:\n");
  exibir(vetor, tamanho);

  inserir(vetor, 3, tipo);
  inserir(vetor, 9, tipo);
  inserir(vetor, 2, tipo);
  inserir(vetor, 1, tipo);
  inserir(vetor, 4, tipo);
  inserir(vetor, 5, tipo);

  exibir(vetor, tamanho);
  printf("\n");
  exibirHeap(vetor, tamanho, 0, 0);
  printf("\n\n");

  inserir(vetor, 1, tipo);

  deletar(vetor, tipo);

  exibir(vetor, tamanho);
  printf("\n");
  exibirHeap(vetor, tamanho, 0, 0);

  inserir(vetor, 20, tipo);

  exibir(vetor, tamanho);
  printf("\n");
  exibirHeap(vetor, tamanho, 0, 0);

  return 0;
}
