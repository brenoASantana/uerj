m1 = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
m2 = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
mS = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]

ordem = 1

for lin in range(len(m1)):
    for col in range(len(m1[lin])):
        m1[col] = int(input(f"Informe o valor da {ordem}º matriz na coordenada [{lin},{col}]: "))
        m1[lin] = int(input(f"Informe o valor da {ordem}º matriz na coordenada [{lin},{col}]: "))

ordem += 1

for lin in range(len(m2)):
    for col in range(len(m2[lin])):
        m2[col] = int(input(f"Informe o valor da {ordem}º matriz na coordenada [{lin},{col}]: "))
        m1[lin] = int(input(f"Informe o valor da {ordem}º matriz na coordenada [{lin},{col}]: "))

## Somar direto
for lin in range(len(mS)):
    for col in range(len(mS[lin])):
        mS[col] = m1[col] + m2[col]
        mS[lin] = m1[lin] + m2[lin]

print("Matriz 1: ", m1)
print("Matriz 2: ", m2)
print("Matriz Soma: ", mS)