# Maiores e Menores
# Professores IME/DICC — Timelimit: 5
#
# Ideia do problema (explicação de aluno):
# - Temos n bolas, cada uma com um valor inteiro positivo.
# - Dois jogadores (Ollie e Stan) escolhem, cada um, k bolas (k <= n/2).
# - Pergunta: considerando todas as possibilidades, qual é:
#   (1) a maior soma que algum jogador pode ter (ou seja, a soma máxima possível de k bolas)
#   (2) a menor soma possível de k bolas do conjunto
#
# Observação importante:
# - Como queremos o máximo que "algum" jogador pode ter, basta pensar no melhor conjunto de k bolas:
#   é simplesmente escolher as k maiores bolas.
# - E a menor soma de k bolas é simplesmente a soma das k menores bolas.
# - Não precisamos simular o jogo; basta ordenar os valores e somar as extremidades.
#
# Entrada:
# - Um inteiro t indicando o número de casos de teste.
# - Para cada caso:
#     - Uma linha com n e k (2 <= n <= 10000, k <= n/2)
#     - Uma linha com n inteiros positivos (entre 1 e 10000), os valores das bolas.
#
# Saída:
# - Para cada caso, imprimir uma linha com dois inteiros:
#     <maior_soma_de_k_bolas> <menor_soma_de_k_bolas>
#
# Exemplo:
# Entrada:
#   3
#   4 2
#   1 2 4 3
#   10 3
#   3 3 3 3 3 3 3 3 3 3
#   10 5
#   1 100 40 25 33 44 40 25 12 97
# Saída:
#   7 3
#   9 9
#   321 96
#
# Estratégia e complexidade:
# - Ordenamos o array de valores (O(n log n)) e somamos:
#     - k últimos para o máximo
#     - k primeiros para o mínimo
# - Para n até 10000, essa abordagem é eficiente o suficiente mesmo com vários casos.
#
# Implementação abaixo.


import sys


def maiores_e_menores_somas(valores, k):
    """
    Dada a lista 'valores' com n inteiros positivos e um inteiro k,
    retorna uma tupla (max_soma, min_soma) onde:
      - max_soma = soma das k maiores bolas
      - min_soma = soma das k menores bolas
    """
    # Ordena os valores em ordem crescente
    ordenados = sorted(valores)

    # Soma das k maiores: pega a "cauda" do array
    max_soma = sum(ordenados[-k:])

    # Soma das k menores: pega o "começo" do array
    min_soma = sum(ordenados[:k])

    return max_soma, min_soma


def main():
    # Lemos tudo como tokens para simplificar o parsing e tolerar quebras de linha
    data = sys.stdin.buffer.read().split()
    if not data:
        return

    it = iter(data)

    try:
        t = int(next(it))  # número de casos de teste
    except (StopIteration, ValueError):
        return

    out_lines = []

    for _ in range(t):
        try:
            n = int(next(it))
            k = int(next(it))
        except (StopIteration, ValueError):
            break  # entrada acabou antes do esperado

        # Lê os n valores das bolas
        valores = []
        for _j in range(n):
            try:
                valores.append(int(next(it)))
            except (StopIteration, ValueError):
                valores.append(0)  # fallback defensivo; não deve ocorrer se a entrada for válida

        # Calcula maior e menor soma de k bolas
        max_soma, min_soma = maiores_e_menores_somas(valores, k)

        # Formata a saída conforme enunciado
        out_lines.append(f"{max_soma} {min_soma}")

    sys.stdout.write("\n".join(out_lines))


if __name__ == "__main__":
    main()