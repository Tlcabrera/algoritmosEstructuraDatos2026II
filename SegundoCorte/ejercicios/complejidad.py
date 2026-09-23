# notaciones dependen las ordenes 
#Big O
# O(1) - constante no cambia con el tamaño de la entrada v[i]
# O(log n) - logaritmica, divide el problema en partes iguales,busqueda binaria (sube uno o dos pasos mas)
# O(n) - lineal, recorre todos los elementos de la entrada, busqueda secuencial(se dobla) recorrer lista enlazada
# O(n log n) - logaritmica lineal, divide el problema en partes iguales y recorre todos los elementos de la entrada, mergesort, quicksort (un poco mas del doble)
# O(n^2) - cuadratica, recorre todos los elementos de la entrada y para cada elemento recorre todos los elementos de la entrada, bubble sort, selection sort, insertion sort (cuadruplica)
#Regla 1: se ignoran las constantes y los terminos de menor orden
#regla 2: manda terminos quemás crece.

# A
def primero(v):
    return v[0]
 
# B
def sumar(v):
    s = 0
    for x in v: s += x
    return s
 
# C
def pares(v):
    c = 0
    for x in v:
        for y in v: c += 1
    return c
 
# D
def mitad(v, x):
    izq, der = 0, len(v)-1
    while izq <= der:
        m = (izq+der)//2
        if v[m] == x: return m
        elif v[m] < x: izq = m+1
        else: der = m-1
    return -1

#E
def engañoso(v):
    for i in range(len(v)):
        for j in range(5):        
            print(v[i], j)
#tabla de complejidad
#CLASIFICAR LA COMPLEJIDAD DE TODOS LOS ALGORITMOS 
# DE ORDENAMIENTO VISTOS EN CLASE
#codacy code codacy
