// Ler o conteudo de um arquivo de texto e exibi lo na tela
#include <stdio.h>

int main()
{
    FILE *arquivo;
    char linha[100];

    // Abre o arquivo em modo de leitura
    arquivo = fopen("arquivo.txt", "r");

    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê e exibe cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        printf("%s", linha);
    }

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}
