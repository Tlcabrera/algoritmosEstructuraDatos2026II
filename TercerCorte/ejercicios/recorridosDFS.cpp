/*  DFS 3 instrucciones y 1 condicion 
marcar el vertice como visitado
procesar el vertice
para cada vecino no visitado repetir el proceso
condicion es el no visitado

version recursiva usa pila
version iterativa hacer expicita la pila
*/

void dfsRec(int u, vector<bool>& vis, vector<int>& orden) {
    vis[u] = true;              // el hilo de Ariadna
    orden.push_back(u);
    for (int v : lista[u])
        if (!vis[v]) dfsRec(v, vis, orden);
}


// version iterativa
vector<int> dfsIter(int inicio) {
    vector<bool> vis(N, false);
    vector<int> pila{inicio}, orden;
    while (!pila.empty()) {
        int u = pila.back(); pila.pop_back();   // LIFO
        if (vis[u]) continue;                    // pudo entrar dos veces
        vis[u] = true;
        orden.push_back(u);
        for (auto it = lista[u].rbegin(); it != lista[u].rend(); ++it)
            if (!vis[*it]) pila.push_back(*it);
    }
    return orden;
    /*
      orden de visita: CENTRO -> NORTE -> OCCIDENTE -> BOSA -> SUR -> VEREDA -> CHAPINERO -> USAQUEN -> ORIENTE
 
DFS ITERATIVO (con pila explicita) desde CENTRO
  orden de visita: CENTRO -> NORTE -> OCCIDENTE -> BOSA -> SUR -> VEREDA -> CHAPINERO -> USAQUEN -> ORIENTE
 
COMPONENTES CONEXAS de la red completa: [['CENTRO', 'NORTE', 'OCCIDENTE', 'BOSA', 'SUR', 'VEREDA', 'CHAPINERO', 'USAQUEN', 'ORIENTE']]
COMPONENTES de una red con tramos cortados: [['CENTRO', 'NORTE', 'SUR'], ['ORIENTE', 'USAQUEN'], ['OCCIDENTE'], ['CHAPINERO'], ['BOSA'], ['VEREDA']]
¿La red tiene algun circuito? True

    */