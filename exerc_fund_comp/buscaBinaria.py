def buscaBin(vetor, tam, valor):
    ini = 0
    fim = tam - 1
    while ini <= fim:
        meio = int((ini + fim) / 2)
        if vetor[meio] == valor:
            return meio
        elif valor < vetor[meio]:
            fim = meio - 1
        else:
            ini = meio + 1
    return -1


def leitura(tam):
    vetor = [0] * tam
    for i in range(tam):
        vetor[i] = int(input(f"Informe o valor da posição {i}:"))
        return vetor


vet = leitura(10)
n = int(input("Informe o valor que deseja buscar: "))
res = buscaBin(vet, len(vet), n)
if res == -1:
    print("Valor não encontrado na lista!")
else:
    print(f"Valor {n} encontrado na posição {res}")
