// Ler o conteudo de um arquivo de texto e exibi lo na tela
#include <stdio.h>

int main() {
    // Abrindo o arquivo para leitura
    FILE *arq;
    arq = fopen("ex1.txt", "r");

    // Verificando se o arquivo foi aberto corretamente
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1; // Sair com erro
    }

    // Lendo e imprimindo o conteúdo do arquivo linha por linha
    char linha[100];
    while (fgets(linha, sizeof(linha), arq) != NULL) {
        printf("%s", linha);
    }

    // Fechando o arquivo após a leitura
    fclose(arq);

    return 0;
}


