// Ler o conteudo de um arquivo de texto e exibi lo na tela
#include <stdio.h>
#include <stdlib.h>

int main() {
    char texto[100];
    FILE *arq;
    arq = fopen("ex1.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; // Exit with error
    }

    if (fgets(texto, 100, arq) != NULL) {
        printf("%s", texto);
    } else {
        printf("Erro ao ler o arquivo.\n");
    }

    fclose(arq);

    return 0;
}
