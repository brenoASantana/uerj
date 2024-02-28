## Método bastante simples;
## Utilizado quando os dados não estão ordenados;
## • Percorre o vetor, elemento por elemento, verificando se o elemento
## desejado está presente no vetor e termina:
## • Com sucesso: valor pesquisado é encontrado;
## • Sem sucesso: todos os registros são pesquisados, mas o valor não é encontrado.


def buscaSeq(vetor, tam, valor):
    for i in range(tam):
        if vetor[i] == valor:
            return i
    return -1


def leitura(tam):
    vetor = [0] * tam
    for i in range(tam):
        vetor[i] = int(input(f"Informe o valor da posição {i}:"))
        return vetor


vet = leitura(10)
n = int(input("Informe o valor que deseja buscar: "))
res = buscaSeq(vet, len(vet), n)
if res == -1:
    print("Valor não encontrado na lista!")
else:
    print(f"Valor {n} encontrado na posição {res}")
