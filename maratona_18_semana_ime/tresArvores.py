# As três árvores — IME/DICC
# Timelimit: 5
#
# Ideia (explicação de aluno):
# - Temos um retângulo original [x1, x2] × [y1, y2].
# - Dentro dele há 3 árvores (pontos).
# - Queremos o maior retângulo alinhado aos eixos que NÃO contenha nenhuma árvore.
#
# Estratégia:
# - Dividir o retângulo em sub-retângulos usando as coordenadas x e y das árvores como "linhas de corte".
# - Considerar todos os intervalos [a, b] em x e [c, d] em y formados por essas coordenadas
#   (incluindo as bordas x1, x2, y1, y2).
# - Para cada retângulo candidato, verificar se ele NÃO contém nenhuma árvore (verificação de inclusão estrita).
# - Retornar a maior área dentre os válidos.
#
# Observação sobre inclusão:
# - Um retângulo [a, b] × [c, d] contém um ponto (px, py) se a ≤ px ≤ b e c ≤ py ≤ d.
# - Queremos retângulos que NÃO contenham nenhuma árvore, então testamos a negação.
#
# Complexidade:
# - Coordenadas únicas em x e y: até 5 cada (x1, x2, ax, bx, cx).
# - Pares de intervalos: O(5²) × O(5²) = O(625) por caso.
# - Para cada, testamos 3 árvores: O(1).
# - Total por caso: O(1), extremamente rápido.

import sys


def maior_retangulo_sem_arvores(x1, y1, x2, y2, arvores):
    """
    Retorna a maior área de um retângulo [a, b] × [c, d] dentro de [x1, x2] × [y1, y2]
    que NÃO contenha nenhuma das três árvores.
    """
    # Coleta todas as coordenadas x e y relevantes (bordas + árvores)
    xs = sorted(set([x1, x2] + [ax for ax, ay in arvores]))
    ys = sorted(set([y1, y2] + [ay for ax, ay in arvores]))

    max_area = 0

    # Testa todos os pares de intervalos [xs[i], xs[j]] × [ys[k], ys[l]]
    for i in range(len(xs)):
        for j in range(i, len(xs)):
            a, b = xs[i], xs[j]
            for k in range(len(ys)):
                for l in range(k, len(ys)):
                    c, d = ys[k], ys[l]
                    # Verifica se o retângulo [a, b] × [c, d] NÃO contém nenhuma árvore
                    contem_alguma = False
                    for ax, ay in arvores:
                        if a <= ax <= b and c <= ay <= d:
                            contem_alguma = True
                            break
                    if not contem_alguma:
                        area = (b - a) * (d - c)
                        if area > max_area:
                            max_area = area

    return max_area


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
            # Lê 10 inteiros: x1, y1, x2, y2, ax, ay, bx, by, cx, cy
            coords = [int(next(it)) for _ in range(10)]
        except (StopIteration, ValueError):
            break

        x1, y1, x2, y2 = coords[0], coords[1], coords[2], coords[3]
        arvores = [
            (coords[4], coords[5]),
            (coords[6], coords[7]),
            (coords[8], coords[9]),
        ]

        area = maior_retangulo_sem_arvores(x1, y1, x2, y2, arvores)
        out_lines.append(str(area))

    sys.stdout.write("\n".join(out_lines))


if __name__ == "__main__":
    main()