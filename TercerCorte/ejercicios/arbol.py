## Arbol, es una estructura no lineal que permite
# almacenar datos de manera jerárquica. 
# Cada elemento del árbol se llama nodo,
# y cada nodo puede tener cero o más nodos hijos.
# El nodo superior se llama raíz, 
# y los nodos sin hijos se llaman hojas.
# Raiz: Nodo principal del árbol.
# Nodo: cada elemento que almacena datos
# y puede tener hijos.
#ºPadre e hijo: Relación entre nodos, 
# donde un nodo padre tiene uno o más nodos hijos.
#hojas: Nodos que no tienen hijos.
#aristas: Conexiones entre nodos,
# que representan la relación padre-hijo.
# Tipos de arboles 
# Binario: Cada nodo puede tener como máximo dos hijos.
# Busqueda Binaria ABB: Árbol binario con la propiedad 
# de que para cada nodo, todos los valores 
# en el subárbol izquierdo son menores que el 
# valor del nodo, y todos los valores en el 
# subárbol derecho son mayores que el valor del nodo.
#Arboles de decision: Árboles utilizados en aprendizaje 
# automático para tomar decisiones basadas en las 
# características de los datos. modelos predictivos 
# que dividen los datos en función de
# características específicas para tomar
# decisiones o hacer predicciones. Scikit-learn 
# es una biblioteca de Python que 
# proporciona herramientas para construir y 
# entrenar modelos de aprendizaje automático, 
# incluyendo árboles de decisión.

# ejemplo de implementación 
class Nodo:
    def __init__(self, valor):
        self.valor = valor
        self.izquierdo = None
        self.derecho = None

# Crear la raíz y los primeros nodos
raiz = Nodo(10)
raiz.izquierdo = Nodo(5)
raiz.derecho = Nodo(15)
# recorridos (Pre / In / Post)
# CATALOGO, HERRAMIENTA, LIBRO, TALADRO, SIERRA, 
# ARTE, TECNICO y REDES. 
# recorrido por niveles o BFS