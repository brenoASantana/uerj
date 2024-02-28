# Feito por Breno Alexandre Santana Silva e Samir Guimarães


def percentual(espaco, somaEspaco):
    return (espaco * 100) / somaEspaco


def bytesParaMegabytes(bytes):
    megabytes = bytes / 1000000
    return megabytes


def lerUsuario():
    usuario = open("usuarios.txt", "r")
    vetNome = [""] * 20
    vetEspaco = [0] * 20
    somaEspaco = 0

    for i in range(20):
        linha = usuario.readline()
        vetNome[i], vetEspaco[i] = linha.split()
        vetEspaco[i] = float(vetEspaco[i])
        somaEspaco += vetEspaco[i]

    usuario.close()
    return vetNome, vetEspaco, somaEspaco


def criarRelatorio(vetNome, vetEspaco, somaEspaco):
    relatorio = open("relatorio.txt", "a")
    relatorio.write("Nr. Usuário Espaço utilizado % do uso \n")
    relatorio.seek(0)

    for i in range(20):
        nr = i + 1
        vetEspaco[i] = float(vetEspaco[i])
        porcentUso = (vetEspaco[i] * 100) / somaEspaco
        relatorio.write(
            str(nr)
            + " "
            + vetNome[i]
            + " "
            + str(f"{bytesParaMegabytes(vetEspaco[i]):.2f}")
            + " MB"
            + " "
            + str(f"{percentual(vetEspaco[i], somaEspaco):.2f}")
            + "%"
            + "\n"
        )
        relatorio.seek(0)
        nr += 1

    mediaEspaco = bytesParaMegabytes((somaEspaco / 20))
    relatorio.write("\n")
    relatorio.seek(0)
    relatorio.write(
        "Espaço total ocupado: "
        + str(f"{bytesParaMegabytes(somaEspaco):.2f}")
        + " MB"
        + "\n"
    )
    relatorio.seek(0)
    relatorio.write("Espaço médio ocupado: " + str(f"{mediaEspaco:.2f}") + " MB")
    relatorio.close()


vetNome = [""] * 20
vetEspaco = [0] * 20

vetNome, vetEspaco, somaEspaco = lerUsuario()
criarRelatorio(vetNome, vetEspaco, somaEspaco)

relatorio = open("relatorio.txt", "r")

relatorio = relatorio.read()

print(relatorio)

relatorio.close()
