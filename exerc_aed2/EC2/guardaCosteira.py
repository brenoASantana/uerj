#1247 guarda costeira
import math
import sys

def solve():
    # Lê todas as linhas da entrada
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    iterator = iter(input_data)

    while True:
        try:
            D = int(next(iterator))
            VF = int(next(iterator))
            VG = int(next(iterator))

            # Distância que o fugitivo percorre para chegar ao limite (12 milhas)
            dist_fugitivo = 12.0

            # Distância que o guarda percorre (Hipotenusa)
            # Cateto 1: 12 milhas (distância horizontal até o limite)
            # Cateto 2: D milhas (distância inicial entre eles)
            dist_guarda = math.sqrt(12**2 + D**2)

            # Tempo = Distância / Velocidade
            tempo_fugitivo = dist_fugitivo / VF
            tempo_guarda = dist_guarda / VG

            # Se o guarda chega antes ou no mesmo tempo, ele pega o ladrão
            if tempo_guarda <= tempo_fugitivo:
                print("S")
            else:
                print("N")

        except StopIteration:
            break

if __name__ == '__main__':
    solve()