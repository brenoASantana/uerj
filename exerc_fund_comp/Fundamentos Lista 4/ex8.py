habA = 5000000
habB = 7000000
natA = 0.03
natB = 0.02
tempo = 0

while habA <= habB:
    habA += habA * 0.03
    habB += habB * 0.02
    tempo += 1
print(
    f"O tempo necessário para que a população do país A ultrapasse ou iguale a população do país B é de {tempo} anos."
)
