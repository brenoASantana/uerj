import time

# Merge: combina duas metades já ordenadas
def merge(lista, inicio, meio, fim):
    tamanho_esq = meio - inicio + 1
    tamanho_dir = fim - meio

    esquerda = lista[inicio:meio+1] + [float("inf")]
    direita = lista[meio+1:fim+1] + [float("inf")]

    i = j = 0
    for k in range(inicio, fim + 1):
        if esquerda[i] <= direita[j]:
            lista[k] = esquerda[i]
            i += 1
        else:
            lista[k] = direita[j]
            j += 1


# MergeSort recursivo: divide, ordena e combina
def merge_sort(lista, inicio, fim):
    if inicio < fim:
        meio = (inicio + fim) // 2
        merge_sort(lista, inicio, meio)
        merge_sort(lista, meio + 1, fim)
        merge(lista, inicio, meio, fim)


# Gerador de números pseudo-aleatórios (Linear Congruential Generator)
def gerar_numeros(seed, quantidade):
    a = 1664525
    c = 1013904223
    m = 2**32
    valores = []
    x = seed
    for _ in range(quantidade):
        x = (a * x + c) % m
        valores.append(x % 100000)
    return valores


# Geração dos vetores
vetores = {
    "100": gerar_numeros(seed=int(time.time()), quantidade=100),
    "1000": gerar_numeros(seed=int(time.time()), quantidade=1000),
    "10000": gerar_numeros(seed=int(time.time()), quantidade=10000),
}

# Salva vetores originais
for tamanho, vetor in vetores.items():
    with open(f"vetor_{tamanho}.txt", "w") as f:
        f.write(" ".join(map(str, vetor)))

# Lê, ordena e salva
for tamanho in vetores.keys():
    with open(f"vetor_{tamanho}.txt", "r") as f:
        vetor = list(map(int, f.read().split()))

    merge_sort(vetor, 0, len(vetor) - 1)

    with open(f"vetor_{tamanho}_ordenado.txt", "w") as f:
        f.write(" ".join(map(str, vetor)))