n = int(input("Informe um número positivo: "))

antecessor = 0
fatorial = 0
if n > 0:
    for cont in range(1, n):
        antecessorMaior = n - 1
        fatorial += n * antecessor
    print(f"Fatorial de {n} = {fatorial}")
else:
    print("Número negativo informado!")
