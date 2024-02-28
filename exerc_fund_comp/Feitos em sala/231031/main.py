def isTriangle(x,y,z):
    if x < 0 or y < 0 or z < 0:
        return None
    elif x < (y+z) or y < (x+z) or z < (x+y):
        return True
    else:
        return False

def triangleType(x,y,z):
    if x == y and y == z:
        return "Esses lados formam um Triângulo Equilátero!"
    elif x == y or y == z or x == z:
        return "Esses lados formam um Triângulo Isósceles!"
    elif x != y and y != z and x != z:
        return "Esses lados formam um Triângulo Escaleno!" 
    
x = float(input("Informe um valor de X: "))
y = float(input("Informe um valor de Y: "))
z = float(input("Informe um valor de Z: "))

if isTriangle(x,y,z):
    print(triangleType(x,y,z))
else:
    print("O comprimento dos lados informados não formam um triângulo!")
