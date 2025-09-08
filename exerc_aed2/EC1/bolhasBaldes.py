# EC1 - Bolhas e Baldes
# Solução do problema 1088 do Beecrowd

# Função para contar inversões usando o método Merge Sort
def contar_inversoes(vetor):
    if len(vetor) <= 1:
        return vetor, 0
    meio = len(vetor) // 2
    esquerda, inv_esq = contar_inversoes(vetor[:meio])
    direita, inv_dir = contar_inversoes(vetor[meio:])
    resultado = []
    i = j = inversoes = 0
    while i < len(esquerda) and j < len(direita):
        if esquerda[i] <= direita[j]:
            resultado.append(esquerda[i])
            i += 1
        else:
            resultado.append(direita[j])
            inversoes += len(esquerda) - i
            j += 1
    resultado += esquerda[i:]
    resultado += direita[j:]
    return resultado, inv_esq + inv_dir + inversoes


# Programa principal
while True:
    try:
        entrada = input()
    except EOFError:
        break
    if entrada.strip() == '0':
        break
    dados = list(map(int, entrada.strip().split()))
    tamanho = dados[0]
    numeros = dados[1:1+tamanho]
    if len(numeros) != tamanho:
        continue  # ignora entradas inválidas
    _, total_inversoes = contar_inversoes(numeros)
    # Se o número de inversões for par, Carlos vence; se for ímpar, Marcelo vence
    if total_inversoes % 2 == 0:
        print("Carlos")
    else:
        print("Marcelo")