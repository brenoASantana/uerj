#include <stdio.h>
#define MAX = 30

int menu(int *op)
{
    printf("*** Sistema de alunos ***\n");
    printf("1 - Cadastras aluno\n");
    printf("2 - Buscar aluno pela matricula\n");
    printf("3 - Exibir os dados dos alunos\n\n");
    printf("4 - Remover um aluno\n");
    printf("5 - Sair\n");
    scanf("%d", op);
    return op;
}

int cadastrar(int *op)
{
    printf("*** Sistema de alunos ***\n");
    printf("1 - Cadastras aluno\n");
    printf("2 - Buscar aluno pela matrícula\n");
    printf("3 - Exibir os dados dos alunos\n\n");
    printf("4 - Remover um aluno\n");
    printf("5 - Sair\n");
    scanf("%d", op);
    return op;
}

int buscar(int matricula)
{
    printf("*** Sistema de alunos ***\n");
    printf("1 - Cadastras aluno\n");
    printf("2 - Buscar aluno pela matrícula\n");
    printf("3 - Exibir os dados dos alunos\n\n");
    printf("4 - Remover um aluno\n");
    printf("5 - Sair\n");
    scanf("%d", matricula);
    return matricula;
}

int exibir()
{
    printf("*** Sistema de alunos ***\n");
    printf("1 - Cadastras aluno\n");
    printf("2 - Buscar aluno pela matrícula\n");
    printf("3 - Exibir os dados dos alunos\n\n");
    printf("4 - Remover um aluno\n");
    printf("5 - Sair\n");
    scanf("%d", 0);
    return 0;
}

int remover()
{
    printf("*** Sistema de alunos ***\n");
    printf("1 - Cadastras aluno\n");
    printf("2 - Buscar aluno pela matrícula\n");
    printf("3 - Exibir os dados dos alunos\n\n");
    printf("4 - Remover um aluno\n");
    printf("5 - Sair\n");
    scanf("%d", 0);
    return 0;
}

int main()
{
    int op;

    do
    {
        menu(&op);

        switch (op)
        {
        case 1:
            menu(&op);
        case 2:
            menu(&op);
        case 3:
            menu(&op);
        case 4:
            menu(&op);
        case 5:
            menu(&op);
        default:
            printf("\nOpçao Invalida! Tente Novamente.\n");
        }
    } while (op != 5);

    return 0;
}