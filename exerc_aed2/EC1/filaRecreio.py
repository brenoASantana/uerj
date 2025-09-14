# Problema 1548 - Fila do Recreio

qtd_testes = int(input())

for _ in range(qtd_testes):
    qtd_alunos = int(input())
    notas_original = list(map(int, input().split()))
    
    # Ordena em ordem decrescente
    notas_ordenado = sorted(notas_original, reverse=True)
    
    # Conta quantos ficaram na mesma posição
    perm = 0
    for i in range(qtd_alunos):
        if notas_original[i] == notas_ordenado[i]:
            perm += 1
    
    print(perm)
