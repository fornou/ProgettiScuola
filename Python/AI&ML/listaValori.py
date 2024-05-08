from typing import List as l

class ListaValori:
    def __init__(self) -> None:
        # self.a: list[int] | None = None
        self.a: l[int] = []

    def add(self, v: int):
        self.a.append(v)

    def print(self):
        for e in self.a:
            print(f"value -> {e}")