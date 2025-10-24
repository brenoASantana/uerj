# Contagem — beecrowd 6436
# Professores IME/DICC — Timelimit: 5
#
# Ideia (explicação de aluno):
# - O código C dado define T[0] = 0 e T[i] = T[i/3] + (i % 3).
# - Isso é exatamente a soma dos dígitos de i em base 3:
#     enquanto dividimos i por 3, acumulamos os restos (0, 1 ou 2),
#     que são justamente os dígitos ternários.
# - Portanto, T(n) = soma_digitos_base_3(n).
#
# Vantagem:
# - Em vez de pré-computar um vetor até 10^6 (que não serve para n até 10^18),
#   calculamos diretamente em O(log_3 n), suficiente para n ≤ 10^18 e t ≤ 500.
#
# Exemplo rápido:
# - n=4  -> base 3 = 11  -> soma = 1+1 = 2
# - n=5  -> base 3 = 12  -> soma = 1+2 = 3
# - n=0  -> soma = 0 (caso base)
#
# Entrada:
# - t casos, depois t valores n (0 ≤ n ≤ 10^18).
#
# Saída:
# - Para cada n, imprimir T(n) = soma dos dígitos de n em base 3.

import sys


def soma_digitos_base3(n: int) -> int:
    """Retorna a soma dos dígitos de n na base 3."""
    total = 0
    while n > 0:
        total += n % 3
        n //= 3
    return total  # para n=0, total=0


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
            n = int(next(it))
        except (StopIteration, ValueError):
            break
        out.append(str(soma_digitos_base3(n)))

    sys.stdout.write("\n".join(out))


if __name__ == "__main__":
    main()