num1 = int(input("Digite o primeiro valor: "))
num2 = int(input("Digite o segundo valor: "))
num3 = int(input("Digite o terceiro valor: "))

if num1 < num2 and num1 < num3:
    if num2 < num3:
        print(f"Ordem crescente: {num1}, {num2}, {num3}")
    else:
        print(f"Ordem crescente: {num1}, {num3}, {num2}")
elif num2 > num1 and num2 > num3:
    if num1 > num3:
        print(f"Ordem crescente: {num2}, {num1}, {num3}")
    else:
        print(f"Ordem crescente: {num2}, {num3}, {num1}")
elif num3 > num1 and num3 > num2:
    if num1 > num2:
        print(f"Ordem crescente: {num3}, {num1}, {num1}")
    else:
        print(f"Ordem crescente: {num3}, {num2}, {num1}")
