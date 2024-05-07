// Escreva uma funcao que verifique se uma string e um palindromo usando ponteiros.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se uma string é um palíndromo
int ehPalindromo(char *str)
{
    // Inicializa dois ponteiros para percorrer a string
    char *inicio = str;
    char *fim = str + strlen(str) - 1;

    // Enquanto os ponteiros não se cruzam
    while (inicio < fim)
    {
        // Ignora caracteres não alfanuméricos na parte inicial
        while (!isalnum(*inicio) && inicio < fim)
        {
            inicio++;
        }
        // Ignora caracteres não alfanuméricos na parte final
        while (!isalnum(*fim) && inicio < fim)
        {
            fim--;
        }
        // Converte ambos os caracteres para minúsculas antes de comparar
        if (tolower(*inicio) != tolower(*fim))
        {
            // Se os caracteres não forem iguais, não é um palíndromo
            return 0;
        }
        // Move os ponteiros para o próximo par de caracteres
        inicio++;
        fim--;
    }
    // Se chegarmos aqui, a string é um palíndromo
    return 1;
}

int main()
{
    char str[100];
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remova a quebra de linha se houver
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';

    if (ehPalindromo(str))
    {
        printf("A string é um palíndromo.\n");
    }
    else
    {
        printf("A string não é um palíndromo.\n");
    }

    return 0;
}
