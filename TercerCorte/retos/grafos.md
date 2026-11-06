Reto 1 — La red del proyecto   ·   Obligatorio
Modele la red real de su línea con mínimo diez vértices y quince aristas. Impleméntela en las dos representaciones, calcule la densidad y escriba dos líneas justificando cuál usará el proyecto.
Pista: Si su línea es la 3, la red de prerrequisitos es DIRIGIDA: la matriz no es simétrica y la lista guarda solo una dirección. Dígalo explícitamente en su justificación.
Resultado esperado: Las dos representaciones funcionando sobre los mismos datos y una decisión argumentada con la densidad calculada.

Reto 2 — El converso   ·   Obligatorio
Escriba matrizALista(m) y listaAMatriz(l) que conviertan una representación en la otra. Verifique que convertir ida y vuelta devuelve el original.
Pista: La verificación de ida y vuelta es la prueba más barata y más efectiva que existe para este tipo de funciones. Escríbala antes que las conversiones.
Resultado esperado: listaAMatriz(matrizALista(m)) debe ser igual a m para cualquier m válida.

Reto 3 — El grafo imposible (reto corchador)   ·   Obligatorio
¿Existe un grafo no dirigido de cinco vértices donde todos tengan grado 3? Intente dibujarlo. Si cree que no existe, demuéstrelo. Después generalice: ¿para qué combinaciones de V y grado es imposible?
Pista: Sume los grados de todos los vértices de cualquier grafo y compare esa suma con el número de aristas. La relación que encuentre resuelve el problema de inmediato.

  V = 9 vertices,  E = 10 aristas
  Matriz : 81 casillas en memoria. ¿Existe arista? O(1). Recorrer vecinos: O(V) = 9 casillas.
  Lista  : 20 referencias en memoria. ¿Existe arista? O(grado). Recorrer vecinos: O(grado).
  Densidad = 2E / (V(V-1)) = 0.28  ->  grafo DISPERSO: conviene lista
  ¿CENTRO conecta con NORTE? matriz=True  lista=True
  ¿CENTRO conecta con BOSA? matriz=False  lista=False
  ¿CHAPINERO conecta con USAQUEN? matriz=True  lista=True
