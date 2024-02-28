def distancia(x1, y1, x2, y2):
    return (((x2 - x1) ** 2) + ((y2 - y1) ** 2)) ** 0.5


x1 = float(input("Informe a posição de x1: "))
y1 = float(input("Informe a posição de y1: "))
x2 = float(input("Informe a posição de x2: "))
y2 = float(input("Informe a posição de y2: "))

print(f"A distância é: {distancia(x1,y1,x2,y2)}")
