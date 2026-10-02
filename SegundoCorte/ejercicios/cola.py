#FIFO

class cola:
    def __init__(self): self.frente = None; self.final = None; self.n = 0
 
    def encolar(self, x):
        nuevo = self._Nodo(x)
        if self.final is None: self.frente = self.final = nuevo   # cola vacia
        else: self.final.siguiente = nuevo; self.final = nuevo
        self.n += 1
 
    def desencolar(self):
        if self.frente is None: return None
        x = self.frente.dato
        self.frente = self.frente.siguiente
        if self.frente is None: self.final = None    
        self.n -= 1
        return x
    
#Llegan: 1, 2, 3, 4
#Salen dos
#Llega: 5
#Salen todosV

