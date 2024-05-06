#include <stdio.h>
typedef struct Lista
{
    int vetor[15];
    int quant;

} Lista;

void iniciarLista(Lista *lista)
{
    lista->quant = 0;
}


void inserir1Elem(Lista *lista, int valor){
    lista->vetor[0] = valor;
}

void inserirUltElem(Lista *lista, int valor){
    lista->vetor[14] = valor;
}

int main()
{
    Lista lista;
    iniciarLista(&lista);
    inserir1Elem(&lista, 1);
    inserirUltElem(&lista, 14);

    return 0;
}