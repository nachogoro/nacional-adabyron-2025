# Introducción a la solución

Para encontrar la secuencia de primos consecutivos menores que $10^7$ que suman
$n$, en primer lugar necesitamos calcular todos los primos menores que $10^7$.
Lo hacemos una única vez y lo reutilizaremos para todos los casos de prueba.

Podemos usar para eso la [criba de
Eratóstenes](https://es.wikipedia.org/wiki/Criba_de_Erat%C3%B3stenes).

Una vez disponimos de un vector que contiene todos los números primos de
interés en orden, podemos utilizar un algoritmo de ventana deslizante para
encontrar la secuencia más temprana cuyos elementos suman $n$.

Aprovechamos que el vector de primos es estrictamente creciente para establecer
una condición de parada temprana: puesto que la ventana ha de ser de mínimo dos
elementos, la ventana nunca podrá empezar más allá de $\frac{n}{2}$.


# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [B.cpp](src/B.cpp) | :x: |

