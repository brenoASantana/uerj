x = int(input("Informe o valor de X: "))
n = int(input("Informe o valor impar de N: "))

s = 0
while n % 2 == 0:
    n = float(input("Informe o valor IMPAR de N: "))

i = 1
for cont in range(1, n + 1, 2):
    ## O que me dificultou foi achar um jeito de saber se devo somar ou subtratir os valores e ainda manter o mesmo valor de n

    if i % 2 == 0:
        s += (x**n) / n
    else:
        s -= (x**n) / n

    i += 1

s -= x

print(f"Valor da operação: {s}")
