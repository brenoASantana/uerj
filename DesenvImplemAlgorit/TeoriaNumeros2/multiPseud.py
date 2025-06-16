def encontrar_multiplo_pseudobinario(n):
    """Encontra um múltiplo de N composto apenas pelos dígitos 1 e 0."""

    if n == 1:
        print(1)
        return

    # Dicionário para mapear: {resto: quantidade_de_uns}
    restos_visitados = {}

    quantidade_de_uns = 1
    resto_atual = 1 % n

    while True:
        # Caso 1: O número formado por '1's (B) é divisível por N.
        if resto_atual == 0:
            print('1' * quantidade_de_uns)
            break

        # Caso 2: Um resto se repetiu, encontramos A e B com o mesmo resto.
        if resto_atual in restos_visitados:
            i = restos_visitados[resto_atual]  # Qtd. de '1's em A
            j = quantidade_de_uns              # Qtd. de '1's em B

            # O múltiplo é C = B - A
            resultado = '1' * (j - i) + '0' * i
            print(resultado)
            break

        # Armazena o resto visto pela primeira vez.
        restos_visitados[resto_atual] = quantidade_de_uns

        # Avança para o próximo número da sequência (1, 11, 111...).
        quantidade_de_uns += 1
        resto_atual = (resto_atual * 10 + 1) % n


def main():
    """Lê os casos de teste e executa a solução para cada um."""
    try:
        numero_de_casos = int(input())
        for _ in range(numero_de_casos):
            n_atual = int(input())
            encontrar_multiplo_pseudobinario(n_atual)
    except (ValueError, EOFError):
        pass

if __name__ == "__main__":
    main()