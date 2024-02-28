vetor = []

for i in range(10):
    n = int(input("Informe um valor: "))
    vetor.append(n)

for i in range(len(vetor)-1, -1, -1):
    print(vetor[i])
