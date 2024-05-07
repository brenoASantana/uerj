// Escreva um alg em C que verifique se um arquivo texto fornecido
// como argumento na linha de comando existe ou nao

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *arquivo;

    // Verifica se foi passado um argumento na linha de comando
    if (argc != 2) {
        printf("Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }

    // Tenta abrir o arquivo em modo de leitura
    arquivo = fopen(argv[1], "r");

    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("O arquivo %s não existe ou não pode ser aberto.\n", argv[1]);
        return 1;
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("O arquivo %s existe e pode ser aberto.\n", argv[1]);

    return 0;
}
