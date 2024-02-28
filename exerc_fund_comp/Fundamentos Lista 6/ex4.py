vetor = [0] * 15

for i in range(len(vetor)):
    n = int(input("Informe um valor inteiro: "))
    if n < 0:
        vetor[i] = 0
    else:
        vetor[i] = n

print(vetor)
