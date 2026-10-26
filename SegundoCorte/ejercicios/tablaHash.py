import time


class TablaHash:
    def __init__(self, capacidad=8):
        self.cap = capacidad
        self.cubetas = [[] for _ in range(self.cap)]   # encadenamiento
        self.n = 0

    def _hash(self, clave):
        h = 0
        for c in str(clave):
            h = (h * 31 + ord(c)) % self.cap           # 31: primo, dispersa bien
        return h

    def insertar(self, clave, valor):
        i = self._hash(clave)
        for par in self.cubetas[i]:
            if par[0] == clave:
                par[1] = valor                         # ACTUALIZA, no duplica
                return
        self.cubetas[i].append([clave, valor])
        self.n += 1

    def buscar(self, clave):
        i = self._hash(clave)
        for k, v in self.cubetas[i]:                   # recorre SOLO esa cubeta
            if k == clave:
                return v
        return None

    def eliminar(self, clave):
        i = self._hash(clave)
        for idx, (k, _) in enumerate(self.cubetas[i]):
            if k == clave:
                self.cubetas[i].pop(idx)
                self.n -= 1
                return True
        return False

    def distribucion(self):
        return [len(c) for c in self.cubetas]

    def factor_carga(self):
        return self.n / self.cap


# ---------- Demostracion ----------
codigos = ["REC-001", "REC-002", "REC-003", "EQ-100",
           "EQ-101", "PA-007", "PA-008", "EST-42"]

t = TablaHash(8)
for c in codigos:
    t.insertar(c, "valor de " + c)

print("distribucion por cubeta:", t.distribucion())
print("factor de carga        :", t.factor_carga())
print("buscar REC-002         :", t.buscar("REC-002"))
print("buscar NO-EXISTE       :", t.buscar("NO-EXISTE"))
t.insertar("REC-002", "valor NUEVO")
print("actualizar REC-002     :", t.buscar("REC-002"), "| n =", t.n)
print("eliminar EQ-100        :", t.eliminar("EQ-100"))
print("distribucion despues   :", t.distribucion())
print("colisiones (cubetas con mas de un elemento):",
      sum(1 for x in t.distribucion() if x > 1))

# ---------- Medicion: lista vs tabla hash ----------
N, B = 20000, 200
lista = [("COD-%05d" % i, i) for i in range(N)]
tabla = TablaHash(32768)
for k, v in lista:
    tabla.insertar(k, v)
objetivo = "COD-%05d" % (N - 1)                      # el ULTIMO: peor caso de la lista

t0 = time.perf_counter()
for _ in range(B):
    for k, v in lista:
        if k == objetivo:
            break
t_lista = time.perf_counter() - t0

t0 = time.perf_counter()
for _ in range(B):
    tabla.buscar(objetivo)
t_tabla = time.perf_counter() - t0

print(f"\n{B} busquedas sobre {N} elementos:")
print(f"  lista (recorre) : {t_lista:.5f} s")
print(f"  tabla hash      : {t_tabla:.5f} s")
print(f"  la tabla fue ~{t_lista / t_tabla:.0f} veces mas rapida")