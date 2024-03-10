// Faca um programa que preencha dois vetores de dez elementos inteiros cada um e
//  crie um terceiro vetor resultante da intercalacao entre eles.
// Ao final, o programa deve exibir o vetor criado.

#include <stdio.h>

int main()
{
    int v1[10], v2[10], v3[10], i, i_v1, i_v2, i_v3, turn;

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
    // Se for a ver do vetor v1, turn e 0, se for a vez do vetor v2, turn e 1
    turn = 0;
    // Considerando que o vetor v3 será uma intercalacao dos vetores v1 e v2,
    // seu tamanho deve ser a soma dos espacos preenchidos nos vetores anteriores
    i_v1 = 0;
    i_v2 = 0;
    for (i_v3 = 0; i_v3 < 20; i_v3++)
    {
        // Se o indice estiver num numero par, pega o valor do vetor v2, se não, pega o valor do vetor v1
        if (turn == 0)
        {
            v3[i_v3] = v1[i_v1];
            turn = 1;
            i_v1++;
        }
        else
        {
            if (turn == 1)
            {
                v3[i_v3] = v2[i_v2];
                i_v2++;
                turn = 0;
            }
        }
    }
    printf("Vetor intercalado:\n");

    // Loop para ler os valores no vetor
    for (i = 0; i < 20; i++)
    {

        printf("%d\n", v3[i]);
    }

    return 0;
}