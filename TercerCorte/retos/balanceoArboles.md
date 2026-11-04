Reto 1: Rotacion Manual
Escriba un pequeño programa que lea por teclado tres claves en el orden en que se insertarían, construya el árbol SIN balancear, diagnostique cuál de los cuatro casos es (o si está equilibrado) y aplique la rotación correcta. Debe imprimir el árbol antes y después.
Pista: El diagnóstico sale de dos números: el fe del nodo y el fe de su hijo del lado pesado. No necesita más.
Resultado esperado: Con 30, 10, 20 debe diagnosticar LR. Con 10, 20, 30 debe diagnosticar RR. Con 10, 30, 20 debe diagnosticar RL.

Reto 2 — El orden maldito   ·   Obligatorio
Encuentre un orden de inserción de las siete claves 1 a 7 que produzca un BST perfectamente equilibrado (altura 2) sin aplicar ninguna rotación. Después encuentre el peor orden posible. Explique qué tienen en común todos los órdenes que dan altura 2.
Pista: Piense en qué clave tiene que llegar primero para que el árbol quede partido por la mitad. Luego repita el razonamiento en cada mitad.
Resultado esperado: Hay varios órdenes válidos. Todos empiezan por el 4. Cuente cuántos son: la respuesta es un número sorprendentemente grande.

Reto 3 — ¿Cuándo NO alcanza una rotación? (reto corchador)   ·  Obligatorio
Construya un árbol donde, después de aplicar la rotación correcta en el nodo desbalanceado más profundo, QUEDE otro nodo desbalanceado más arriba. ¿Es posible en una inserción? ¿Y en una eliminación?
Pista: En inserción, una sola rotación siempre basta y eso se puede demostrar mirando cómo cambia la altura del subárbol. En eliminación no: la altura puede reducirse y propagar el problema hacia la raíz.

