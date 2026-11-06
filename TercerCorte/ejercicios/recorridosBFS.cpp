#include <queue>
 
void bfs(int inicio, vector<int>& orden, vector<int>& dist, vector<int>& padre) {
    vector<bool> vis(N, false);
    dist.assign(N, -1); padre.assign(N, -1); orden.clear();
    queue<int> cola;
    cola.push(inicio); vis[inicio] = true; dist[inicio] = 0;
    while (!cola.empty()) {
        int u = cola.front(); cola.pop();    // FIFO
        orden.push_back(u);
        for (int v : lista[u]) if (!vis[v]) {
            vis[v]   = true;                 // se marca al ENCOLAR
            dist[v]  = dist[u] + 1;
            padre[v] = u;
            cola.push(v);
        }
    }
}

/*
NIVELES (todos los que estan a la misma distancia)
  nivel 0: CENTRO
  nivel 1: NORTE, SUR, ORIENTE
  nivel 2: OCCIDENTE, CHAPINERO, USAQUEN, BOSA
  nivel 3: VEREDA
 
CAMINO MAS CORTO desde CENTRO (en numero de tramos)
  hacia BOSA      : CENTRO -> SUR -> BOSA   (2 tramos)
  hacia USAQUEN   : CENTRO -> ORIENTE -> USAQUEN   (2 tramos)
  hacia OCCIDENTE : CENTRO -> NORTE -> OCCIDENTE   (2 tramos)
 
  DFS hacia BOSA : CENTRO -> NORTE -> OCCIDENTE -> BOSA   (3 tramos)
  BFS hacia BOSA : CENTRO -> SUR -> BOSA   (2 tramos)
  BFS garantiza el minimo numero de tramos; DFS solo garantiza que llega.


*/
