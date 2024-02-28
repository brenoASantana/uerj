a = int(input("Digite o valor de A:\n"))
b = int(input("Digite o valor de B:\n"))

print(f"Valores Iniciais:\nA={a} B={b}")

a, b = b, a

print(f"Valores Finais:\nA={a} B={b}")
