//Escreva um programa em C que abra um arquivo em modo escrita, escreva "Ola, mundo" nele. Certifique-se
//de fechar o arquivo apos a escrita


#include <stdio.h>

int main() {
    // Declara um ponteiro para o arquivo
    FILE *arquivo;

    // Abre o arquivo em modo de escrita ("w")
    arquivo = fopen("saida.txt", "w");

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
