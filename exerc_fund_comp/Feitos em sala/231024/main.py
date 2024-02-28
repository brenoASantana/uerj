import math


def delta(a, b, c):
    delta = (b**2) - 4 * (a * c)
    if delta < 0:
        return None
    else:
        return delta


def calcularRaiz(delta, a, b):
    

    x1 = ((b * -1) + math.sqrt(delta)) / (2 * a)
    x2 = ((b * -1) - math.sqrt(delta)) / (2 * a)
    return x1, x2


a = int(input("Informe o valor de A da equação de segundo grau:\n"))
b = int(input("Informe o valor de B da equação de segundo grau:\n"))
c = int(input("Informe o valor de C da equação de segundo grau:\n"))
delta = delta(a, b, c)
if delta == None:
    print(f"Não existe raiz de delta negativo!")
else:
    print(f"O conjunto solução é: {calcularRaiz(delta, a, b)}")
