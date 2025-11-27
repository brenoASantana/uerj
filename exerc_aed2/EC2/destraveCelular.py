import sys

# Constante do problema
MOD = 1300031

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def mat_mul(A, B):
    size = len(A)
    C = [[0] * size for _ in range(size)]
    for i in range(size):
        for k in range(size):
            if A[i][k] == 0: continue
            val_a = A[i][k]
            for j in range(size):
                C[i][j] = (C[i][j] + val_a * B[k][j]) % MOD
    return C

def mat_pow(A, p):
    size = len(A)
    res = [[0] * size for _ in range(size)]
    for i in range(size): res[i][i] = 1
    base = A
    while p > 0:
        if p % 2 == 1:
            res = mat_mul(res, base)
        base = mat_mul(base, base)
        p //= 2
    return res

def get_canonical(r, c, n):
    # Simetria Horizontal/Vertical
    r = r if r < n - 1 - r else n - 1 - r
    c = c if c < n - 1 - c else n - 1 - c
    # Simetria Diagonal
    return (r, c) if r <= c else (c, r)

def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    iterator = iter(input_data)

    while True:
        try:
            n = int(next(iterator))
            p = int(next(iterator))
        except StopIteration:
            break

        if n == 0 and p == 0: break

        # Caso base: caminhos de tamanho 1 (apenas o ponto inicial)
        if p == 1:
            print((n * n) % MOD)
            continue

        # 1. Mapear classes de simetria
        coord_to_class = {}
        class_counts = []
        unique_sigs = []
        sig_to_idx = {}

        for r in range(n):
            for c in range(n):
                sig = get_canonical(r, c, n)
                if sig not in sig_to_idx:
                    sig_to_idx[sig] = len(unique_sigs)
                    unique_sigs.append(sig)
                    class_counts.append(0)
                idx = sig_to_idx[sig]
                coord_to_class[(r,c)] = idx
                class_counts[idx] += 1

        num_classes = len(unique_sigs)

        # Encontrar representante para calcular transições
        class_reps = {}
        for r in range(n):
            for c in range(n):
                c_idx = coord_to_class[(r,c)]
                if c_idx not in class_reps:
                    class_reps[c_idx] = (r, c)

        # 2. Construir Matriz de Adjacência (M[u][v] = caminhos de UM nó u para QUALQUER nó v)
        M = [[0] * num_classes for _ in range(num_classes)]

        for u_idx in range(num_classes):
            r1, c1 = class_reps[u_idx]
            for r2 in range(n):
                for c2 in range(n):
                    if r1 == r2 and c1 == c2: continue

                    dr = abs(r1 - r2)
                    dc = abs(c1 - c2)
                    if gcd(dr, dc) == 1:
                        v_idx = coord_to_class[(r2, c2)]
                        M[u_idx][v_idx] += 1

        # 3. Calcular M^(P-1)
        M_final = mat_pow(M, p - 1)

        # 4. Cálculo Final Correto (Vetor x Matriz)
        # Vetor inicial V = contagem de pontos em cada classe (pois podemos começar em qualquer lugar)
        # Resultado = Soma( V * M_final )

        total_patterns = 0

        # Para cada classe de origem 'i' e destino 'j'
        for i in range(num_classes):
            row_sum = 0
            # Quantos caminhos saem de um único nó da classe 'i' e vão para qualquer lugar?
            # Somamos a linha i da matriz final
            for j in range(num_classes):
                row_sum = (row_sum + M_final[i][j]) % MOD

            # Multiplicamos pelo número de nós iniciais que existem na classe 'i'
            term = (class_counts[i] * row_sum) % MOD
            total_patterns = (total_patterns + term) % MOD

        print(total_patterns)

if __name__ == '__main__':
    solve()