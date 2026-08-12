# vector estatico
#.len()

#lecturas=[23.5, 24.0, 22.8, 25.3, 24.7]
#lecturas.len()
#El problema: calcular máximo, 
# #mínimo y promedio de un conjunto de lecturas(datos)
lecturas = [23, 7, 91, 45, 7, 60, 12, 88]
 
maximo = lecturas[0]
minimo = lecturas[0]
suma   = 0
 
for valor in lecturas:          # Python recorre el elemento, no el indice
    if valor > maximo:
        maximo = valor
    if valor < minimo:
        minimo = valor
    suma += valor
 
promedio = suma / len(lecturas)  # en Python 3 la division ya es real
 
print(f"Maximo:   {maximo}")
print(f"Minimo:   {minimo}")
print(f"Promedio: {promedio}")
