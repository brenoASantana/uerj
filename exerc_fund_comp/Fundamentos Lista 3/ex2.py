salario = float(input("Digite a renda mensal: R$"))

if salario <= 1903.98:
    print(f"Salário Bruto: R${salario} | Valor do imposto: R${salario*0:.2f}")
elif salario >= 1903.99 and salario <= 2826.65:
    print(f"Salário Bruto: R${salario} | Valor do imposto: R${salario*1.075:.2f}")
elif salario >= 2826.66 and salario <= 3751.05:
    print(f"Salário Bruto: R${salario} | Valor do imposto: R${salario*1.15:.2f}")
elif salario >= 3751.06 and salario <= 4664.68:
    print(f"Salário Bruto: R${salario} | Valor do imposto: R${salario*1.225:.2f}")
else:
    print(f"Salário Bruto: R${salario} | Valor do imposto: R${salario*1.275:.2f}")
