#include <stdio.h>

int main()
{
    float n1 = 0.0;
    float n2 = 0.0;
    float media = 0.0;

    printf("Informe a primeira nota:\n");
    scanf("%f", &n1);
    printf("Informe a segunda nota:\n");
    scanf("%f", &n2);

    media = ((n1 + n2) / 2);

    if (media >= 7)
    {
        printf("Aluno Aprovado.");
    }
    else if (media < 4)
    {
        printf("Aluno Reprovado.");
    }
    else if (media <= 4 || media < 7)
    {
        printf("Aluno de Prova Final.");
    }

    return 0;
}