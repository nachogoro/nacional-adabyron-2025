import dataclasses
from typing import *

T = TypeVar('T')


@dataclasses.dataclass
class Vector2D(Generic[T]):
    x: int
    y: int

    def __add__(self, other):
        return Vector2D(self.x + other.x, self.y + other.y)
    
    def __sub__(self, other):
        return Vector2D(self.x - other.x, self.y - other.y)
    
    def __mul__(self, other):
        return Vector2D(self.x * other, self.y * other)
    
    def __rmul__(self, other):
        return Vector2D(self.x * other, self.y * other)
    
    def __truediv__(self, other):
        return Vector2D(self.x / other, self.y / other)
    
    def __rtruediv__(self, other):
        return Vector2D(self.x / other, self.y / other)
    
    def dot(self, other):
        return self.x * other.x + self.y * other.y


def orientation(a: Vector2D[T], b: Vector2D[T], c: Vector2D[T]) -> T:
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)


def pairwise(iterable: Iterable[T]) -> Iterator[Tuple[T, T]]:
    """
    Implementación de la función pairwise de la librería itertools
    (no se encuentra disponible hasta la versión 3.10 de python).
    """
    iterator = iter(iterable)
    prev = next(iterator)
    for item in iterator:
        yield prev, item
        prev = item


def test(start: Vector2D[float], end: Vector2D[float], vertices: List[Vector2D[float]]):
    vertices.append(vertices[0])  # añadimos el primer vértice al final para poder iterar sobre todas las aristas
    res = 0
    for v0, v1 in pairwise(vertices):                                                    # iteramos sobre el conjunto de vértices de dos en dos
        diff_v = v1 - v0
        end_relative = end - v0                                                          # vector del punto final respecto de v0
        projection = diff_v * diff_v.dot(end_relative) / diff_v.dot(diff_v)              # proyección del vector end_relative sobre el vector diff_v
        end_mirror = v0 + (2 * projection - end_relative)                                # reflexión del punto de destino respecto del segmento
        if orientation(start, v1, end_mirror) < 0 < orientation(start, v0, end_mirror):  # comprobamos si el punto de intersección se encuentra dentro del segmento
            res += 1
    return res


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        start = Vector2D(*map(float, input().split()))
        end = Vector2D(*map(float, input().split()))
        vertices = [Vector2D(*map(float, input().split())) for _ in range(n)]
        print(test(start, end, vertices))


if __name__ == '__main__':
    main()
