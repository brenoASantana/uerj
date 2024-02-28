idade = int(input("Digite a idade em anos: "))

while idade < 0:
    idade = int(input("Digite uma idade VÁLIDA em anos: "))
if idade < 5:
    print("Idade muito jovem para a competição!")
elif idade >= 5 and idade <= 7:
    print("Categoria: Infantil A")
elif idade >= 8 and idade <= 10:
    print("Categoria: Infantil B")
elif idade >= 11 and idade <= 13:
    print("Categoria: Juvenil A")
elif idade >= 14 and idade <= 17:
    print("Categoria: Juvenil B")
else:
    print("Categoria: Sênior")
