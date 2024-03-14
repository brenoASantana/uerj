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

    printf("\nInforme o nome do produto: ");
    fflush(stdin);
    gets(prod.nome);

    printf("\nInforme a quantidade em estoque do produto: ");
    scanf("%d", &prod.quantEstoque);

    printf("\nInforme o preco de compra do produto: ");
    scanf("%f", &prod.precoCompra);

    printf("\nInforme o preco de venda do produto: ");
    scanf("%f", &prod.precoVenda);

    printf("\n%d\n", prod.cod);
    puts(prod.nome);
    printf("\n%d", prod.quantEstoque);
    printf("\n%.2f", prod.precoCompra);
    printf("\n%.2f", prod.precoVenda);
    return 0;
}