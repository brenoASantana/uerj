#include <stdio.h>

int main()
{
    float n1 = 0.0;
    float n2 = 0.0;
    float mediaAluno = 0.0;
    float mediaTurma = 0.0;
    int numAlunos = 0;

    int continuar = 1;

    while (continuar != 0)
    {
        printf("Informe a primeira nota:\n");
        scanf("%f", &n1);
        printf("Informe a segunda nota:\n");
        scanf("%f", &n2);

        mediaAluno = ((n1 + n2) / 2);

        if (mediaAluno >= 7)
        {
            printf("Media: %.2f. Aluno Aprovado. \n", mediaAluno);
        }
        else if (mediaAluno < 4)
        {
            printf("Media: %.2f. Aluno Reprovado.\n", mediaAluno);
        }
        else if (mediaAluno <= 4 || mediaAluno < 7)
        {
            printf("Media: %.2f. Aluno de Prova Final.\n", mediaAluno);
        }

        mediaTurma += mediaAluno;
        numAlunos += 1;

        printf("Deseja continuar? Digite qualquer numero para sim e 0 para nao.\n");
        scanf("%i", &continuar);
    }

    mediaTurma = mediaTurma / numAlunos;

    printf("Media da turma: %.2f", mediaTurma);
    return 0;
}