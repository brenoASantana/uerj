// Considere que você foi contratado para fazer parte de uma equipe de desenvolvimento e precisa fazer inicialmente um cadastro de produtos de um determinado estoque, com as seguintes informações para cada produto:
// • Código de identificação do produto: representado por um valor inteiro.
// • Nome do produto: com até 50 caracteres.
// • Quantidade disponível no estoque: representado por um número inteiro.
// • Preço de venda: representado por um valor real.
// Para isso, você deve:
//(a) Definir uma estrutura, denominada produto, que tenha os campos apropriados para guardar as informações de um produto.
//(b) Alocar espaço dinamicamente para armazenar 10 produtos e pedir ao usuário para entrar com as informações de cada produto, enquanto ele desejar.
//(c) Obter o maior preço de venda.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto
{
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

int main()
{
    Produto *produtos = NULL;
    int quantidadeProdutos = 0;
    float maiorPreco = 0.0;
    char continuar;

    printf("Cadastro de Produtos\n");

    do
    {
        produtos = (Produto *)realloc(produtos, (quantidadeProdutos + 1) * sizeof(Produto));

        if (produtos == NULL)
        {
            printf("Erro de alocação de memória.\n");
            return 1;
        }

        printf("Codigo: ");
        scanf("%d", &produtos[quantidadeProdutos].codigo);
        printf("Nome: ");
        scanf("%s", produtos[quantidadeProdutos].nome);
        printf("Quantidade: ");
        scanf("%d", &produtos[quantidadeProdutos].quantidade);
        printf("Preco: ");
        scanf("%f", &produtos[quantidadeProdutos].preco);

        quantidadeProdutos++;

        if (quantidadeProdutos >= 10)
        {
            printf("Limite de produtos atingido.\n");
            break;
        }

        printf("Deseja cadastrar outro produto? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's');

    printf("\nProdutos cadastrados:\n");

    for (int i = 0; i < quantidadeProdutos; i++)
    {
        printf("Codigo: %d, Nome: %s, Quantidade: %d, Preco: %.2f\n",
               produtos[i].codigo, produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
    }

    for (int i = 0; i < quantidadeProdutos; i++)
    {
        if (produtos[i].preco > maiorPreco)
        {
            maiorPreco = produtos[i].preco;
        }
    }

    printf("\nMaior preco de venda encontrado: %.2f\n", maiorPreco);

    printf("\nProdutos com o maior preco de venda:\n");

    for (int i = 0; i < quantidadeProdutos; i++)
    {
        if (produtos[i].preco == maiorPreco)
        {
            printf("Codigo: %d, Nome: %s, Quantidade: %d, Preco: %.2f\n",
                   produtos[i].codigo, produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
        }
    }

    free(produtos);

    return 0;
}
