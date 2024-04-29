#include <stdio.h>
const int MAX = 15;

typedef struct pilhaSeq
{
    int valores[MAX];
    int topo;
} pilhaSeq;

int main()
{
    int num;
    
    printf("Informe um valor: ");
    scanf("%d", num);

    return 0;
}