// Escreva um algoritmo em C que substitua todas as ocorrencias de uma palavra por outra em um arquivo
// fornecido como argumento. PS.: Pode criar um novo arquivo com substituições

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[])
{
    FILE *arquivo_entrada, *arquivo_saida;
    char linha[MAX_LINE_LENGTH];
    char *palavra_antiga, *palavra_nova;

    // Verifica se foram passados argumentos corretos na linha de comando
    if (argc != 5)
    {
        printf("Uso: %s <arquivo_entrada> <arquivo_saida> <palavra_antiga> <palavra_nova>\n", argv[0]);
        return 1;
    }

    // Tenta abrir o arquivo de entrada em modo de leitura
    arquivo_entrada = fopen(argv[1], "r");

    // Verifica se o arquivo de entrada foi aberto corretamente
    if (arquivo_entrada == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada %s.\n", argv[1]);
        return 1;
    }

    // Tenta abrir o arquivo de saída em modo de escrita
    arquivo_saida = fopen(argv[2], "w");

    // Verifica se o arquivo de saída foi aberto corretamente
    if (arquivo_saida == NULL)
    {
        printf("Erro ao abrir o arquivo de saída %s.\n", argv[2]);
        fclose(arquivo_entrada);
        return 1;
    }

    // Lê as palavras antigas e novas fornecidas como argumentos
    palavra_antiga = argv[3];
    palavra_nova = argv[4];

    // Substitui as ocorrências da palavra antiga pela palavra nova em cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo_entrada) != NULL)
    {
        char *ocorrencia = strstr(linha, palavra_antiga);
        while (ocorrencia != NULL)
        {
            memcpy(ocorrencia, palavra_nova, strlen(palavra_nova));
            ocorrencia = strstr(ocorrencia + strlen(palavra_nova), palavra_antiga);
        }
        fputs(linha, arquivo_saida);
    }

    // Fecha os arquivos
    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    printf("Substituição realizada com sucesso.\n");

    return 0;
}
