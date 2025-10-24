# Botas — beecrowd 6456
# Professores IME/DICC — Timelimit: 5
#
# Explicação de aluno:
# - Cada valor representa um "pé" de bota:
#     > 0  → pé esquerdo (tamanho = valor)
#     < 0  → pé direito  (tamanho = |valor|)
# - Um par é formado quando temos um esquerdo e um direito do MESMO tamanho.
# - Para cada caso, queremos contar quantos pares podem ser formados no total.
#
# Estratégia:
# - Contar quantos pés esquerdos e quantos pés direitos existem para cada tamanho (20..100).
# - O número de pares para um tamanho s é min(qtd_esq[s], qtd_dir[s]).
# - A resposta do caso é a soma desses mínimos para todos os tamanhos.
#
# Complexidade:
# - Leitura e contagem por caso: O(n) para n pés.
# - Tamanhos possíveis são só 81 valores (20..100), então somar é O(1) prático.
#
# Observações de implementação:
# - Para ser robusto com quebras de linha, leio toda a entrada como tokens.
# - Trato fim de arquivo inesperado de forma graciosa.

import sys


def contar_pares_de_botas(pes):
    """
    Recebe uma lista 'pes' de inteiros (positivos = esquerdo, negativos = direito).
    Retorna a quantidade total de pares formados.
    """
    # Como tamanhos vão de 20 a 100, usamos vetores de contagem indexados pelo tamanho.
    # Índices 0..19 ficam sem uso; usamos 20..100.
    esq = [0] * 101  # contagem de pés esquerdos por tamanho
    dir = [0] * 101  # contagem de pés direitos por tamanho

    for x in pes:
        s = abs(x)  # tamanho em valor absoluto
        if x > 0:
            esq[s] += 1
        else:
            dir[s] += 1

    # Soma dos pares possíveis por tamanho
    pares = 0
    for s in range(20, 101):
        pares += min(esq[s], dir[s])

    return pares


def main():
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
            n = int(next(it))  # quantidade de pés neste caso
        except (StopIteration, ValueError):
            break

        # Lê exatamente n inteiros dos pés
        pes = []
        for _j in range(n):
            try:
                pes.append(int(next(it)))
            except (StopIteration, ValueError):
                # Entrada inesperada; assume 0 (não conta para pares, mas evita crash)
                pes.append(0)

        # Calcula a quantidade de pares e guarda para impressão
        out_lines.append(str(contar_pares_de_botas(pes)))

    sys.stdout.write("\n".join(out_lines))


if __name__ == "__main__":
    main()