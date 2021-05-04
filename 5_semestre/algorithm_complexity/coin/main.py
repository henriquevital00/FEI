import math
from collections import defaultdict

contagem = defaultdict(int)


def moedas(v, valor):
    contagem[valor] += 1

    if valor in v:
        return 1
    menor = math.inf

    for ma in v:
        if valor - ma > 0:
            solAtual = min(moedas(v, valor - ma) + 1, menor)

    return menor


print(moedas([1, 5, 10, 6], 10))
print(contagem)
