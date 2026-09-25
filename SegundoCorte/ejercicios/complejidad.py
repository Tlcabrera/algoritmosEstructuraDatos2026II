# notaciones dependen las ordenes 
#Big O
# O(1) - constante no cambia con el tamaño de la entrada v[i]
#
# - logaritmica, divide el problema en partes iguales,busqueda binaria (sube uno o dos pasos mas)
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

#anotar una secuencia de pasos un  algoritmo 
#1. ¿Qué es n en esa secuencia?
#2. Cuántas veces se ejecutqa el proceso si se
#duplican los datos
#3. Dentro de esa secuencia se invoca otro porceso
#cuantos procesos se invocan
#4. que tipo de estructura de datos se
#utiliza
#1. Regla de la suma : codigo en secuencia,
# se suman los tiempos de cada proceso
Suma
for x in v: ...        # O(n)
for y in v:            # O(n^2)
    for z in v: ...
# total: O(n) + O(n^2) = O(n^2)
#2. Regla de producto: codigo anidado, 
# se multiplican los tiempos de cada proceso
Producto
for i in range(n):
    a=len(v)# n veces
    for j in range(m):    # por cada una, m veces
        ...               # total: O(n*m)
        
#llamadas a funciones
El error más caro
for x in lista:           # n veces
    if buscar(otra, x):   # y buscar es O(m)
        ...               # total: O(n*m), NO O(n)
#Clasifique
# 1
for i in range(n):
    for j in range(i):      # <- ojo: j depende de i
        ...
 
# 2
    i = n
    while i > 1:
    i = i // 2
 
# 3
for i in range(n):
    j = n
    while j > 1:
        j = j // 2


