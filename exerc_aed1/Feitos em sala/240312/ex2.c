// Em uma escola é necessário armazenar os dados de diversos alunos. Defina uma struct para armazenar os dados de um aluno: nome, matrícula,
// quatro notas e a média final. Faça um programa para armazenar esses dados e imprimir a média do aluno.
#include <stdio.h>

typedef struct aluno
{
    char nome[50];
    int matricula;
    float n1, n2, n3, n4, media;
} aluno;

int main()
{
    aluno aluno;

    printf("Informe o nome do aluno: ");
    fflush(stdin);
    gets(aluno.nome);

    printf("\nInforme a matricula do aluno: ");
    scanf("%d", &aluno.matricula);

    printf("\nInforme a nota 1 do aluno: ");
    scanf("%f", &aluno.n1);

    printf("\nInforme a nota 2 do aluno: ");
    scanf("%f", &aluno.n2);

    printf("\nInforme a nota 3 do aluno: ");
    scanf("%f", &aluno.n3);

    printf("\nInforme a nota 4 do aluno: ");
    scanf("%f", &aluno.n4);

    aluno.media = ((aluno.n1 + aluno.n2 + aluno.n3 + aluno.n4) / 4);

    printf("\nMedia do aluno: %.2f", aluno.media);

    return 0;
}