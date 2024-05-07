// Escreva um alg em C que leia uma mensagem e escreva em um arquivo de texto
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arquivo;
    char mensagem[1000];

    // Solicita ao usuário que digite a mensagem
    printf("Digite a mensagem que deseja armazenar no arquivo:\n");
    fgets(mensagem, sizeof(mensagem), stdin);

    // Abre o arquivo em modo de escrita
    arquivo = fopen("mensagem.txt", "w");

    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Escreve a mensagem no arquivo
    fputs(mensagem, arquivo);

    // Fecha o arquivo
    fclose(arquivo);

    printf("Mensagem escrita no arquivo com sucesso.\n");

    return 0;
}
