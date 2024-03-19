// Feito por Breno Alexandre Santana Silva e Matheus da Silva de Oliveira
#include <stdio.h>
#define MAX 20

typedef struct professor
{
    int matricula;
    char nome[50];
    float salario;
    int telefone;
} professor;

void leitura(professor *prof, int *numProf)
{

    printf("Digite a matricula do professor: \n");
    scanf("%d", &prof->matricula);

    printf("Digite o nome do professor: \n");
    // fflush(stdin);
    // fgets(prof->nome, 50, stdin);

    printf("Digite o salario do professor: \n");
    scanf("%f", &prof->salario);

    printf("Digite o telefone do professor: \n");
    scanf("%d", &prof->telefone);

    numProf++;
}

void maxSalario(professor *prof, int *numProf)
{
    float maior = 0.0;
    int i;
    for (i = 0; i < *numProf; i++)
    {
        if (prof[i].salario > maior)
            prof[i].salario = maior;
    }
    printf("O maior salario eanh: %.2f\n", maior);
}

int exibirDados(professor *prof, int *numProf)
{
    int i;
    for (i = 0; i < *numProf; i++)
    {
        printf("Matricula: %d\n", prof[i].matricula);
        printf("Nome: %s\n", prof[i].nome);
        printf("Salario: %.2f\n", prof[i].salario);
        printf("Telefone: %d\n", prof[i].telefone);
        printf("\n");
    }
    return 0;
}

int main(void)
{
    int numProf = 0;
    professor prof[20];
    int valor = -1;

    while (0 == 0)
    {
        printf("1. Cadastras professor\n2. Exibir maior salario\n3. Imprimir lista "
               "de professores\n4. Sair\n");
        scanf("%d", &valor);

        switch (valor)
        {
        case 1:
            leitura(&prof[numProf], &numProf);
            continue;
        case 2:
            maxSalario(prof, &numProf);
            continue;
        case 3:
            exibirDados(prof, &numProf);
            continue;
        case 4:
            break;

        default:
            printf("Valor invalido\n");
            continue;
        }

        return 0;
    }
}