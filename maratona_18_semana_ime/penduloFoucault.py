# O pêndulo de Foucault — IME/DICC
# Timelimit: 5
#
# Explicação (como um aluno):
# - L é o comprimento TOTAL do pêndulo (do ponto de fixação até a ponta da agulha).
# - D é a distância da ponta ao chão quando o pêndulo está em repouso (vertical).
# - H é a altura dos pinos acima do chão (entre D e D+L).
#
# Geometria:
# - O ponto de fixação (pivô) está a (D + L) do chão.
# - A ponta descreve uma esfera de raio L centrada no pivô.
# - O plano onde estão os pinos tem altura H. A interseção da esfera com esse plano
#   é um círculo de raio:
#       r = sqrt(L^2 - (D + L - H)^2)
#   Observando que (D + L - H) é a distância vertical do pivô até o plano dos pinos.
# - Para evitar cancelamentos numéricos, podemos reescrever:
#       r = sqrt( (H - D) * (2L + D - H) )
#
# Saída:
# - Imprimir r com uma casa decimal.
#
# Complexidade:
# - O(1) por caso. Para t até 1e5, é tranquilo.

import sys
import math


def raio_maximo(L: int, D: int, H: int) -> float:
    """
    Retorna o raio máximo do círculo (no plano a altura H) que a agulha alcança.
    Fórmula: r = sqrt( (H - D) * (2L + D - H) )
    """
    return math.sqrt((H - D) * (2 * L + D - H))


def main() -> None:
    data = sys.stdin.buffer.read().split()
    if not data:
        return

    it = iter(data)
    try:
        t = int(next(it))
    except (StopIteration, ValueError):
        return

    out = []
    for _ in range(t):
        try:
            L = int(next(it))
            D = int(next(it))
            H = int(next(it))
        except (StopIteration, ValueError):
            break

        r = raio_maximo(L, D, H)
        out.append(f"{r:.1f}")

    sys.stdout.write("\n".join(out))


if __name__ == "__main__":
    main()