taxaFDia = float(input("Digite a taxa fixa por dia:\n"))
taxaFKm = float(input("Digite a taxa por quilômetro rodado:\n"))
dia = int(input("Digite o número de dias:\n"))
km = float(input("Digite o número de quilômetros rodados:\n"))

if taxaFDia < 0 or taxaFKm < 0 or dia < 0 or km < 0:
        print("Algum valor informado negativo! Finalizando sistema...")

## Interpretei que o valor total será a fatura sem descontos ao invés da fatura final
print(
    f"Valor total do aluguel: {((taxaFDia*1.1)*dia)+(taxaFKm*km)}. Valor do desconto: {(taxaFDia*0.1)*dia}. Nº dias: {dia}. Quilometragem rodada: {km}"
)
