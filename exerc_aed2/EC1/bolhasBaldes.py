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
        linha = input().strip()
        if not linha:  # Lida com possíveis linhas vazias no final
            continue
        dados = list(map(int, linha.split()))
        
        tamanho = dados[0]
        if tamanho == 0:
            break
        
        numeros = dados[1:]
        
        _, total_inversoes = contar_inversoes(numeros)
        
        # Se o número de inversões for par, Carlos vence; se for ímpar, Marcelo vence
        if total_inversoes % 2 == 0:
            print("Carlos")
        else:
            print("Marcelo")
            
    except EOFError:
        break
