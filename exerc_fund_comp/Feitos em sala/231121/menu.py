def menu():
    print(
        """
        1 - Inserir número
        2 - Buscar número
            * Buscar Sequencial
            * Busca Binária
        3 - Exibir lista
        4 - Sair
        """
    )
    return int(input())


vetor = []
isOrdenado = False
nAnt = 0
n = 0
pos = 0

while True:
    match (menu()):
        ## Inserir número
        case 1:
            n = int(input("Informe o valor que deseja inserir no vetor: "))
            vetor.append(n)
            ## Se o valor na posição anterior for menor que ou igual ao número
            ## que acabou de ser inserido, então o vetor está ordenado
            if vetor[pos - 1] <= n:
                isOrdenado = True
            else:
                isOrdenado = False
            pos += 1
            continue
        ## Buscar número
        case 2:
            nBusca = int(input("Informe o valor que deseja buscar no vetor: "))
            ## Se estiver ordenado, faz busca binária
            ## Se não, faz busca sequencial
            if isOrdenado:
                print("Utilizando a busca binária...")
                exist = False
                p = 0
                inf = 0
                sup = len(vetor) - 1
                while inf <= sup:
                    meio = int((inf + sup) / 2)
                    if vetor[meio] == nBusca:
                        exist = True
                        p = meio + 1
                        break
                    elif nBusca < vetor[meio]:
                        sup = meio - 1
                    else:
                        inf = meio + 1

                if exist:
                    print(f"O valor {nBusca} está na posição {p}.")
                else:
                    print(f"O valor {nBusca} não está presente no vetor.")
                continue

            else:
                print("Utilizando a busca sequencial...")
                exist = False
                p = 0
                for i in range(len(vetor)):
                    if vetor[i] == nBusca:
                        exist = True
                        p = i + 1
                        break

                if exist:
                    print(f"O valor {nBusca} está na posição {p}.")
                else:
                    print(f"O valor {nBusca} não está presente no vetor.")
                continue
        ## Exibir lista
        case 3:
            print(f"Lista: {vetor}")
            continue
        ## Sair
        case 4:
            print("Saindo...")
            break
        ## Default
        case _:
            print("Por favor, selecione um número das opções disponíveis")
            continue
