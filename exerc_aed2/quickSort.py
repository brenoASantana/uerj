import time

def merge(lista, inicio, meio, fim):
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

def merge_sort(lista, inicio, fim):
    if inicio < fim:
        meio = (inicio + fim) // 2
        merge_sort(lista, inicio, meio)
        merge_sort(lista, meio + 1, fim)
        merge(lista, inicio, meio, fim)


# quicksort
def particionar(lista, baixo, alto):
    pivo = lista[alto]
    i = baixo - 1
    for j in range(baixo, alto):
        if lista[j] <= pivo:
            i += 1
            lista[i], lista[j] = lista[j], lista[i]
    lista[i+1], lista[alto] = lista[alto], lista[i+1]
    return i + 1

def quick_sort(lista, baixo, alto):
    if baixo < alto:
        pi = particionar(lista, baixo, alto)
        quick_sort(lista, baixo, pi - 1)
        quick_sort(lista, pi + 1, alto)


# gerador de numeros
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


# execucao e comparacao
tamanhos = [100, 1000, 10000]
resultados = []

for tamanho in tamanhos:
    # vetor original
    vetor = gerar_numeros(seed=int(time.time()), quantidade=tamanho)

    # Teste MergeSort
    copia_merge = vetor[:]
    inicio = time.perf_counter()
    merge_sort(copia_merge, 0, len(copia_merge) - 1)
    tempo_merge = time.perf_counter() - inicio

    # Teste QuickSort
    copia_quick = vetor[:]
    inicio = time.perf_counter()
    quick_sort(copia_quick, 0, len(copia_quick) - 1)
    tempo_quick = time.perf_counter() - inicio

    resultados.append((tamanho, tempo_merge, tempo_quick))


# mostra resultados
print("Comparação de tempos (em segundos):")
print("Tamanho | MergeSort | QuickSort")
for tamanho, tempo_merge, tempo_quick in resultados:
    print(f"{tamanho:<7} | {tempo_merge:.6f} | {tempo_quick:.6f}")

# salva em txt
with open("comparacao_tempos.txt", "w") as f:
    f.write("Tamanho | MergeSort | QuickSort\n")
    for tamanho, tempo_merge, tempo_quick in resultados:
        f.write(f"{tamanho:<7} | {tempo_merge:.6f} | {tempo_quick:.6f}\n")
