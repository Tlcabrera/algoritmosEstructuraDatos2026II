uso = [
    [4, 2, 6, 1, 3],
    [0, 5, 5, 2, 7],
    [8, 1, 0, 4, 2],
]
 
print("Total por recurso (filas):")
for i, fila in enumerate(uso):
    print(f"  Recurso {i}: {sum(fila)}")
 
print("Total por dia (columnas):")
for j in range(len(uso[0])):
    total = 0
    for i in range(len(uso)):
        total += uso[i][j]
    print(f"  Dia {j}: {total}")
