print("Escolha uma das operações matemáticas abaixo:")

opcao = int(input("1-Adição\n2-Subtração\n3-Multiplicação\n4-Divisão\n5-Sair\n"))

if opcao >= 1 and opcao <= 5:
    num1 = int(input("Digite o valor do primeiro número\n"))
    num2 = int(input("Digite o valor do segundo número\n"))

    match opcao:
        case 1:
            print(f"O resultado é: {num1+num2}")
        case 2:
            print(f"O resultado é: {num1-num2}")
        case 3:
            print(f"O resultado é: {num1*num2}")
        case 4:
            if num2 != 0:
                print(f"O resultado é: {num1/num2}")
            else:
                print("ERRO: Divisor igual a 0. Cancelando operação...")
        case 5:
            print("Operação Finalizada")
else:
    print("Valor digitado fora das opções do menu.")
