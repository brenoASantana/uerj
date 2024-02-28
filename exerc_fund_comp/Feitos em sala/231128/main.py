def cadNotaAluno():
    file = open("notasAluno.txt", "w")
    isContinue = True
    while isContinue == True:
        nome = str(input("Informe o nome do aluno:"))
        nota = -1


while nota < 0:
    nota = float(input("Informe a nota válida da P1 do aluno:"))

    file.write(nome + " " + str(nota) + "\n")

    r = int(input("Deseja cadastrar um novo aluno? (1-Sim 2-Não)"))

    if r == 2:
        ##while break
        isContinue = False

file.close()


def maiorNota():
    nomeMaior = []
    notaMaior = 0
    ## file.seek(0) se não fechar
    file = open("notasAluno.txt", "r")
    fileS = file.readline().split()
    nomeMaior = fileS[0]
    notaMaior = fileS[1]

    for line in file:
        ## nome, nota = line.split()
        lineS = line.split()

    ## precisa rodar de novo, pois não garante que o primeiro valor é o maior de todos
    if lineS[1] > notaMaior:
        notaMaior = lineS[1]
        nomeMaior += [str(lineS[0])]

        ## for linha in arquivo:
        ## nome, nota = linha.split()
        ## nota = float(nota)
        ## if nota > maiorNota:
        ## maiorNota = nota
        ## for linha in arquivo:
        ## nome, nota = linha.split()
        ## if float(nota) > maiorNota:
        ## nomesMaior.append(nome
    file.close()
    print(f"Maior Nota:{notaMaior}")
    print(f"Alunos:{nomeMaior}")


cadNotaAluno()
maiorNota()
