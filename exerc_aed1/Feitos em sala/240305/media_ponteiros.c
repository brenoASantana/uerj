#include <stdio.h>

void leitura(float *p_n1, float *p_n2)
{
	do
	{
		printf("Informe a primeira nota: ");
		scanf("%f", p_n1);
	} while (*p_n1 < 0);
	do
	{
		printf("Informe a segunda nota: ");
		scanf("%f", p_n2);
	} while (*p_n2 < 0);
}

float calcular_media(float n1, float n2)
{
	return (n1 + n2) / 2;
}

int main()
{
	float n1, n2, media = 0.0;

	for (int i = 0; i <= 15; i++)
	{
		leitura(&n1, &n2);
		media = calcular_media(n1, n2);
		printf("Media do aluno %d: %.2f\n", (i + 1), media);
	}
}
