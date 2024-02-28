# Descrição

# Na épica reunião anual de entusiastas da cultura pop, onde os participantes respiram paixão por filmes, 
# séries e ícones nerds, a busca por novas experiências é tão constante quanto bater o coração em uma cena 
# emocionante de um filme favorito. Este ano, a convenção anseia por uma surpresa que ultrapasse os limites 
# do convencional. Assim, eles forjaram um desafio único, uma aventura de adivinhação que testará as habilidades 
# dos participantes em decifrar códigos enigmáticos. Imagine-se imerso nesse cenário repleto de cosplayers que ganham 
# vida, painéis que sussurram segredos e estandes repletos de colecionáveis cobiçados. Agora, é o seu momento de brilhar 
# e criar um jogo que não apenas desafiará os fãs da cultura pop, mas também elevará a diversão da convenção a níveis épicos, 
# deixando todos maravilhados com a experiência. Prepare-se para mergulhar nas profundezas da imaginação nerd e surpreender 
# todos os participantes com uma aventura única e interativa!

# Menu

# Ao iniciar o programa, uma saudação será apresentada ao usuário e, em seguida, revelaremos o Menu Interdimensional de Opções 
# para os verdadeiros fãs da cultura pop:

# 1. Embarcar em uma Nova Missão;
# 2. Explorar o último desafio;
# 3. Abandonar a Convenção (Sair).

# Se você, nobre aventureiro interdimensional, digitar algo que não seja um dos números sagrados de 1 a 3, temerariamente 
# informaremos que essa dimensão não existe e, então, apresentaremos novamente o Menu Interdimensional de Opções, esperando 
# sua escolha.

# Novo jogo

# Ao selecionar a opção 1, o seu programa começará uma nova missão interdimensional. Nesse desafio, o computador escolherá 
# um código de 1 a 100, cuidadosamente selecionado nas estrelas. O jogador, munido de sua astúcia, deve decifrar esse código, 
# enviando uma transmissão com um número dentro desse mesmo intervalo. Se o jogador desviar-se do caminho, o programa responderá, 
# informando se o número transmitido está em uma órbita mais elevada (é maior) ou em uma galáxia distante em relação ao número 
# secreto (é menor). No entanto, quando a sintonia é perfeita (é igual), a vitória será celebrada em todas as dimensões conhecidas, 
# e o programa revelará o número de tentativas em que o jogador decifrou o código com sucesso.

# Registro do último jogo

# Ao escolher a opção 2 no Menu Interdimensional, o jogador poderá visualizar o registro do último jogo, incluindo a) o nome do jogador 
# e b) o número de tentativas necessárias para decifrar o código secreto. Após exibir o registro do último jogo, o programa deve exibir 
# novamente o menu de opções.

# Encerrar o jogo

# Para sair do jogo, basta que o usuário escolha a opção 3 do menu. O programa deve ser encerrado, imprimindo uma mensagem heróica.

# usei esse import para facilitar a criação do numero randomico

import random

ultima = {}

while True:
    # apresentação do menu

    print(
        "Bem vindo meu padrinho, neste momento você esta diante uma grande oportunidade de entretenimento, nela voce pode testar sua sorte em um pequeno e breve jogo, aceitas meu consagrado?"
    )
    print("\nMenu Interdimensional de Opções:")
    print("1. Iniciar novo jogo")
    print("2. Explorar o último desafio")
    print("3. Abandonar o desafio (Sair)")
    escolha = input("Escolhe rapido ai paizão entre (1-3): ")

    # Ao apertar a tecla 1 você entra no codigo do jogo de advinhação onde o numero que você precisa achar e gerado pelo random.randint

    if escolha == "1":
        # info basicas para a opção '2' fazer uso no futuro como nome, maquina (numero que precisa ser achado) e tentativas

        Nome = input("Diga seu nome para começar: ")
        maquina = random.randint(1, 100)
        Tentativas = 0
        print(maquina)
        print("\n Vamos comecar!")
        print("Escolha um numero de 1 a 100 campeão")

        # laço de repetição para achar o numero randomico, a cada tentativa falha mais um numero e acrescentado ao contador de tentativa e dicas que facilitam o encontro do numero surgem

        while True:
            Tentativa = int(input("Tente um numero:"))
            Tentativas += 1
            diferenca = Tentativa - maquina
            if Tentativa == maquina:
                print(f"Boa chefe, Acertou em {Tentativas}")
                ultima = {
                    "Nome": Nome,
                    "Tentativas": Tentativas,
                    "Numero_Secreto": maquina,
                }
                break
            elif -5 < diferenca <= 5:
                print("Se não acertar,Desiste meu nobre")
            elif -25 < diferenca <= 25:
                print("Ta mais quente que o rj")
            elif -40 < diferenca <= 40:
                print("Tamo la paizão, so mais um pouco")
            elif -65 < diferenca <= 65:
                print("Tu não é muito bom de chute né chefe?")
            elif -89 < diferenca <= 89:
                print("Pra voce, gastar grana no jogo do bicho é desperdicio")
            elif -99 < diferenca <= 99:
                print("VERGONHAAAA, DESGRAÇAAAA,HUMILHAÇÃO PARA TODA UMA RAÇA")

                # ao escolher a opção dois, eles puxam os dados de tentativa, nome e numero random da opção '1'
    elif escolha == "2":
        if ultima:
            print("\nRegistro do Último Jogo:")
            print(f"Nome do jogador: {ultima['Nome']}")
            print(f"Tentativas: {ultima['Tentativas']}")
            print(f"Número Secreto: {ultima['Numero_Secreto']}")
        else:
            print("Nenhum jogo anterior registrado.")

        pass

        # ao escolher a opção três o jogo finaliza com uma mensagem de despedida

    elif escolha == "3":
        print("Obrigado por participar, adeus!")
        break
    else:
        print("Escolha novamente.")
