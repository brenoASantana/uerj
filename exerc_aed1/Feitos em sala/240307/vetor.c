// Faca um programa que preencha dois vetores de dez elementos inteiros cada um e
//  crie um terceiro vetor resultante da intercalacao entre eles.
// Ao final, o programa deve exibir o vetor criado.

#include <stdio.h>

int main()
{
    int v1[10];
    int v2[10];
    int v3[10];
    int i;

    // Loop para atribuir valores no vetor v1
    for (i = 0; i < 10; i++)
    {
        printf("Informe o valor %d do primeiro vetor:\n", (i + 1));
        scanf("%d", &v1[i]);
    }

    // Loop para atribuir valores no vetor v2
    for (i = 0; i < 10; i++)
    {
        printf("Informe o valor %d do segundo vetor:\n", (i + 1));
        scanf("%d", &v2[i]);
    }

    // Loop para atribuir valores no vetor v3
    // Considerando que o vetor v3 será uma intercalacao dos vetores v1 e v2,
    // seu tamanho deve ser a soma dos espacos preenchidos nos vetores anteriores
    for (i = 1; i < 21; i++)
    {
        // Se o indice estiver num numero par, pega o valor do vetor v2, se não, pega o valor do vetor v1
        if (i % 2 == 0)
        {
            v3[i] = v2[i];
        }
        else
        {
            v3[i] = v1[i];
        }
    }
    printf("Vetor intercalado:\n");
    // Loop para ler os valores no vetor
    for (i = 0; i <= 20; i++)
    {

        printf("%d\n", v3[i]);
    }

    return 0;
}