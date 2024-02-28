def buscaSeqOrd(vetor, valor):
    for i in range(10):
        if vetor[i] == valor:
            return i
        elif vetor[i] > valor:
            return -1
    return -1


def leitura(tam):
    vetor = [0] * tam
    for i in range(tam):
        vetor[i] = int(input(f"Informe o valor da posição {i}:"))
        return vetor


vet = leitura(10)
n = int(input("Informe o valor que deseja buscar: "))
res = buscaSeqOrd(vet, n)
if res == -1:
    print("Valor não encontrado na lista!")
else:
    print(f"Valor {n} encontrado na posição {res}")
