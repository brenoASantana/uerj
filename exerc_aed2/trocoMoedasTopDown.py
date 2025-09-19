def moedas_memo(p, q, V, T):
    # Caso base: valor negativo ou nenhuma moeda
    if q < 0 or p == 0:
        return 0
    # Caso base: valor 0 pode ser formado de 1 forma (sem usar moedas)
    if q == 0:
        return 1

    # Se já calculado, retorna
    if T[p][q] != -1:
        return T[p][q]

    # Escolha: usar ou não a moeda V[p-1]
    T[p][q] = moedas_memo(p, q - V[p-1], V, T) + moedas_memo(p-1, q, V, T)
    return T[p][q]


def resolver_memo(V, n):
    m = len(V)
    # inicializa tabela com -1
    T = [[-1] * (n + 1) for _ in range(m + 1)]
    return moedas_memo(m, n, V, T)


# Exemplo de uso
V = [1, 2, 5]  # moedas disponíveis
n = 5          # valor a formar
print("Número de formas (Memoização):", resolver_memo(V, n))
