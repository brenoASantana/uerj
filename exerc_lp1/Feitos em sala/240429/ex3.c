// Escreva um alg em C que conte o numeros de palavras em um arquivo de texto e crie um novo arquivo contendo essa contagem
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *arquivo_leitura, *arquivo_escrita;
    char caractere;
    int contador_palavras = 0;
    int dentro_palavra = 0;

    // Abre o arquivo de leitura em modo de leitura
    arquivo_leitura = fopen("arquivo.txt", "r");

    // Verifica se o arquivo de leitura foi aberto corretamente
    if (arquivo_leitura == NULL)
    {
        printf("Erro ao abrir o arquivo de leitura.\n");
        return 1;
    }

    // Conta o número de palavras no arquivo
    while ((caractere = fgetc(arquivo_leitura)) != EOF)
    {
        if (isspace(caractere))
        {
            dentro_palavra = 0;
        }
        else if (!dentro_palavra)
        {
            dentro_palavra = 1;
            contador_palavras++;
        }
    }

    // Fecha o arquivo de leitura
    fclose(arquivo_leitura);

    // Abre o arquivo de escrita em modo de escrita
    arquivo_escrita = fopen("contagem_palavras.txt", "w");

    // Verifica se o arquivo de escrita foi aberto corretamente
    if (arquivo_escrita == NULL)
    {
        printf("Erro ao abrir o arquivo de escrita.\n");
        return 1;
    }

    // Escreve a contagem de palavras no arquivo de escrita
    fprintf(arquivo_escrita, "O número de palavras no arquivo é: %d\n", contador_palavras);

    // Fecha o arquivo de escrita
    fclose(arquivo_escrita);

    printf("Contagem de palavras salva com sucesso no arquivo.\n");

    return 0;
}

return 0;
}