// Escreva um alg em C que proure por uma palavra chave em um arquivo de um texto
// fornecido como argumento. Imprima as linhas onde a palavra foi encontrado

// #include <stdio.h>

// // int main(int argC, char *argv[])
// // {

// //     return 0;
// // }


#include <stdio.h>

int main(int argC, char *argv[]) {
    // Abrindo o arquivo para leitura
    FILE *arq;
    arq = fopen(argv[1], "r");
    char word_search;
    char linha[100];
    while (fgets(linha, sizeof(linha), arq) != NULL) {
        if(word_search == linha){
            printf("Palavra encontrada");
        }
    }

    // Fechando o arquivo após a leitura
    fclose(arq);

    return 0;
}


