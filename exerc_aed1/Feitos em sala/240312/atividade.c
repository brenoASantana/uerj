// Escreva um programa em C para o cadastramento de compromissos. Seu programa deve definir um vetor de registros, conforme os seguintes tipos de dados:
//     - Horário: composto de hora, minutos e segundos.
//     - Data: composto de dia, mês e ano.
//     - Compromisso: composto de uma data, horário e um texto que descreve o compromisso.
// O programa deve permitir que o usuário agende os compromissos de acordo com sua vontade ou até atingir o limite de 20 compromissos.
// Ao final, o programa deve exibir os compromissos cadastrados.

#include <stdio.h>
#define lim 20

typedef struct horario
{
    int h, m, s;
} horario;

typedef struct data
{
    int d, m, a;
} data;

typedef struct compromisso
{
    horario horario;
    data data;
    char descricao[50];
} compromisso;

int main()
{
    horario listaHorarios[lim];
    data listaDatas[lim];
    compromisso compromissos[lim];

    int op = 0;
    int i;
    int numCompromissos = 0; // Variável para rastrear o número atual de compromissos

    while (op == 0 && numCompromissos < lim)
    {
        for (i = 0; i < lim; i++)
        {
            printf("\nInforme a hora do compromisso: ");
            scanf("%d", &listaHorarios[numCompromissos].h);
            printf("\nInforme o minuto do compromisso: ");
            scanf("%d", &listaHorarios[numCompromissos].m);
            printf("\nInforme o segundo do compromisso: ");
            scanf("%d", &listaHorarios[numCompromissos].s);

            printf("\nInforme o dia do compromisso: ");
            scanf("%d", &listaDatas[numCompromissos].d);
            printf("\nInforme o mes do compromisso: ");
            scanf("%d", &listaDatas[numCompromissos].m);
            printf("\nInforme o ano do compromisso: ");
            scanf("%d", &listaDatas[numCompromissos].a);

            compromissos[numCompromissos].horario = listaHorarios[numCompromissos];
            compromissos[numCompromissos].data = listaDatas[numCompromissos];

            printf("\nDescreva o compromisso: ");
            fflush(stdin);
            fgets(compromissos[numCompromissos].descricao, 50, stdin);

            numCompromissos++; // Incrementa o número de compromissos cadastrados

            if (numCompromissos >= lim)
            {
                printf("\nLimite de compromissos atingido.\n");
                break;
            }

            printf("\nDeseja continuar? 0 - Sim | 1 - Nao: ");
            scanf("%d", &op);
            if (op != 0)
                break;
        }
    }

    for (i = 0; i < numCompromissos; i++)
    {
        printf("%02d:%02d:%02d ", compromissos[i].horario.h, compromissos[i].horario.m, compromissos[i].horario.s);
        printf("%02d/%02d/%04d ", compromissos[i].data.d, compromissos[i].data.m, compromissos[i].data.a);
        printf("%s\n", compromissos[i].descricao);
    }

    return 0;
}
