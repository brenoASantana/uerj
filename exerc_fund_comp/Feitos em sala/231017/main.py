import math

n = int(input("Informe um número positivo: "))

s = 0

while n < 0:
    n = int(input("Informe um número POSITIVO: "))

for cont in range(1, n + 1):
    s += math.sqrt(n)

print(f"O valor é: {s}")
