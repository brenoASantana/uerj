import math


def area(r):
    return (math.pi) * (r**2)


def perimetro(r):
    return 2 * (math.pi) * r


r = float(input("Informe o valor do raio do círculo: "))

print(f"Area do círculo: {area(r)}, Perímetro do círculo: {perimetro(r)}")
