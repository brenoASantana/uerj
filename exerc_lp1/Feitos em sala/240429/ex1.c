#include <stdio.h>
// Ler o conteudo de um arquivo de texto e exibi lo na tela
int main(){
    char texto[100];
    FILE *arq;
    arq = fopen("ex1.txt","r");
    char result = fgets(texto, 100, arq);

    if(!arq)
        prinf("Erro na abertura ");

    if(result){
        printf("%s",texto);
    }


    fclose(arq);

    return 0;
}