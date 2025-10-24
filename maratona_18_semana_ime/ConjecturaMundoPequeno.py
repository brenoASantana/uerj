# Conjectura do mundo pequeno — IME/DICC
# Timelimit: 10
#
# Ideia (explicação de aluno):
# - A conjectura diz que entre quaisquer duas pessoas X e Y há um caminho com no máximo 6 intermediários.
# - Isso significa que a distância no grafo entre X e Y é no máximo 7 (contando X e Y).
# - Precisamos verificar se o grafo está conectado E se o diâmetro (maior distância entre pares) é ≤ 7.
#
# Observação:
# - Se o grafo não for conexo, já retornamos 'N'.
# - Caso contrário, fazemos BFS a partir de cada vértice e verificamos se todas as distâncias são ≤ 7.
#
# Complexidade:
# - BFS por vértice: O(n + m)
# - Total por caso: O(n * (n + m))
# - Para n ≤ 1000 e m ~ 60n, temos ~60 milhões de operações por caso no pior caso,
#   ainda aceitável dentro do timelimit 10s (especialmente em Python otimizado).
#
# Detalhes de implementação:
# - Leitura por tokens para velocidade.
# - Grafo não direcionado.
# - Consideramos que a conjectura vale se todas as distâncias são ≤ 7.

import sys
from collections import deque


def bfs_max_dist(start, adj, n):
    """
    Faz BFS a partir de 'start' e retorna a maior distância alcançada.
    Se algum vértice ficar inalcançável, retorna +infinito (indicando desconexo).
    """
    dist = [-1] * (n + 1)
    dist[start] = 0
    q = deque([start])
    max_d = 0

    while q:
        u = q.popleft()
        for v in adj[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                if dist[v] > max_d:
                    max_d = dist[v]
                q.append(v)

    # Verifica se todos os nós (1..n) foram alcançados
    for i in range(1, n + 1):
        if dist[i] == -1:
            return float('inf')  # grafo desconexo

    return max_d


def verifica_conjectura(n, adj):
    """
    Retorna 'S' se o grafo está conectado e o diâmetro é ≤ 7; 'N' caso contrário.
    """
    # Verifica para cada vértice se consegue alcançar todos os outros com dist ≤ 7
    for u in range(1, n + 1):
        max_d = bfs_max_dist(u, adj, n)
        if max_d > 7:
            return 'N'
    return 'S'


def main() -> None:
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    it = iter(data)

    try:
        t = int(next(it))
    except (StopIteration, ValueError):
        return

    out_lines = []
    for _ in range(t):
        try:
            n = int(next(it))
            m = int(next(it))
        except (StopIteration, ValueError):
            break

        # Lista de adjacência: para cada pessoa, lista de conhecidos
        adj = [[] for _ in range(n + 1)]
        for _e in range(m):
            try:
                u = int(next(it))
                v = int(next(it))
            except (StopIteration, ValueError):
                break
            # bidirecional
            adj[u].append(v)
            adj[v].append(u)

        out_lines.append(verifica_conjectura(n, adj))

    sys.stdout.write("\n".join(out_lines))


if __name__ == "__main__":
    main()

