mat = [
    [0,0,0],
    [0,0,0],
    [0,0,0]
    ]

soma = 0

for lin in range(len(mat)):
    for col in range(len(mat[lin])):
        nCol = int(input("Informe um valor: "))
        print(mat)
        mat[col] = nCol
        soma += nCol
    nLin = int(input("Informe um valor: "))
    print(mat)
    mat[lin] = nLin
    soma += nLin

print(f"A soma dos elementos da matriz é: {soma}")
