valorCompra = float(input("Digite o valor de compra do produto: R$"))

## Interpretei que o valor de venda sera o valor somado ao valor de compra
while valorCompra < 0:
    valorCompra = float(input("Digite o valor VÁLIDO de compra do produto: R$"))

if valorCompra < 20:
    print(f"Valor de venda: R${valorCompra*1.7}")
elif valorCompra >= 20 and valorCompra < 50:
    print(f"Valor de venda: R${valorCompra*1.5}")
elif valorCompra >= 50 and valorCompra < 100:
    print(f"Valor de venda: R${valorCompra*1.4}")
else:
    print(f"Valor de venda: R${valorCompra*1.3}")
