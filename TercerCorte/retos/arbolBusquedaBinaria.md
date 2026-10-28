Reto 1 — El índice de recursos   ·   Obligatorio
Modifique el nodo para que guarde código y nombre. Inserte al menos diez recursos de su línea de proyecto. Implemente listarOrdenado() e informe(codigo) que imprima el nombre o un mensaje de no encontrado, indicando cuántas comparaciones hizo.
Pista: La comparación se hace siempre sobre el código, nunca sobre el nombre. Si compara por nombre, la invariante se rompe para las búsquedas por código.
Resultado esperado: El listado debe salir ordenado por código sin llamar a ningún sort.

Reto 2 — El rango   ·   Obligatorio
Escriba enRango(nodo, a, b) que imprima todas las claves entre a y b, ambas incluidas, en orden ascendente. La gracia está en que NO debe visitar todo el árbol: si la clave del nodo es menor que a, no tiene sentido bajar por la izquierda.
Pista: Es un inorden con dos podas. Agregue un contador de nodos visitados y compare contra el total del árbol: debe ser menor.
Resultado esperado: Con el árbol del ejemplo y el rango [35, 65], debe imprimir 35, 40, 50, 60 visitando menos de 8 nodos.

Reto 3 — El detector de impostores (reto corchador)   
Escriba esBST(nodo) que determine si un árbol binario cualquiera cumple la invariante. Luego constrúyale este contraejemplo: raíz 50, hijo izquierdo 30, y como hijo DERECHO del 30 ponga un 60. Si su función dice que es un BST, está mal.
Pista: Comparar cada nodo solo con sus dos hijos no basta. Cada nodo tiene un rango permitido que se va estrechando al bajar; pásele a la recursión los límites mínimo y máximo admisibles.
Resultado esperado: El contraejemplo debe dar falso, porque el 60 está en el subárbol izquierdo del 50 y es mayor que 50.
