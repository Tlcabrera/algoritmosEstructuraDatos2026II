/*
Grafo: es un conjunto de nodos (vertices) y aristas(hilos) que conectan esos nodos
arbol de n nodos tiene n-1 aristas no ciclos
grafo puede tener desde 0 hasta n(n-1)/2 aristas ciclicas
grado: número de aristas incidentes en un nodo
no dirigido: aristas no tienen dirección
dirigido: aristas tienen dirección
ponderado: aristas tienen un peso asociado
caminos: secuencia de aristas que conectan nodos
ciclos: camino que empieza y termina en el mismo nodo
conexo: si existe un camino entre cada par de nodos

Matriz de adyacencia: matriz cuadrada de n x n donde n es el número de nodos, 
si hay una arista entre el nodo i y j, entonces la posición (i,j) es 1, sino es 0
lista de adyacencia: lista de listas donde cada lista contiene los nodos adyacentes a un nodo


vector<vector<int>> matriz(N, vector<int>(N, 0));
for (auto [u, v] : ARISTAS) {
    matriz[u][v] = 1;
    matriz[v][u] = 1;         // no dirigido: la matriz es simetrica
}
bool hayVia(int u, int v) { return matriz[u][v] == 1; }  // O(1)
*/
