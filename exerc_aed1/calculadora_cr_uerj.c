#include <stdio.h>
//colocar ponteiro de vetor?
float calcular_cr(int quant_mat, int creditos, float medias)
{
    float numerador, denominador;
    int i;
    for (i = 0; i < quant_mat; i++)
    {
        int credito = creditos[i];
        float media = medias[i];
        numerador += credito * media;
        denominador += credito;
    }
    float cr = numerador / denominador;
    return cr;
}

int main()
{
    int op = 0;
    while (op == 0){
        printf("");
        scanf("%d", &quant_mat);
    }
    return 0;
}

def calcular_cr(quantMat, creditos, medias):
    numerador = 0.0
    denominador = 0.0

    for i in range(quantMat):
        credito = creditos[i]
        media = medias[i]
        numerador += credito * media
        denominador += credito

    cr = numerador / denominador

    return cr


while True:
    quantMat = int(input("Quantas matérias você inscreveu-se nesse semestre?\n"))

    creditos = []
    medias = []

    for i in range(quantMat):
        credito = int(input(f"Quantos créditos a {i+1}ª matéria possui?\n"))
        media = float(input(f"Qual foi sua média na {i+1}ª matéria?\n"))
        creditos.append(credito)
        medias.append(media)

    print("Matérias e médias inseridas:")
    for i in range(quantMat):
        print(f"Matéria {i+1}: Créditos = {creditos[i]}, Média = {medias[i]}")

    isConfirm = input("Todas as informações acima estão corretas? (s/n)\n").lower()

    if isConfirm == "s":
        cr = calcular_cr(quantMat, creditos, medias)
        print(f"Seu CR este semestre é: {cr:.2f}")
        break
    elif isConfirm == "n":
        print("OK. Vamos tentar novamente...")
    else:
        print("Resposta inválida. Por favor, responda 's' para sim ou 'n' para não.")
