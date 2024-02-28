num = int(input("Informe um número positivo: "))

while num > 0:
    numAnt = num - 1

    if numAnt == 0:
        break

    if num % numAnt != 0:
         if num % numAnt != num:
            num = numAnt
            continue
    else:
        print("O número informado não é primo!")
        break
    num = numAnt

print("O número informado é primo!")