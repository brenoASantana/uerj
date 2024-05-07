#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FUNCIONARIOS 50
#define MAX_NOME 50
#define MAX_ENDERECO 100

// Estrutura para armazenar os dados de um funcionário
typedef struct {
    char nome[MAX_NOME];
    char endereco[MAX_ENDERECO];
    int qtdFilhos;
    float salario;
} Funcionario;

// Função para cadastrar um novo funcionário
void cadastrarFuncionario(Funcionario funcionarios[], int *numFuncionarios) {
    if (*numFuncionarios >= MAX_FUNCIONARIOS) {
        printf("Limite de funcionários atingido!\n");
        return;
    }

    printf("Cadastro do Funcionário %d\n", *numFuncionarios + 1);
    printf("Nome: ");
    scanf(" %[^\n]", funcionarios[*numFuncionarios].nome);
    printf("Endereço: ");
    scanf(" %[^\n]", funcionarios[*numFuncionarios].endereco);
    printf("Quantidade de filhos: ");
    scanf("%d", &funcionarios[*numFuncionarios].qtdFilhos);
    printf("Salário: ");
    scanf("%f", &funcionarios[*numFuncionarios].salario);

    (*numFuncionarios)++;
}

// Função para buscar um funcionário pelo nome
void buscarFuncionario(Funcionario funcionarios[], int numFuncionarios, char nomeBusca[]) {
    int encontrado = 0;
    for (int i = 0; i < numFuncionarios; i++) {
        if (strcmp(funcionarios[i].nome, nomeBusca) == 0) {
            printf("\nFuncionário encontrado:\n");
            printf("Nome: %s\n", funcionarios[i].nome);
            printf("Endereço: %s\n", funcionarios[i].endereco);
            printf("Quantidade de filhos: %d\n", funcionarios[i].qtdFilhos);
            printf("Salário: %.2f\n", funcionarios[i].salario);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("\nFuncionário não encontrado.\n");
    }
}

int main() {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int numFuncionarios = 0;
    char nomeBusca[MAX_NOME];

    printf("Cadastro de Funcionários\n");
    printf("========================\n");

    // Cadastro de 50 funcionários
    for (int i = 0; i < MAX_FUNCIONARIOS; i++) {
        printf("\n");
        cadastrarFuncionario(funcionarios, &numFuncionarios);
    }

    // Busca por um funcionário específico
    printf("\nBuscar por funcionário\n");
    printf("Nome do funcionário: ");
    scanf(" %[^\n]", nomeBusca);
    buscarFuncionario(funcionarios, numFuncionarios, nomeBusca);

    return 0;
}
