// Em uma escola é necessário armazenar os dados de diversos alunos. Defina uma struct para armazenar os dados de um aluno: nome, matrícula,
// quatro notas e a média final. Faça um programa para armazenar esses dados e imprimir a média do aluno.
#include <stdio.h>
#define numAlunos 20

typedef struct aluno
{
    char nome[50];
    int matricula;
    float n1, n2, n3, n4, media;
} aluno;

int main()
{
    float media_turma;
    int i;
    aluno aluno[numAlunos];

    for (i = 0; i < numAlunos; i++)
    {
        printf("\nInforme o nome do aluno: ");
        fflush(stdin);
        gets(aluno[i].nome);

        printf("\nInforme a matricula do aluno: ");
        scanf("%d", &aluno[i].matricula);

        printf("\nInforme a nota 1 do aluno: ");
        scanf("%f", &aluno[i].n1);

        printf("\nInforme a nota 2 do aluno: ");
        scanf("%f", &aluno[i].n2);

        printf("\nInforme a nota 3 do aluno: ");
        scanf("%f", &aluno[i].n3);

        printf("\nInforme a nota 4 do aluno: ");
        scanf("%f", &aluno[i].n4);

        aluno[i].media = ((aluno[i].n1 + aluno[i].n2 + aluno[i].n3 + aluno[i].n4) / 4);

        printf("\nMedia do aluno: %.2f", aluno[i].media);

        media_turma += aluno[i].media;
    }

    media_turma = media_turma / numAlunos;

    printf("\nMedia da turma: %.2f", media_turma);

    return 0;
}