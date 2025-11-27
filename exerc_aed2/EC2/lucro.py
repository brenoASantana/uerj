#1310 - Lucro
import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    iterator = iter(input_data)

    while True:
        try:
            # N dias
            n = int(next(iterator))
            # Custo por dia
            custo_por_dia = int(next(iterator))

            receitas = []
            for _ in range(n):
                receitas.append(int(next(iterator)))

            # Algoritmo de Kadane adaptado (Lucro = Receita - Custo)
            max_lucro_global = 0 # Começa em 0 (se der prejuízo, melhor não fazer nada)
            lucro_atual = 0

            for receita in receitas:
                # O lucro real do dia é a receita menos o custo fixo
                lucro_dia = receita - custo_por_dia

                lucro_atual += lucro_dia

                # Decisão Gulosa 1: Se o lucro acumulado ficou negativo, reinicia (zera)
                if lucro_atual < 0:
                    lucro_atual = 0

                # Decisão Gulosa 2: Atualiza o máximo global
                if lucro_atual > max_lucro_global:
                    max_lucro_global = lucro_atual

            print(max_lucro_global)

        except StopIteration:
            break

if __name__ == '__main__':
    solve()