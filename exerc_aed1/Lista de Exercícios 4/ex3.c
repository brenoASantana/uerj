#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Definição da estrutura da lista sequencial
typedef struct
{
    int items[MAX_SIZE];
    int size;
} ListaSequencial;

// Função para inicializar a lista sequencial
void inicializarLista(ListaSequencial *lista)
{
    lista->size = 0;
}

// Função para verificar se a lista está vazia
int listaVazia(ListaSequencial *lista)
{
    return lista->size == 0;
}

// Função para verificar se a lista está cheia
int listaCheia(ListaSequencial *lista)
{
    return lista->size == MAX_SIZE;
}

// Função para inserir um elemento na primeira posição da lista
void inserirPrimeiro(ListaSequencial *lista, int elemento)
{
    if (listaCheia(lista))
    {
        printf("Erro: lista cheia\n");
        return;
    }

    // Deslocar todos os elementos para a direita
    for (int i = lista->size; i > 0; i--)
    {
        lista->items[i] = lista->items[i - 1];
    }

    lista->items[0] = elemento;
    lista->size++;
}

// Função para inserir um elemento na última posição da lista
void inserirUltimo(ListaSequencial *lista, int elemento)
{
    if (listaCheia(lista))
    {
        printf("Erro: lista cheia\n");
        return;
    }

    lista->items[lista->size] = elemento;
    lista->size++;
}

// Função para modificar um elemento da lista dado sua posição e o novo valor
void modificarElemento(ListaSequencial *lista, int posicao, int novoValor)
{
    if (posicao >= 0 && posicao < lista->size)
    {
        lista->items[posicao] = novoValor;
    }
    else
    {
        printf("Erro: posição inválida\n");
    }
}

// Função para remover o primeiro elemento da lista
void removerPrimeiro(ListaSequencial *lista)
{
    if (!listaVazia(lista))
    {
        for (int i = 0; i < lista->size - 1; i++)
        {
            lista->items[i] = lista->items[i + 1];
        }
        lista->size--;
    }
    else
    {
        printf("Erro: lista vazia\n");
    }
}

// Função para remover o último elemento da lista
void removerUltimo(ListaSequencial *lista)
{
    if (!listaVazia(lista))
    {
        lista->size--;
    }
    else
    {
        printf("Erro: lista vazia\n");
    }
}

// Função para remover um elemento dado o seu valor
void removerElemento(ListaSequencial *lista, int elemento)
{
    int i, encontrado = 0;
    for (i = 0; i < lista->size; i++)
    {
        if (lista->items[i] == elemento)
        {
            encontrado = 1;
            break;
        }
    }

    if (encontrado)
    {
        for (int j = i; j < lista->size - 1; j++)
        {
            lista->items[j] = lista->items[j + 1];
        }
        lista->size--;
    }
    else
    {
        printf("Erro: elemento não encontrado\n");
    }
}

// Função para imprimir toda a lista
void imprimirLista(ListaSequencial *lista)
{
    printf("Lista: ");
    for (int i = 0; i < lista->size; i++)
    {
        printf("%d ", lista->items[i]);
    }
    printf("\n");
}

int main()
{
    ListaSequencial lista;
    inicializarLista(&lista);

    // Exemplo de uso das funções
    inserirPrimeiro(&lista, 5);
    inserirPrimeiro(&lista, 3);
    inserirUltimo(&lista, 7);
    imprimirLista(&lista);

    modificarElemento(&lista, 1, 9);
    imprimirLista(&lista);

    removerPrimeiro(&lista);
    imprimirLista(&lista);

    removerUltimo(&lista);
    imprimirLista(&lista);

    removerElemento(&lista, 9);
    imprimirLista(&lista);

    return 0;
}
