// Escreva uma funcao que multiplique todos os elementos de um array por uma
//  constante, utilizando ponteiros
#include <stdio.h>

// Função para multiplicar todos os elementos de um array por uma constante
void multiplicarPorConstante(int *array, int tamanho, int constante)
{
    // Percorre o array usando ponteiros
    for (int *ptr = array; ptr < array + tamanho; ptr++)
    {
        // Multiplica cada elemento pelo valor da constante
        *ptr *= constante;
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(array) / sizeof(array[0]);
    int constante = 2;

    printf("Array original:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Chamada da função para multiplicar os elementos do array pela constante
    multiplicarPorConstante(array, tamanho, constante);

    printf("Array após multiplicação por %d:\n", constante);
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
