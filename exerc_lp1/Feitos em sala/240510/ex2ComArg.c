//Abra um arquivo em modo de leitura e imprima seu conteudo na tela. Feche o arquivo ao fim

#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *arquivo;
    char linha[100]; // Tamanho máximo de uma linha
    
    // Verifica se o número de argumentos é válido
    if (argc != 2) {
        printf("Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1; // Retorna um código de erro
    }

    // Abre o arquivo em modo de leitura
    arquivo = fopen(argv[1], "r");

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
