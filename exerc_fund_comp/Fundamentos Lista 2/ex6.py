peso = float(input("Digite o valor do peso em quilogramas:\n"))
altura = float(input("Digite o valor da altura em metros:\n"))

if peso < 0 or altura < 0:
    print("Algum dos valores negativo! Encerrando programa...")
print(f'O IMC é: {(peso/(altura**2))}')