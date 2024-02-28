vet1 = [0] * 10
vet2 = [0] * 10
vetInter = []

for i in range(len(vet1)):
    vet1[i] = int(input("Informe um valor inteiro para o 1º vetor: "))

for i in range(len(vet2)):
    vet2[i] = int(input("Informe um valor inteiro para o 2º vetor: "))

for i in range(len(vet1)):
    for j in range(len(vet2)):
        if vet1[i] == vet2[j]:
            vetInter.append(vet2[j])

print(vetInter)
