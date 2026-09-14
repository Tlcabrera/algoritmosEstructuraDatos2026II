# Fragmento 1
def factorial(n):
    return n * factorial(n - 1)
# Fragmento 2
def suma(lista, i):
    if i >= len(lista):
        return 0
    return lista[i] + suma(lista, i)
# Fragmento 3  (dentro del laberinto)
camino[f][c] = 1
if resolver(f+1, c): return True
if resolver(f, c+1): return True
return False

def infinita(n):
    return infinita(n + 1)     # nunca llega a un caso base
 
infinita(0)


