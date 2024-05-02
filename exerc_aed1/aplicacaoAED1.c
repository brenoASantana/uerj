//Feito por Breno Santana, Davi Justino, Matheus Oliveira, Rafael Achidi e Samir Guimaraes

#include <stdio.h>

// Função para exibir o menu e obter a opção do usuário
int menu() {
  int opcao;
  printf("Selecione uma opção:\n");
  printf("1- Preencher o vetor\n");
  printf("2- Buscar por um valor\n");
  printf("3- Ordenar o vetor\n");
  printf("4- Mostrar o vetor\n");
  printf("5- Sair\n");
  scanf("%d", &opcao);
  return opcao;
}

// Função para preencher o vetor com valores fornecidos pelo usuário
void preencherVetor(int vetor[], int tamanhoVetor) {
  for (int i = 0; i < tamanhoVetor; i++) {
    printf("Digite o valor desejado para o elemento %d: ", i);
    scanf("%d", &vetor[i]);
    printf("Valor %d adicionado.\n", vetor[i]);
  }
}

// Função para busca binária em um vetor ordenado
int buscaBinaria(int alvo, int arr[], int tamanhoArr) {
  int baixo = 0;
  int alto = tamanhoArr - 1;
  while (baixo <= alto) {
    int meio = (baixo + alto) / 2;
    if (arr[meio] == alvo) {
      return meio;
    } else if (arr[meio] < alvo) {
      baixo = meio + 1;
    } else {
      alto = meio - 1;
    }
  }
  return -1; // Retorna -1 se o elemento não for encontrado
}

// Função para ordenar o vetor usando Bubble Sort
void bubbleSort(int vetor[], int tamanhoVetor) {
  int i, continua, aux, fim = tamanhoVetor;
  do {
    continua = 0;
    for (i = 0; i < fim - 1; i++) {
      if (vetor[i] > vetor[i + 1]) {
        aux = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = aux;
        continua = 1;
      }
    }
    fim--;
  } while (continua);
}

// Função para mostrar os elementos do vetor
void mostrarVetor(int *vetor, int tamanhoVetor) {
  for (int i = 0; i < tamanhoVetor; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main(void) {
  int valor;
  int vetor[10]; // Tamanho do vetor definido como 10
  int tamanhoVetor = sizeof(vetor) / sizeof(vetor[0]);
  int opcao;
  int vetorPreenchido = 0; // Variável para verificar se o vetor foi preenchido
  do {
    opcao = menu();
    switch (opcao) {
    case 1:
      // 1 - Preencher vetor
      preencherVetor(vetor, tamanhoVetor);
      vetorPreenchido = 1; // Atualiza para indicar que o vetor foi preenchido
      break;
    case 2:
      // 2 - Buscar por um valor
      if (!vetorPreenchido) {
        printf("O vetor ainda não foi preenchido.\n");
        break;
      }
      printf("Digite o valor que deseja buscar:");
      scanf("%d", &valor);
      int opcaoBusca;
      do {
        printf("\nInforme qual busca deseja usar:\n");
        printf("1 - Busca Sequencial Ordenada\n");
        printf("2 - Busca Binaria\n");
        scanf("%d", &opcaoBusca);

        if (opcaoBusca != 1 && opcaoBusca != 2)
          printf("\nOpção Inválida\n");

      } while (opcaoBusca != 1 && opcaoBusca != 2);

      if (opcaoBusca == 1)
        bubbleSort(vetor, tamanhoVetor);

      int posicao = buscaBinaria(valor, vetor, tamanhoVetor);

      if (posicao != -1)
        printf("Valor encontrado na posição %d\n", posicao);
      else
        printf("Valor não encontrado.\n");
      break;
    case 3:
      // 3 - Ordenar o vetor
      if (!vetorPreenchido) {
        printf("O vetor ainda não foi preenchido.\n");
        break;
      }
      int opcaoOrdenacao;
      do {
        printf("\nInforme qual ordenação deseja usar:\n");
        printf("1 - BubbleSort\n");
        printf("2 - InsertionSort\n");
        scanf("%d", &opcaoOrdenacao);

        if (opcaoOrdenacao != 1 && opcaoOrdenacao != 2)
          printf("\nOpção Inválida\n");

      } while (opcaoOrdenacao != 1 && opcaoOrdenacao != 2);

      if (opcaoOrdenacao == 1)
        bubbleSort(vetor, tamanhoVetor);

      printf("Vetor ordenado com sucesso.\n");
      break;
    case 4:
      // 4 - Mostrar vetor
      if (!vetorPreenchido) {
        printf("O vetor ainda não foi preenchido.\n");
        break;
      }
      mostrarVetor(vetor, tamanhoVetor);
      break;
    case 5:
      // 5 - Sair
      printf("Saindo do programa...\n");
      break;
    default:
      printf("Opção inválida, tente novamente.\n");
    }
  } while (opcao != 5);
  return 0;
}
