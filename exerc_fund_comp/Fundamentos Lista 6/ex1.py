vetpos = []
vetneg = []

for i in range(10):
    n = int(input("Informe um valor: "))

    if n > 0:
        vetpos.append(n)
    if n < 0:
        vetneg.append(n)

print(f"Vetor Positivo: {vetpos}")
print(f"Vetor Negativo: {vetneg}")
