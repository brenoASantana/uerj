a = 642
b = 231

if b > a:
    a, b = b, a

restos = [a, b]
quocientes = [None, None]
ms = [1, 0]
ns = [0, 1]

while restos[-1] != 0:
    quocientes.append(restos[-2] // restos[-1])
    restos.append(restos[-2] % restos[-1])
    ms.append(ms[-2] - quocientes[-1] * ms[-1])
    ns.append(ns[-2] - quocientes[-1] * ns[-1])

print(f"mdc({a}, {b}) = {restos[-2]}")
print(f"{restos[-2]} = ({ms[-2]}) * {a} + ({ns[-2]}) * {b}")

print(f"Restos: {restos}")
print(f"Quocientes: {quocientes}")
print(f"ms: {ms}")
print(f"ns: {ns}")
