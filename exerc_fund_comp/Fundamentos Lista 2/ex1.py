import math

r = float(input("Informe a medida do raio do círculo:\n"))

while r < 0:
    r = float(input("Informe UM VALOR POSITIVO:\n"))
print(f"A area do círculo é: {(math.pi)*(r**2)}")
