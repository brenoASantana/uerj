# Craques Regulares
# Professores IME/DICC — Timelimit: 5
#
# Ideia (explicação de aluno):
# - Queremos os jogadores que marcaram em TODAS as partidas.
# - Para cada partida, coletamos o conjunto de jogadores que fizeram pelo menos 1 gol.
#   Observação: se um jogador aparece repetido na mesma partida, continua sendo "fez gol naquela partida".
#   Por isso usamos um conjunto (set) para remover duplicatas dentro da partida.
# - No final, fazemos a interseção de todos os conjuntos (partida 1 ∩ partida 2 ∩ ... ∩ partida n).
# - Se a interseção ficar vazia, imprimimos 0. Caso contrário, imprimimos os jogadores em ordem crescente.
#
# Entrada:
# - t casos de teste.
# - Para cada caso:
#     n (número de partidas)
#     Para cada uma das n partidas:
#         k (número de gols do time na partida) seguido de k inteiros com os jogadores que marcaram.
#
# Saída:
# - Para cada caso, uma linha com os jogadores que marcaram em todas as partidas (ordem crescente),
#   ou apenas 0 caso não exista nenhum.
#
# Complexidade:
# - Lemos todos os gols uma vez (O(total_de_tokens)).
# - A interseção de conjuntos de tamanho no máx. 100 é bem barata na prática.

import sys


def main() -> None:
    # Lemos toda a entrada como tokens para simplificar o parsing e tolerar quebras de linha
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
            n = int(next(it))  # número de partidas deste caso
        except (StopIteration, ValueError):
            break

        regulares = None  # manterá a interseção dos jogadores que marcaram em todas as partidas

        for _j in range(n):
            # Lê k e depois os k jogadores dessa partida
            try:
                k = int(next(it))
            except (StopIteration, ValueError):
                k = 0  # se faltar, tratamos como 0 gols

            jogadores_na_partida = set()
            for _g in range(k):
                try:
                    jogador = int(next(it))
                except (StopIteration, ValueError):
                    # Se a entrada acabar de forma inesperada, paramos de coletar
                    break
                # Adiciona ao conjunto (elimina duplicatas na mesma partida)
                jogadores_na_partida.add(jogador)

            # Atualiza a interseção:
            # - Na primeira partida, inicializa com os jogadores dessa partida.
            # - Nas demais, intersecta com o que já tínhamos.
            if regulares is None:
                regulares = jogadores_na_partida
            else:
                regulares &= jogadores_na_partida

        # Após processar as n partidas:
        if not regulares:
            out_lines.append("0")
        else:
            # Ordena e imprime numa única linha, separados por espaço
            out_lines.append(" ".join(map(str, sorted(regulares))))

    # Garante quebra de linha ao final para evitar Presentation Error no juiz
    sys.stdout.write("\n".join(out_lines) + ("\n" if out_lines else ""))


if __name__ == "__main__":
    main()