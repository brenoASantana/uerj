// Escreva um alg em C que proure por uma palavra chave em um arquivo de um texto
// fornecido como argumento. Imprima as linhas onde a palavra foi encontrado

// #include <stdio.h>

// // int main(int argC, char *argv[])
// // {

// //     return 0;
// // }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[])
{
    FILE *arquivo;
    char linha[MAX_LINE_LENGTH];
    char *palavra_chave;

    // Verifica se foi passado um argumento na linha de comando
    if (argc != 3)
    {
        printf("Uso: %s <nome_do_arquivo> <palavra_chave>\n", argv[0]);
        return 1;
    }

    // Tenta abrir o arquivo em modo de leitura
    arquivo = fopen(argv[1], "r");

    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s.\n", argv[1]);
        return 1;
    }

    // Lê o argumento da palavra-chave
    palavra_chave = argv[2];

    // Lê cada linha do arquivo e verifica se a palavra-chave está presente
    int numero_linha = 1;
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        if (strstr(linha, palavra_chave) != NULL)
        {
            printf("Palavra-chave encontrada na linha %d: %s", numero_linha, linha);
        }
        numero_linha++;
    }

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}
