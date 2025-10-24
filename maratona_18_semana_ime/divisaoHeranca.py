# Divisão de herança — IME/DICC
# Timelimit: 5
#
# Ideia (explicação de aluno):
# - Queremos contar quantos subconjuntos NÃO VAZIOS têm soma divisível por 3.
# - Em vez de considerar a soma inteira, basta olhar o resto da soma módulo 3.
# - Mantemos DP de 3 estados:
#     dp[0] = quantidade de subconjuntos com soma ≡ 0 (mod 3)
#     dp[1] = quantidade de subconjuntos com soma ≡ 1 (mod 3)
#     dp[2] = quantidade de subconjuntos com soma ≡ 2 (mod 3)
# - Inicialização: dp = [1, 0, 0], contando o subconjunto vazio (soma 0).
# - Para cada número x:
#     r = x % 3
#     Ao considerar "pegar x", os subconjuntos de resto i passam a resto (i+r) % 3.
#     Ao considerar "não pegar x", dp permanece igual.
#   Então fazemos:
#     new = dp.copy()
#     para i em {0,1,2}: new[(i+r)%3] += dp[i]
#     dp = new (sempre tirando módulo 1_000_007)
# - No final, a resposta é dp[0] - 1 (subtraímos o vazio), em módulo 1_000_007.
#
# Complexidade:
# - O(n) por caso (apenas 3 estados por elemento), com n ≤ 1000.
# - Memória O(1).
#
# Observação:
# - Se houver números repetidos, cada ocorrência conta como uma escolha independente
#   (ou seja, estamos contando subconjuntos por posição, como é padrão nesses problemas).

import sys

MOD = 1_000_007


def count_subsets_sum_div3(nums):
    """Conta subconjuntos não vazios com soma divisível por 3, em módulo MOD."""
    dp = [1, 0, 0]  # começa com o subconjunto vazio: soma ≡ 0
    for x in nums:
        r = x % 3
        a0, a1, a2 = dp  # snapshot antes de atualizar
        # começamos com as opções de 'não pegar x'
        new0, new1, new2 = a0, a1, a2
        # agora adicionamos as opções de 'pegar x'
        if r == 0:
            new0 = (new0 + a0) % MOD
            new1 = (new1 + a1) % MOD
            new2 = (new2 + a2) % MOD
        elif r == 1:
            new1 = (new1 + a0) % MOD
            new2 = (new2 + a1) % MOD
            new0 = (new0 + a2) % MOD
        else:  # r == 2
            new2 = (new2 + a0) % MOD
            new0 = (new0 + a1) % MOD
            new1 = (new1 + a2) % MOD
        dp = [new0, new1, new2]

    # remove o subconjunto vazio
    return (dp[0] - 1) % MOD


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
        except (StopIteration, ValueError):
            break

        nums = []
        for _j in range(n):
            try:
                nums.append(int(next(it)))
            except (StopIteration, ValueError):
                nums.append(0)  # fallback defensivo

        out_lines.append(str(count_subsets_sum_div3(nums)))

    sys.stdout.write("\n".join(out_lines))


if __name__ == "__main__":
    main()