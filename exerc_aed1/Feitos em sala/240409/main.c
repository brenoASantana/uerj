#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 30
#define MAX_NOME 50
#define MAX_CPF 15
#define MAX_TELEFONE 15

typedef struct Aluno
{
    int matricula;
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
    char telefone[MAX_TELEFONE];
} Aluno;

Aluno alunos[MAX_ALUNOS];
int num_alunos = 0;

void cadastrarAluno()
{
    if (num_alunos >= MAX_ALUNOS)
    {
        printf("Erro: Capacidade maxima de alunos atingida.\n");
        return;
    }

    Aluno *aluno = &alunos[num_alunos];

    printf("Matricula: ");
    scanf("%d", &(aluno->matricula));

    printf("Nome: ");
    getchar();
    gets(aluno->nome);

    printf("CPF: ");
    scanf("%s", aluno->cpf);

    printf("Telefone: ");
    scanf("%s", aluno->telefone);

    num_alunos++;

    printf("Aluno cadastrado com sucesso.\n");
}

void buscarAluno()
{
    int matricula;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);

    for (int i = 0; i < num_alunos; i++)
    {
        if (alunos[i].matricula == matricula)
        {
            Aluno *aluno = &alunos[i];
            printf("Matricula: %d\n", aluno->matricula);
            printf("Nome: %s\n", aluno->nome);
            printf("CPF: %s\n", aluno->cpf);
            printf("Telefone: %s\n", aluno->telefone);
            return;
        }
    }

    printf("Aluno nao encontrado.\n");
}

void exibirAlunos()
{
    if (num_alunos == 0)
    {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("*** Lista de Alunos ***\n");
    for (int i = 0; i < num_alunos; i++)
    {
        Aluno *aluno = &alunos[i];
        printf("Matricula: %d\n", aluno->matricula);
        printf("Nome: %s\n", aluno->nome);
        printf("CPF: %s\n", aluno->cpf);
        printf("Telefone: %s\n", aluno->telefone);
        printf("----------------------\n");
    }
}

void removerAluno()
{
    int matricula;
    printf("Digite a matricula do aluno a ser removido: ");
    scanf("%d", &matricula);

    for (int i = 0; i < num_alunos; i++)
    {
        if (alunos[i].matricula == matricula)
        {
            for (int j = i; j < num_alunos - 1; j++)
            {
                alunos[j] = alunos[j + 1];
            }
            num_alunos--;
            printf("Aluno removido com sucesso.\n");
            return;
        }
    }

    printf("Aluno nao encontrado.\n");
}

int main()
{
    int opcao;

    do
    {
        printf("*** Sistema de alunos ***\n");
        printf("1- Cadastrar aluno\n");
        printf("2- Buscar aluno pela matricula\n");
        printf("3- Exibir os dados dos alunos\n");
        printf("4- Remover um aluno\n");
        printf("5- Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarAluno();
            break;
        case 2:
            buscarAluno();
            break;
        case 3:
            exibirAlunos();
            break;
        case 4:
            removerAluno();
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }

    } while (opcao != 5);

    return 0;
}
