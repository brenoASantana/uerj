def resolver_dp(V, n):
    m = len(V)
    # Cria tabela dp
    T = [[0] * (n + 1) for _ in range(m + 1)]

    # Preenche base: existe 1 forma de formar valor 0
    for i in range(m + 1):
        T[i][0] = 1

    # Preenchimento iterativo
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if j >= V[i-1]:
                T[i][j] = T[i][j - V[i-1]] + T[i-1][j]
            else:
                T[i][j] = T[i-1][j]

    return T[m][n]


# Exemplo de uso
V = [1, 2, 5]  # moedas disponíveis
n = 5          # valor a formar
print("Número de formas (DP Bottom-Up):", resolver_dp(V, n))
