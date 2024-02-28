print("Escolha uma das operações matemáticas abaixo:")

opcao = int(input("1-Adição\n2-Subtração\n3-Multiplicação\n4-Divisão\n5-Sair\n"))

if opcao > 0 and opcao < 6:
    if opcao != 5:
        num1 = int(input("Digite o valor do primeiro número\n"))
        num2 = int(input("Digite o valor do segundo número\n"))

    if opcao == 1:
        print(f'O resultado é: {num1+num2}')
    elif opcao == 2:
        print(f'O resultado é: {num1-num2}')
    elif opcao == 3:
        print(f'O resultado é: {num1*num2}')
    elif opcao == 4:
        print(f'O resultado é: {num1/num2}')
    else:
        print("Operação Finalizada")
else:
    print("Valor digitado fora das opções do menu")