// Escreva um alg em C que copie o conteudo de um arquivo de origem p/ um arquivo de destino.
// O programa deve aceitar o nome da origem e o dos destino como argumentos

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *arquivo_origem, *arquivo_destino;
    char caractere;

    // Verifica se foram passados argumentos corretos na linha de comando
    if (argc != 3)
    {
        printf("Uso: %s <arquivo_origem> <arquivo_destino>\n", argv[0]);
        return 1;
    }

    // Abre o arquivo de origem em modo de leitura
    arquivo_origem = fopen(argv[1], "r");

    // Verifica se o arquivo de origem foi aberto corretamente
    if (arquivo_origem == NULL)
    {
        printf("Erro ao abrir o arquivo de origem.\n");
        return 1;
    }

    // Abre o arquivo de destino em modo de escrita
    arquivo_destino = fopen(argv[2], "w");

    // Verifica se o arquivo de destino foi aberto corretamente
    if (arquivo_destino == NULL)
    {
        printf("Erro ao abrir o arquivo de destino.\n");
        fclose(arquivo_origem);
        return 1;
    }

    // Copia o conteúdo do arquivo de origem para o arquivo de destino
    while ((caractere = fgetc(arquivo_origem)) != EOF)
    {
        fputc(caractere, arquivo_destino);
    }

    // Fecha os arquivos
    fclose(arquivo_origem);
    fclose(arquivo_destino);

    printf("Conteúdo copiado de %s para %s com sucesso.\n", argv[1], argv[2]);

    return 0;
}
