## Feito por Breno Alexandre Santana Silva e Davi Justino Marques Couto
def isPerfect(n):
    divisor = 0
    for count in range(1, n):
        if n % count == 0:
            divisor += count
            
    if n == divisor:
        return "Verdadeiro"
    else:
        return "Falso"

n = int(input('Informe um número inteiro positivo: '))

while (n<=0):
    n = int(input('Informe um número INTEIRO POSITIVO!: '))


print(f'É {isPerfect(n)} que o número {n} é perfeito!')