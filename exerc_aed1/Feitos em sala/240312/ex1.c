// Faça um programa que utilize uma estrutura para armazenar os dados de um produto. Os dados que devem ser armazenados sao: codigo, nome, quantidade em estoque,
// preco de compra e preco de venda. Leia os dados de um produto e imprima as informacoes.

#include <stdio.h>

typedef struct produto
{
    int cod, quantEstoque;
    float precoCompra, precoVenda;
    char nome[50];
} produto;

int main()
{
    produto prod;
    
    printf("Informe o codigo do produto: ");
    scanf("%d", &prod.cod);

    printf("Informe o nome do produto: ");
    getchar(prod.nome);


    return 0;
}