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
    horario horario[lim];
    data data[lim];
    compromisso compromisso[lim];

    int op = 0;
    int i;
    while (op == 0)
    {
        for (i = 0; i < lim; i++)
        {
            printf("\nInforme a hora do compromisso: ");
            scanf("%d", &horario[i].h);
            printf("\nInforme o minuto do compromisso: ");
            scanf("%d", &horario[i].m);
            printf("\nInforme o segundo do compromisso: ");
            scanf("%d", &horario[i].s);

            printf("\nInforme o dia do compromisso: ");
            scanf("%d", &data[i].d);
            printf("\nInforme o mes do compromisso: ");
            scanf("%d", &data[i].m);
            printf("\nInforme o ano do compromisso: ");
            scanf("%d", &data[i].a);

            compromisso[i].horario = horario[i];
            compromisso[i].data = data[i];

            printf("\nDescreva o compromisso: ");
            fflush(stdin);
            gets(compromisso[i].descricao);

            printf("\nDeseja continuar? 0 - Sim | 1 - Nao: ");
            scanf("%d", &op);
            if (op != 0)
                break;
        }
    }

    for (i = 0; i < lim; i++)
    {
        printf("%d", compromisso[i].horario);
        printf("%d", compromisso[i].data);
        puts(compromisso[i].descricao);
    }

    return 0;
}