from typing import Sequence

def busqueda_secuencial(a: Sequence[int], x: int) -> int:
    """Índice de la primera aparición de x, o -1. Sin precondiciones."""
    for i in range(len(a)):
        if a[i] == x:
            return i
    return -1

# Versión pythónica equivalente
def busqueda_secuencial_pythonica(a, x):
    for i, v in enumerate(a):
        if v == x:
            return i
    return -1

#recursiva
def secuencial_rec(a, x, i=0):
    if i >= len(a): return -1
    if a[i] == x:   return i
    return secuencial_rec(a, x, i + 1)