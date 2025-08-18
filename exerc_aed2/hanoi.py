def hanoi(n, origem, destino, auxiliar, movimentos):
    """
    n        : número de discos
    origem   : haste de onde os discos saem
    destino  : haste de destino final
    auxiliar : haste auxiliar
    movimentos : lista para armazenar os movimentos
    """
    if n == 1:
        movimentos.append(f"Mover disco 1 de {origem} para {destino}")
    else:
        # Move n-1 discos para a haste auxiliar
        hanoi(n-1, origem, auxiliar, destino, movimentos)
        # Move o maior disco para o destino
        movimentos.append(f"Mover disco {n} de {origem} para {destino}")
        # Move os n-1 discos da auxiliar para o destino
        hanoi(n-1, auxiliar, destino, origem, movimentos)


def resolver_hanoi(n):
    """
    Resolve a torre de hanoi com n discos.
    Retorna a lista de movimentos.
    """
    movimentos = []
    hanoi(n, "A", "C", "B", movimentos)  # A = origem, C = destino, B = auxiliar
    return movimentos


# Exemplo de execução
if __name__ == "__main__":
    n = 3  # número de discos
    passos = resolver_hanoi(n)
    for i, mov in enumerate(passos, 1):
        print(f"Passo {i}: {mov}")
