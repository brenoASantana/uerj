dist = float(input("Digite o valor da distancia em quilômetros:\n"))
velocKmH = float(input("Digite o valor da velocidade média em quilômetros por hora:\n"))

## Utilizando a formula da velocidade media
print(
    f"Tempo médio em horas para chegar ao local: {dist / velocKmH}. Velocidade em m/s: {velocKmH / 3.6}"
)
