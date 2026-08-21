class Usuario:
    def __init__(self, nombre, documento):
        self._nombre          = nombre
        self._documento       = documento
        self._tiene_sanciones = False

    def puede_solicitar(self):   # <- logica real
        return not self._tiene_sanciones