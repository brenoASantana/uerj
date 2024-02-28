def fazerVetor(tamVet):
    vet = []
    for i in range(tamVet):
        vet.append(0)
    return vet


def fazerMatriz(linMat, colMat):
        mat = []
    for i in range(linhas):
        mat.append([])
        for j in range(colunas):
            mat[i].append(int(input(f'Insira um valor para a posição [{i}][{j}]: ')))
    return mat

    mat = [[],]
    for lin in range(linMat):
        for col in range(colMat):
            mat.append(0)
        mat.append(0)
    return mat


tamVet = int(input("Informe o tamanho desejado do vetor: "))
linMat = int(input("Informe o tamanho desejado da linha da matriz: "))
colMat = int(input("Informe o tamanho desejado da coluna da matriz: "))
vet = fazerVetor(tamVet)
mat = fazerMatriz(linMat, colMat)

print(vet, mat)
print(len(vet), len(mat))
