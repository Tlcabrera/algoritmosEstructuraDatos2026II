#Un  a<rbol binario de búsqueda: todas las claves del subarbol izquierdo deben ser menores que las de la clave del nodo y todas
# las del derecho deben ser mayores. BTS
def insertar(n, clave):
    if n is None:                     # llegamos a un hueco: aqui va
        return Nodo(clave)
    if clave < n.clave:
        n.izq = insertar(n.izq, clave)   # el retorno se REENGANCHA
    elif clave > n.clave:
        n.der = insertar(n.der, clave)
    return n                           # clave repetida: no se inserta
# eliminar nodo (hoja) se boraa y su lugar queda nulo
# el nodo tiene un hijo el hijo debe subir aocupar el lugar del padre y el subarblo se reengancha al abuelo
# el nodo tiene dos hijos se busca un sucesor inorden (minimo del subarbol derecho) secopia la clave
# en  el nodo y se elimina el sucesor inorden (que es hoja o tiene un hijo derecho)