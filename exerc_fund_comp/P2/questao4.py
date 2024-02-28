notaAluno = []
quantGrupo1 = quantGrupo2 = quantGrupo3 = quantGrupo4 = 0

for i in range(15):
    nota = -1
    while nota < 0 or nota > 10:
        ## Se continuar com o valor inválido após o usuário digitar, imprime a mensagem de erro e repete o loop
        nota = float(input(f"Informe a nota válida do {i+1}º aluno:"))
        if nota < 0:
            print("Nota Inválida: notas devem ser maiores ou iguais a zero!")
        elif nota > 10:
            print("Nota Inválida: notas devem ser menores ou iguais a dez!")
    notaAluno.append(nota)

    if nota <= 3.0:
        quantGrupo1 += 1
    elif nota > 3.0 and nota < 5.0:
        quantGrupo2 += 1
    elif nota >= 5.0 and nota < 7.0:
        quantGrupo3 += 1
    elif nota >= 7.0:
        quantGrupo4 += 1
    ## Não coloquei um else pois a verificação da nota é feita antes de entrar nessa estrutura condiconal, logo se torna em vão
    ## conferir novamente se essa nota é válida

print(f"Vetor de notas: {notaAluno}")
print(f"Grupo 1: {quantGrupo1} alunos")
print(f"Grupo 2: {quantGrupo2} alunos")
print(f"Grupo 3: {quantGrupo3} alunos")
print(f"Grupo 4: {quantGrupo4} alunos")
