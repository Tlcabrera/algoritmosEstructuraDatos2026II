def rebind(lista):
    lista = [99, 99]          # REASIGNA el nombre local
    print("   dentro (rebind):  ", lista)
 
def mutar(lista):
    lista.append(99)          # MUTA el objeto original
    print("   dentro (mutar):   ", lista)
 
datos = [1, 2, 3]
print("antes:", datos)
rebind(datos)
print("despues de rebind:", datos)
 
datos = [1, 2, 3]
mutar(datos)
print("despues de mutar: ", datos)
 
a = [1, 2, 3]
b = a
print("a is b :", a is b, "| mismo id:", id(a) == id(b))
b.append(4)
print("a tras b.append(4):", a)
