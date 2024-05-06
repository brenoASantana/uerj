// Escreva um algoritmo em C que permita ao usuario inserir uma quantidade variavel de n inteiros em um vetor.
// Use alocacao dinamica e umprima a soma dos n inseridos

// ex:
/*
int *vetor;
vetor = (int *)malloc(tamanho*sizeof(int));
(...)
for (i=0; i<tamanho; i++)
{
   x = vetor[i];
   // ou
   x = *vetor;
   vetor++;
}
(...)
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vetor, n, i, sumPonteiro = 0, sumColchetes = 0;

    do
    {
        printf("Informe a quantidade positiva de inteiros a serem inseridos: ");
        scanf("%d", &n);
    } while (n <= 0);

    vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL)
    {
        printf("\nVetor comprometido!");
        return 1;
    }

    // loop para inserir os inteiros no vetor
    for (i = 0; i < n; i++)
    {
        printf("\nInforme o inteiro %d: ", (i + 1));
        scanf("%d", &vetor[i]);
        sumColchetes += vetor[i];
    }

    // loop para imprimir a soma por ponteiro dos inteiros;
    for (i = 0; i < n; i++)
    {
        sumPonteiro += *vetor;
        vetor++;
    }

    printf("A soma por colchetes dos inteiros inseridos eh: %d\n", sumColchetes);
    printf("A soma por ponteiro dos inteiros inseridos eh: %d\n", sumPonteiro);

    return 0;
}