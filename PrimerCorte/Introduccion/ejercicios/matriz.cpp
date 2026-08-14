// Matriz estatica: tamano conocido al compilar
int uso[3][5];
 
// Matriz dinamica: arreglo de punteros a arreglos
int** m = new int*[filas];
for (int i = 0; i < filas; i++)
    m[i] = new int[columnas];
 
// Liberar en orden inverso al que se reservo
for (int i = 0; i < filas; i++) delete[] m[i];
delete[] m;
# Matriz como lista de listas
filas, columnas = 3, 5
m = [[0 for _ in range(columnas)] for _ in range(filas)]

# FORMA INCORRECTA
mala = [[0] * 3] * 2
mala[0][0] = 99
print("Mala :", mala)
 
# FORMA CORRECTA
buena = [[0] * 3 for _ in range(2)]
buena[0][0] = 99
print("Buena:", buena)

