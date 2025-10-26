# Embrulhando um presente
# Professores IME/DICC — Timelimit: 5
#
# Ideia do problema:
# - Temos uma caixa em forma de paralelepípedo retângulo com dimensões inteiras (a, b, c).
# - Podemos usar quantos pedaços de papel forem necessários (temos fita adesiva suficiente).
# - A pergunta é: qual a menor área total de papel necessária para cobrir completamente a caixa?
#
# Observação importante:
# - Como podemos cortar o papel em quantas partes quisermos e colar com fita, não precisamos
#   de sobras, dobras ou “folgas” extras. Basta cobrir exatamente todas as faces.
# - Sendo assim, a menor área total de papel necessária é simplesmente a área total da superfície
#   do paralelepípedo.
#
# Fórmula da área total do paralelepípedo:
#   Área = 2*(ab + bc + ac)
#   onde:
#     - ab é a área de uma face (a × b), existem 2 dessas
#     - bc é a área de outra face (b × c), existem 2 dessas
#     - ac é a área da terceira face (a × c), existem 2 dessas
#
# Entrada:
# - Um inteiro t (1 ≤ t ≤ 1000) indicando o número de casos de teste.
# - Em seguida, t linhas, cada uma com três inteiros a, b, c (1 ≤ a, b, c ≤ 1000).
#
# Saída:
# - Para cada caso de teste, imprimir em uma nova linha a área mínima de papel necessária.
#
# Complexidade:
# - Para cada caso de teste fazemos operações O(1), então o total é O(t).
# - Os valores cabem em inteiros 32 bits: no pior caso 2*(1000*1000 + 1000*1000 + 1000*1000) = 6_000_000.


import sys


def area_papel_minima(a: int, b: int, c: int) -> int:
    """
    Dado um paralelepípedo com arestas a, b, c, retorna a menor
    área de papel necessária para cobrir completamente a caixa.

    Como temos fita para juntar pedaços de papel, a área mínima
    é igual à área total da superfície: 2*(ab + bc + ac).
    """
    return 2 * (a * b + b * c + a * c)


def main() -> None:
    # Leitura robusta de toda a entrada como tokens (evita problemas com espaços/linhas extras)
    data = sys.stdin.buffer.read().split()
    if not data:
        return  # Sem entrada, nada a fazer

    it = iter(data)

    try:
        # Lê o número de casos de teste
        t = int(next(it))
    except StopIteration:
        return  # Entrada incompleta
    except ValueError:
        return  # Primeiro token não é inteiro; aborta de forma silenciosa

    out_lines = []

    # Para cada caso, lemos três inteiros a, b, c e calculamos a área
    for _ in range(t):
        try:
            a = int(next(it))
            b = int(next(it))
            c = int(next(it))
        except StopIteration:
            break  # Entrada terminou antes do esperado; encerra graciosamente

        # Calcula a área mínima de papel (área total da superfície)
        area = area_papel_minima(a, b, c)

        # Armazena a resposta como string para imprimir depois
        out_lines.append(str(area))

    # Imprime uma resposta por linha, conforme especificação do problema.
    # Garantimos uma nova linha final para evitar presentation errors em alguns judges.
    sys.stdout.write("\n".join(out_lines) + "\n")


if __name__ == "__main__":
    main()