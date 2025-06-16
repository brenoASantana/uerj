from collections import deque

def encontrar_comprimento_minimo(n):
    if n == 1:
        print(1)
        return

    fila = deque([(1, 1)])
    visitados = {1}

    while fila:
        resto_atual, comprimento_atual = fila.popleft()

        resto_com_zero = (resto_atual * 10) % n
        if resto_com_zero == 0:
            print(comprimento_atual + 1)
            return

        if resto_com_zero not in visitados:
            visitados.add(resto_com_zero)
            fila.append((resto_com_zero, comprimento_atual + 1))

        resto_com_um = (resto_atual * 10 + 1) % n
        if resto_com_um == 0:
            print(comprimento_atual + 1)
            return

        if resto_com_um not in visitados:
            visitados.add(resto_com_um)
            fila.append((resto_com_um, comprimento_atual + 1))


def main():
    try:
        numero_de_casos = int(input())
        for _ in range(numero_de_casos):
            n = int(input())
            encontrar_comprimento_minimo(n)
    except (ValueError, EOFError):
        pass

if __name__ == "__main__":
    main()