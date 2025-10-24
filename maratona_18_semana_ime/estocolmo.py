# Estocolmo — IME/DICC
# Timelimit: 5
#
# Ideia (explicação de aluno):
# - Cada ponte tem uma capacidade c (carga máxima).
# - Um caminhão de capacidade W consegue atravessar uma ponte se W <= c.
# - Queremos o MAIOR W tal que, para TODAS as ilhas, exista um caminho da ilha 1
#   até ela em que todas as pontes no caminho tenham capacidade >= W.
#
# Observação:
# - Para cada ilha v, o melhor caminho a partir da ilha 1 é aquele que maximiza
#   o "gargalo" (ou seja, o mínimo das capacidades das arestas no caminho).
# - Esse problema é o "widest path" a partir da fonte 1.
# - A resposta pedida é o mínimo, entre todas as ilhas v, do valor do widest path(1 -> v).
#   Se alguma ilha for inalcançável, então a resposta é 0 (não dá para chegar em todas).
#
# Como calcular o widest path:
# - Uma variação do Dijkstra com prioridade pelo MAIOR valor atual (max-heap):
#   mantemos best[v] = melhor gargalo conhecido de 1 até v.
#   Inicialmente best[1] = +infinito (sem restrição na origem).
#   Para aresta (u, v, c): candidato = min(best[u], c).
#   Se candidato > best[v], atualiza e coloca na heap.
#
# Complexidade:
# - Por caso de teste: O(m log n), suficiente para n <= 1000 e m grande.
#
# Detalhes de implementação:
# - Leitura por tokens para velocidade.
# - Grafo não direcionado (vias bidirecionais).
# - Se n == 1, não há "outras ilhas": por convenção imprimimos 0.

import sys
import heapq


def widest_path_min_over_all(n, adj):
    """
    Calcula o widest path (maior gargalo) de 1 até cada nó, e retorna
    o mínimo desses valores para nós 2..n. Se algum for inalcançável, retorna 0.
    """
    if n == 1:
        return 0  # não há outras ilhas a alcançar

    # best[i] = melhor gargalo de 1 até i
    best = [-1] * (n + 1)
    best[1] = 10**18  # "infinito" suficiente

    # heap de máximos usando valores negativos (heapq é min-heap)
    heap = [(-best[1], 1)]

    while heap:
        neg_val, u = heapq.heappop(heap)
        val = -neg_val
        if val < best[u]:
            continue  # já temos algo melhor

        for v, c in adj[u]:
            cand = val if val < c else c  # min(val, c) sem chamada de função
            if cand > best[v]:
                best[v] = cand
                heapq.heappush(heap, (-cand, v))

    # Agrega a resposta: mínimo entre best[2..n]; se algum == -1, inalcançável -> 0
    ans = best[2]
    if ans == -1:
        return 0
    for i in range(3, n + 1):
        if best[i] == -1:
            return 0
        if best[i] < ans:
            ans = best[i]
    return ans


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

        # Lista de adjacência: para cada ilha, pares (vizinho, capacidade)
        adj = [[] for _ in range(n + 1)]
        for _e in range(m):
            try:
                u = int(next(it)); v = int(next(it)); c = int(next(it))
            except (StopIteration, ValueError):
                break
            # bidirecional
            adj[u].append((v, c))
            adj[v].append((u, c))

        ans = widest_path_min_over_all(n, adj)
        out_lines.append(str(ans))

    sys.stdout.write("\n".join(out_lines))


if __name__ == "__main__":
    main()