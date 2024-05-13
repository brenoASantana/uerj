//Escreva um programa em C que abra um arquivo em modo escrita, escreva "Ola, mundo" nele. Certifique-se
//de fechar o arquivo apos a escrita

#include <stdio.h>

int main(int argc, char *argv[]) {
    // Verifica se o número de argumentos é válido
    if (argc != 2) {
        printf("Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1; // Retorna 1 para indicar erro
    }

    // Declara um ponteiro para o arquivo
    FILE *arquivo;

    // Abre o arquivo em modo de escrita ("w")
    arquivo = fopen(argv[1], "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        return 1; // Retorna 1 para indicar erro
    }

    // Escreve "Olá, mundo" no arquivo
    fprintf(arquivo, "Olá, mundo");

    // Fecha o arquivo
    fclose(arquivo);

    printf("Texto foi escrito no arquivo com sucesso!\n");

    return 0;
}
