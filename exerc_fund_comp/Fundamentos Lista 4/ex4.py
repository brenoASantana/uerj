soma = 0
for cont in range(85, 908):
    if cont % 2 == 0:
        print(cont)
        soma += cont
print(f"A soma dos valores é: {soma}")
