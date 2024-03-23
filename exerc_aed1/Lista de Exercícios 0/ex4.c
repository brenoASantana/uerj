#include <stdio.h>

int main()
{
    int numConta, numClientes, numClientesNegativos = 0;
    float saldoConta, somaSaldo;
    while (numClientes >= 10000)
    {
        printf("\nDigite o numero da conta: ");
        scanf("%d", &numConta);
        if (numConta == -999)
        {
            break;
        }
        printf("\nDigite o saldo da conta: ");
        scanf("%f", &saldoConta);
        if (saldoConta < 0)
        {
            numClientesNegativos++;
        }
        numClientes++;
        somaSaldo += saldoConta;
    }
    printf("Numero de clientes com saldo negativo: %d\n", numClientesNegativos);
    printf("Numero de clientes: %d\n", numClientes);
    printf("Saldo da agencia: %f\n", somaSaldo);
    return 0;
}