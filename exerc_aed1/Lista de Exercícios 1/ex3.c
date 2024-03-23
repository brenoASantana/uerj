#include <stdio.h>
#define TAM 50

typedef struct Animal
{
    char nome[50];
    char raca[50];
    char dataNascimento[10];
    char sexo;
} Animal;

int main()
{
    int numCadastrados = 0;
    int op = 0;
    int sexo;
    Animal animal[TAM];

    while (op == 0 && numCadastrados < TAM)
    {
        printf("Digite o nome do animal: ");
        getchar(); // Para consumir a nova linha pendente no buffer
        fgets(animal[numCadastrados].nome, 50, stdin);

        printf("Digite a raca do animal: ");
        getchar(); // Para consumir a nova linha pendente no buffer
        fgets(animal[numCadastrados].raca, 50, stdin);

        printf("Digite a data de nascimento do animal (01/01/0001): ");
        getchar(); // Para consumir a nova linha pendente no buffer
        fgets(animal[numCadastrados].dataNascimento, 10, stdin);

        printf("Digite o sexo do animal(1-Macho 2-Femea): ");
        scanf("%d", &sexo); // Atualizar op

        if (sexo == 1)
        {
            animal[numCadastrados].sexo = 'M';
        }
        else
        {
            animal[numCadastrados].sexo = 'F';
        }

        numCadastrados++;

        printf("Digite 0 para continuar ou qualquer outro numero para sair: ");
        scanf("%d", &op); // Atualizar op
    }

    for (int i = 0; i < numCadastrados; i++)
    {
        printf("\nNome: %s", animal[i].nome);
        printf("\nRaca: %s", animal[i].raca);
        printf("\nData de Nascimento: %s", animal[i].dataNascimento);
        printf("\nSexo: %c", animal[i].sexo);
    }

    return 0;
}