# Problema do Tromino (tiling de um tabuleiro 2^n x 2^n com um buraco)

# Variável global que serve como contador de peças
nt = 0

def azulejo(r, c, l, rb, cb, P):
    """
    r, c : canto superior esquerdo da submatriz
    l    : tamanho do lado da submatriz
    rb, cb : posição do buraco dentro da submatriz
    P    : matriz solução
    """
    global nt
    if l > 1:
        nt += 1
        m = l // 2
        rmid = r + m
        cmid = c + m

        # Quadrante superior esquerdo
        if rb < rmid and cb < cmid:
            rNWb, cNWb = rb, cb
        else:
            rNWb, cNWb = rmid - 1, cmid - 1
            P[rNWb][cNWb] = nt

        # Quadrante inferior esquerdo
        if rb >= rmid and cb < cmid:
            rSWb, cSWb = rb, cb
        else:
            rSWb, cSWb = rmid, cmid - 1
            P[rSWb][cSWb] = nt

        # Quadrante inferior direito
        if rb >= rmid and cb >= cmid:
            rSEb, cSEb = rb, cb
        else:
            rSEb, cSEb = rmid, cmid
            P[rSEb][cSEb] = nt

        # Quadrante superior direito
        if rb < rmid and cb >= cmid:
            rNEb, cNEb = rb, cb
        else:
            rNEb, cNEb = rmid - 1, cmid
            P[rNEb][cNEb] = nt

        # Chama recursivamente para os 4 quadrantes
        azulejo(r, c, m, rNWb, cNWb, P)
        azulejo(r + m, c, m, rSWb, cSWb, P)
        azulejo(r + m, c + m, m, rSEb, cSEb, P)
        azulejo(r, c + m, m, rNEb, cNEb, P)


def resolver_tromino(n, rb, cb):
    """
    n  : expoente do tamanho do tabuleiro (tabuleiro de tamanho 2^n)
    rb, cb : coordenadas do buraco (0-indexadas)
    """
    global nt
    nt = 0
    l = 2 ** n
    P = [[-1 for _ in range(l)] for _ in range(l)]
    P[rb][cb] = 0  # marca o buraco original com 0
    azulejo(0, 0, l, rb, cb, P)
    return P


# Exemplo de execução
if __name__ == "__main__":
    n = 3  # tabuleiro 8x8
    rb, cb = 2, 3  # buraco em (2,3)
    P = resolver_tromino(n, rb, cb)

    # imprime a matriz solução
    for linha in P:
        print(" ".join(f"{x:2}" for x in linha))
