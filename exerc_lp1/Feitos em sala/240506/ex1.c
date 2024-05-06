// Escreva um alg em C que verifique se um arquivo texto fornecido
// como argumento na lonha de comando existe ou nao

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Erro: Informe o nome do arquivo como argumento\n");
        return 1;
    }

    FILE *arq = fopen(argv[1], "r");

    if (arq == NULL)
    {
        printf("Arquivo %s nao existe\n", argv[1]);
    }
    else
    {
        printf("Arquivo %s existe\n", argv[1]);
        fclose(arq);
    }

    return 0;
}

