a = int(input("Digite o valor de A: "))
b = int(input("Digite o valor de B: "))
c = int(input("Digite o valor de c: "))

if a < 0 or b < 0 or c < 0:
    print("Algum valor inválido! Encerrando sistema...")

if a < b + c and b < a + c and c < a + b:
    print(
        f"Valor de A: {a}, Valor de B: {b}, Valor de C: {c}, Perímetro do triangulo: {a+b+c}"
    )
else:
    print(
        "Para formar um triângulo, cada suposto lado deve ser menor do que a soma dos outros dois lados"
    )
