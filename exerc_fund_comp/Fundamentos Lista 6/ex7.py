vet1 = []
vet2 = []
vet3 = []

while len(vet1) < 10:
    vet1.append(int(input("Informe um valor para o 1º vetor: ")))

while len(vet2) < 10:
    vet2.append(int(input("Informe um valor para o 2º vetor: ")))

for i in range(10):
    ## Se estiver em uma posição impar, insere valor do primeiro vetor
    ## Se não insere valor do segundo vetor
    if i % 2 != 0:
        vet3.append(vet1[i])
    else:
        vet3.append(vet2[i])

print(vet1)
print(vet2)
print(vet3)
