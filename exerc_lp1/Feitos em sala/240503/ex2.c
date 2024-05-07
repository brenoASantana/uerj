// Escreva um alg em C que concatene o conteudo de dois arquivos de texto em
// um terceiro arquivo. O programa deve aceitar os 3 como argumentos
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *arquivo1, *arquivo2, *arquivo_concatenado;
    char caractere;

    // Verifica se foram passados argumentos corretos na linha de comando
    if (argc != 4)
    {
        printf("Uso: %s <arquivo1> <arquivo2> <arquivo_concatenado>\n", argv[0]);
        return 1;
    }

    // Abre o primeiro arquivo em modo de leitura
    arquivo1 = fopen(argv[1], "r");

    // Verifica se o primeiro arquivo foi aberto corretamente
    if (arquivo1 == NULL)
    {
        printf("Erro ao abrir o primeiro arquivo.\n");
        return 1;
    }

    // Abre o segundo arquivo em modo de leitura
    arquivo2 = fopen(argv[2], "r");

    // Verifica se o segundo arquivo foi aberto corretamente
    if (arquivo2 == NULL)
    {
        printf("Erro ao abrir o segundo arquivo.\n");
        fclose(arquivo1);
        return 1;
    }

    // Abre o arquivo concatenado em modo de escrita
    arquivo_concatenado = fopen(argv[3], "w");

    // Verifica se o arquivo concatenado foi aberto corretamente
    if (arquivo_concatenado == NULL)
    {
        printf("Erro ao abrir o arquivo concatenado.\n");
        fclose(arquivo1);
        fclose(arquivo2);
        return 1;
    }

    // Concatena o conteúdo do primeiro arquivo no arquivo concatenado
    while ((caractere = fgetc(arquivo1)) != EOF)
    {
        fputc(caractere, arquivo_concatenado);
    }

    // Concatena o conteúdo do segundo arquivo no arquivo concatenado
    while ((caractere = fgetc(arquivo2)) != EOF)
    {
        fputc(caractere, arquivo_concatenado);
    }

    // Fecha os arquivos
    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo_concatenado);

    printf("Conteúdo dos arquivos concatenado com sucesso em %s.\n", argv[3]);

    return 0;
}
