# Introducción a la solución

Si tenemos $n$ cajas, cada una de capacidad $c_i$, con la menor de ellas de una
capacidad $c_0$, podemos situar los números naturales en una cuadrícula de
$c_0$ columnas.

Tomamos como ejemplo aclaratorio los valores $c = {6, 9, 20}$, donde $c_0 = 6$:

```
 1  2  3  4  5  6
 7  8  9 10 11 12
13 14 15 16 17 18
19 20 21 22 23 24
25 26 27 28 29 30
31 32 33 34 35 36
37 38 39 40 41 42
43 44 45 46 47 48
49 50 51 52 53 54
...
```

La columna $i$ contiene los números congruentes con $i \mod c_0$: todos los
números en la primera columna dan resto 1 al hacer $\mod 6$, todos los números
en la segunda columna dan resto 2 al hacer $\mod 6$, etc. La sexta columna
incluye los números congruentes con 0 módulo 6.

Se observa que si podemos conseguir una cierta cantidad de nuggets
perteneciente a la columna $i$, podremos conseguir cualquier cantidad de
nuggets debajo del mismo en la misma columna simplemente comprando cajas
$c_0$.

En nuestro ejemplo, podemos comprar una caja de 6 nuggets, lo cual
automáticamente nos permite comprar cualquier cantidad de la sexta columna:

```
 1  2  3  4  5  X
 7  8  9 10 11  X
13 14 15 16 17  X
19 20 21 22 23  X
25 26 27 28 29  X
31 32 33 34 35  X
37 38 39 40 41  X
43 44 45 46 47  X
49 50 51 52 53  X
...
```

Podemos comprar también una caja de 9 nuggets:
```
 1  2  3  4  5  X
 7  8  X 10 11  X
13 14  X 16 17  X
19 20  X 22 23  X
25 26  X 28 29  X
31 32  X 34 35  X
37 38  X 40 41  X
43 44  X 46 47  X
49 50  X 52 53  X
...
```

Y una caja de 20 nuggets:
```
 1  2  3  4  5  X
 7  8  X 10 11  X
13 14  X 16 17  X
19  X  X 22 23  X
25  X  X 28 29  X
31  X  X 34 35  X
37  X  X 40 41  X
43  X  X 46 47  X
49  X  X 52 53  X
...
```

Ahora, desde cualquiera de las cantidades tachadas (obtenibles) podríamos
comprar no sólo una caja de 6 (que es lo que tacha el resto de la columna),
sino también una caja de 9 o una de 20.

Exploramos ahora por tanto de cada columna el primer número $n$ tachado, y
procedemos a tachar $n + 9$ y $n + 20$:
- El primer elemento tachado en la columna 6 es 6. Tachamos 6+9=15 (ya tachado
  previamente), 6+20=26 (ya tachado previamente) y sus inferiores.
- El primer elemento tachado en la columna 3 es 9. Tachamos 9+9=18 (ya tachado
  previamente), 9+20=29 y sus inferiores.
- El primer elemento tachado en la columna 2 es 20. Tachamos 20+9=29 (ya
  tachado previamente) y 20+20=40.
```
 1  2  3  4  5  X
 7  8  X 10 11  X
13 14  X 16 17  X
19  X  X 22 23  X
25  X  X 28  X  X
31  X  X 34  X  X
37  X  X  X  X  X
43  X  X  X  X  X
49  X  X  X  X  X
...
```

Podemos repetir el proceso ahora para todas las columnas donde hayamos
realizado un tachado aún no procesado:
- En la columna 5 hemos tachado 29. Tachamos ahora también 29+9=38 (ya tachado
  previamente) y 29+20=49.
- En la columna 4 hemos tachado 40. Tachamos ahora también 40+9=49 (ya tachado
  previamente) y 40+20=60 (ya tachado previamente).
```
 1  2  3  4  5  X
 7  8  X 10 11  X
13 14  X 16 17  X
19  X  X 22 23  X
25  X  X 28  X  X
31  X  X 34  X  X
37  X  X  X  X  X
43  X  X  X  X  X
 X  X  X  X  X  X
...
```

En el paso anterior hemos tachado 49 en la columna 1, así que tachamos a
continuación 49+9=58 (ya tachado previamente) y 49+20=69 (ya tachado
previamente).

Ya no quedan columnas por procesar. Vemos que ya ningún número posterior a 43
está sin tachar, por lo que la respuesta es 43.

## Cómo simular este algoritmo utilizando un vector
No podemos almacenar todos los números naturales en una matriz, puesto que hay
infinitos. Sin embargo, no necesitamos almacenar toda la matriz, sino llevar
una cuenta de cuál es el primer número tachado en cada columna. Para ello,
necesitamos un vector de $c_0$ elementos (uno por columna).

El vector comienza inicialmente con todos sus elementos inicializados a
infinito (puesto que no hay ningún elemento tachado en ninguna columna).

Almacenaremos en una cola qué números debemos tachar a continuación, y mientras
queden números alcanzables por tachar procederemos a comprobar si dicho número
se encuentra o no tachado. Si ya se encuentra tachado (porque hemos tachado un
número de la misma columna menor o igual a él), ignoramos el número y pasamos
al siguiente. Si no se encuentra aún tachado, lo tachamos y marcamos para
tachar en el futuro los alcanzables desde él.

## Cómo encontrar la respuesta usando grafos
Podemos automatizar este proceso utilizando un grafo. El grafo contendrá $c_0$
vértices, cada uno representando una de las columnas (residuos mod $c_0$).

Podemos ahora añadir una arista desde cada vértice $v_i$ con un peso $w$ igual
al tamaño de cada caja, que irá al residuo correspondiente a $i + w \mod c_0$.
Podemos ignorar las aristas de peso $c_0$:

Para nuestro ejemplo añadiríamos las siguientes aristas:
| Desde | Hasta | Peso |
| :---: | :---: | :--: |
| 0     | 3     |  9   |
| 0     | 2     |  20  |
| 1     | 4     |  9   |
| 1     | 3     |  20  |
| 2     | 5     |  9   |
| 2     | 4     |  20  |
| 3     | 0     |  9   |
| 3     | 5     |  20  |
| 4     | 1     |  9   |
| 4     | 0     |  20  |
| 5     | 2     |  9   |
| 5     | 1     |  20  |

El coste del camino más corto desde el vértice 0 (comenzamos con 0 nuggets)
hasta cada vértice $v_i$ es el primer número de la columna $v_i$ que podemos
tachar.

Podemos encontrar estos costes utilizando el algoritmo de Dijkstra.

Por lo tanto, el mayor de dichos costes $t_{max}$ es el número más alto que
representa el primer tachado de su columna. Por lo tanto, $t_{max} - c_0$ es el
número de la fila anterior, aún sin tachar: el número más alto no obtenible
comprando cajas enteras.

Si un nodo no es accesible desde el nodo 0, estamos en el caso INFINITO: para
cualquier número inalcanzable $n$ será posible encontrar un número mayor que
$n$ que tampoco sea alcanzable.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [C-vector.cpp](src/C-vector.cpp) | :white_check_mark: |
| [C-grafo.cpp](src/C-grafo.cpp) | :white_check_mark: |

