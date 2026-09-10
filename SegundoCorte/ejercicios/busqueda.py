#Busquedas secuenciales -BusquedasBinarias
def binaria(v, x):
    izq, der = 0, len(v) - 1
    while izq <= der:
        medio = (izq + der) // 2
        if v[medio] == x:   return medio
        elif v[medio] < x:  izq = medio + 1   # descarto la mitad izquierda
        else:               der = medio - 1   # descarto la mitad derecha
    return -1
#A[0..n-1] clave x xEA indice i tal que A[i] = x, o -1 si no existe