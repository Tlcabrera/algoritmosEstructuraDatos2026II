atras = []
adelante = []
actual = "inicio.com"

def visitar(url):
    global actual
    atras.append(actual)
    actual = url
    adelante.clear()
    print(f"Visitar   -> {actual}")

def ir_atras():
    global actual
    if not atras:
        print("No hay pagina anterior")
        return
    adelante.append(actual)
    actual = atras.pop()
    print(f"Atras     -> {actual}")

def ir_adelante():
    global actual
    if not adelante:
        print("No hay pagina siguiente")
        return
    atras.append(actual)
    actual = adelante.pop()
    print(f"Adelante  -> {actual}")

visitar("google.com")
visitar("wikipedia.org")
visitar("youtube.com")
ir_atras()
ir_atras()
ir_adelante()
visitar("github.com")
ir_adelante()