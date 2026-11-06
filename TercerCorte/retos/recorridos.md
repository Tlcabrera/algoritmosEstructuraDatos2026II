Recorridos DFS

Reto 1 — El detector de islas   ·   Obligatorio
Sobre la red de su proyecto, escriba un informe automático que diga cuántas componentes hay, cuáles vértices tiene cada una, y cuál es la más grande. Después elimine dos aristas a propósito y vuelva a correrlo.

Pista: La componente de un vértice se identifica con un número: asigne a cada vértice el índice de la componente a la que pertenece durante el recorrido.

Resultado esperado: Un informe legible, no una lista de números. Debe decir, por ejemplo, 'la red está partida en 3 zonas; la zona 2 tiene 4 puntos y no tiene conexión con el centro'.

Reto 2 — El plan de estudios imposible   ·   Obligatorio
Construya un grafo DIRIGIDO de prerrequisitos con al menos seis asignaturas e introduzca a propósito un ciclo. Escriba un detector de ciclos para grafos dirigidos y haga que informe cuáles asignaturas forman el ciclo.

Pista: En un grafo dirigido la regla del padre NO sirve. Se necesitan tres estados por vértice: sin visitar, en proceso, y terminado. Encontrar un vecino en proceso es el ciclo.

Resultado esperado: El programa debe imprimir la secuencia de asignaturas del ciclo, no solo decir que existe.

Reto 3 — El camino más largo (reto corchador)   ·   Obligatorio
Escriba una función que encuentre el camino más LARGO sin repetir vértices entre dos puntos de la red. Mida cuánto tarda con 9 vértices, con 15 y con 20.

Pista: Esto no es DFS con visitado: hay que desmarcar al regresar, como en el backtracking de la sesión 15. Y cuidado con el tiempo.

Resultado esperado: Al llegar a 20 vértices el programa se vuelve impracticable. Eso no es un error suyo: el problema del camino más largo es NP-difícil. Escriba un párrafo explicando por qué el camino más CORTO sí es fácil (sesión 42) y el más largo no.

Recorridos BFS

Reto 1 — El módulo de rutas   ·   Obligatorio · entregable del taller
Sobre la red de su proyecto, escriba ruta(origen, destino) que devuelva el camino con menos tramos y su longitud, o un mensaje claro si no hay camino. Pruébelo con un destino alcanzable y con uno que no lo sea.

Pista: El caso sin camino es el que casi nadie prueba. Si dist[destino] sigue en −1 al terminar el BFS, no hay ruta.

Resultado esperado: La función debe manejar correctamente los tres casos: ruta normal, origen igual a destino, y destino inalcanzable.

Reto 2 — Los grados de separación   ·   Obligatorio
Calcule, para cada par de vértices de su red, la distancia mínima entre ellos. Reporte el diámetro de la red, que es la mayor de todas esas distancias, e identifique qué par de puntos lo produce.

Pista: Un BFS desde cada vértice. Son V recorridos de O(V+E), es decir O(V·(V+E)) en total. Para redes pequeñas es perfectamente viable.

Resultado esperado: El diámetro y el par de puntos más alejados. Interprete el resultado: ¿qué significa para la operación de su sistema?

Reto 3 — La propagación por olas (reto corchador)   ·   Obligatorio
Suponga que una falla se origina en un punto y se propaga a los vecinos en un minuto. Escriba un programa que diga en qué minuto queda afectado cada punto y cuántos minutos tarda en caer toda la red. Luego responda: ¿desde qué punto conviene MENOS que empiece la falla?

Pista: La respuesta a la primera parte es literalmente el arreglo dist. La segunda parte pide buscar el vértice que minimiza la excentricidad, que es lo que haremos en la sesión 43.

Resultado esperado: El punto desde el cual la falla tarda más en propagarse es el punto más periférico de la red. Nómbrelo y explique por qué un centro de distribución debería estar en el extremo opuesto.
