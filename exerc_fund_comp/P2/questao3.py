import math

## Breno, a forma como foi feita a validação, não permite a inserção de um novo valor caso o lado inválido seja o segundo ou outro depois dele.
## Além disso, a área total deveria ser exibida, não a área de cada polígono separadamente.


def areaRetangulo(x, y):
    return x * y


def areaTriangulo(cateto1, cateto2):
    return areaRetangulo(cateto1, cateto2) / 2


def hipotenusa(cateto1, cateto2):
    return math.sqrt(cateto1**2 + cateto2**2)


def areaTotal(a, b, c, d, e):
    areaAB = areaRetangulo(a, b)
    areaCD = areaRetangulo(c, d)
    hipotAD = hipotenusa(a, d)
    areaHE = areaRetangulo(hipotAD, e)
    areaAD = areaTriangulo(a, d)
    return areaAB, areaCD, areaHE, areaAD


while True:
    a = b = c = d = e = 0.0

    while a <= 0.0 and b <= 0.0 and c <= 0.0 and d <= 0.0 and e <= 0.0:
        ## ENTRADA DE DADOS (COMECO DO LOOP)
        ## Se continuar com o valor inválido após o usuário digitar, imprime a mensagem de erro e repete o loop
        a = float(input("Informe o valor de A: "))
        if a <= 0.0:
            print("Valor inválido: o valor A deve ser maior que zero!")
            continue
        b = float(input("Informe o valor de B: "))
        if b <= 0.0:
            print("Valor inválido: o valor B deve ser maior que zero!")
            continue
        c = float(input("Informe o valor de C: "))
        if c <= 0.0:
            print("Valor inválido: o valor C deve ser maior que zero!")
            continue
        d = float(input("Informe o valor de D: "))
        if d <= 0.0:
            print("Valor inválido: o valor D deve ser maior que zero!")
            continue
        e = float(input("Informe o valor de E: "))
        if e <= 0.0:
            print("Valor inválido: o valor E deve ser maior que zero!")
            continue

    aT = areaTotal(a, b, c, d, e)
    print(f"A área dos polígonos AB, CD, HE e AD é respectivamente: {aT}")

    ## FINAL DO LOOP
    choice = int(input("Deseja continuar? 1-Sim 2-Não "))
    while choice < 1 or choice > 2:
        print("Opção inválida! Por favor selecione uma das opções disponíveis.")
        choice = int(input("Deseja continuar? 1-Sim 2-Não "))

    if choice == 1:
        continue
    else:
        print("Finalizando programa...")
        break
        ## Não coloquei um else para valores inesperados pois a verificação da nota é feita antes de entrar nessa
        # estrutura condiconal, logo se torna em vão conferir novamente se esse valor é válida
