// Escreva um algoritmo em C que recebe uma lista de números inteiros do usuário e armazena esses números em um vetor dinâmico usando alocação de memória.
// Em seguida, o programa deve imprimir os números inseridos pelo usuário.

#include <stdio.h>

int main()
{
    int n;
    int quant = 0;

    printf("Insira a quantidade de números que deseja inserir: ");
    scanf("%d", &quant);


    int *vetor = malloc(quant);

    return 0;
}