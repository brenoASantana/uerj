//Abra um arquivo em modo de leitura e imprima seu conteudo na tela. Feche o arquivo ao fim

#include <stdio.h>

int main() {
    FILE *arquivo;
    char linha[100]; // Tamanho máximo de uma linha
    
    // Abre o arquivo em modo de leitura
    arquivo = fopen("nome_do_arquivo.txt", "r");

    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; // Retorna um código de erro
    }

    // Lê e imprime cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}
