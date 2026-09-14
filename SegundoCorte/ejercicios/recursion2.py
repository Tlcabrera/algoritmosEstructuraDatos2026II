nivel = 0

def factorial(n):
    global nivel
    print("|  " * nivel + f"factorial({n}) entra")
    nivel += 1
    r = 1 if n <= 1 else n * factorial(n - 1)
    nivel -= 1
    print("|  " * nivel + f"factorial({n}) devuelve {r}")
    return r

def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)

print("--- traza de la pila de llamadas ---")
r = factorial(4)
print("Resultado:", r)
print()
print("fibonacci(10) =", fibonacci(10))

factorial(4) entra
|  factorial(3) entra
|  |  factorial(2) entra
|  |  |  factorial(1) entra
|  |  |  factorial(1) devuelve 1
|  |  factorial(2) devuelve 2
|  factorial(3) devuelve 6
factorial(4) devuelve 24
Resultado: 24
