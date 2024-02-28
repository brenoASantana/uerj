arquivo = open("arquivoNotas.txt", "a+")
while True:
    nome = input("Informe seu nome: ")
    nota = float(input("Informe a sua nota: "))
    arquivo.write(nome + " " + str(nota) + "\n")
    resp = int(input("Deseja informar novos dados (1- sim ou 2- não)?"))
    if resp == 2:
        break

maiorNota = 0.0
nomesMaior = []
arquivo.seek(0)

for linha in arquivo:
    nome, nota = linha.split()
    nota = float(nota)
    if nota > maiorNota:
        maiorNota = nota

arquivo.seek(0)
for linha in arquivo:
    nome, nota = linha.split()
    if float(nota) == maiorNota:
        nomesMaior.append(nome)

print(f"Maior nota: {maiorNota}\nAlunos: {nomesMaior}")

arquivo.close()
