from listaValori import ListaValori as ls
from test.test import Test as ts

if __name__ == "__main__":
    m = ls()
    m.add(1)
    m.print()

    t = ts(1,4)

    calc = t.computer(1,1)

    print(f"Calcolo -> {calc}")
