num1 = int(input("Digite o primeiro valor: "))
num2 = int(input("Digite o segundo valor: "))
num3 = int(input("Digite o terceiro valor: "))

if num1 > num2 and num1 > num3:
    print(f"O maior valor é: {num1}")
elif num2 > num1 and num2 > num3:
    print(f"O maior valor é: {num2}")
else:
    print(f"O maior valor é: {num3}")
