#include <stdio.h>

float dolarParaReal(float quantDolar, float cotacaoDolar)
{

    return quantDolar * cotacaoDolar;
}

int main()
{
    float quantDolar, cotacaoDolar = 0.0;

    do
    {
        printf("Informe a quantidade de dolar:");
        scanf("%f", &quantDolar);
    } while (quantDolar <= 0.0);

    do
    {
        printf("\nInforme a cotacao do dolar:");
        scanf("%f", &cotacaoDolar);
    } while (cotacaoDolar <= 0.0);

    printf("\nO valor convertido para dolar e: %.2f", dolarParaReal(quantDolar, cotacaoDolar));
    return 0;
}