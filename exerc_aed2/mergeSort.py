import time

# 1 - Implementação do MergeSort
def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        esquerda = arr[:mid]
        direita = arr[mid:]

        merge_sort(esquerda)
        merge_sort(direita)

        i = j = k = 0

        # Combina as duas metades
        while i < len(esquerda) and j < len(direita):
            if esquerda[i] < direita[j]:
                arr[k] = esquerda[i]
                i += 1
            else:
                arr[k] = direita[j]
                j += 1
            k += 1

        # Copia os elementos restantes
        while i < len(esquerda):
            arr[k] = esquerda[i]
            i += 1
            k += 1

        while j < len(direita):
            arr[k] = direita[j]
            j += 1
            k += 1


# 2 - Gerador de números pseudo-aleatórios (Linear Congruential Generator)
def lcg(seed, n):
    a = 1664525      # multiplicador
    c = 1013904223   # incremento
    m = 2**32        # módulo
    valores = []
    x = seed
    for _ in range(n):
        x = (a * x + c) % m
        valores.append(x % 100000)  # limitar os valores
    return valores


# 3 - Gerar três vetores (100, 1000, 10000 elementos)
vetores = {
    "100": lcg(seed=int(time.time()), n=100),
    "1000": lcg(seed=int(time.time()), n=1000),
    "10000": lcg(seed=int(time.time()), n=10000),
}

# 4 - Armazenar em arquivos .txt
for tamanho, vetor in vetores.items():
    with open(f"vetor_{tamanho}.txt", "w") as f:
        f.write(" ".join(map(str, vetor)))


# 5 - Ler, ordenar com MergeSort e salvar em novos arquivos
for tamanho in vetores.keys():
    # Lê o vetor
    with open(f"vetor_{tamanho}.txt", "r") as f:
        vetor = list(map(int, f.read().split()))

    # Ordena
    merge_sort(vetor)

    # Salva vetor ordenado
    with open(f"vetor_{tamanho}_ordenado.txt", "w") as f:
        f.write(" ".join(map(str, vetor)))