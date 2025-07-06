# Problema C - Cajas de nuggets

La receta de los nuggets de pollo fue inventada por un profesor de tecnología
de los alimentos en la década de 1950. Como no la patentó, la cadena McDonald's
la adaptó en 1979 para crear sus McNuggets, un alimento muy poco saludable, con
mucha grasa, que tiene menos de 50% de carne de pollo. El resto está formado
por piel, hueso triturado, cartílago, nervios, venas y así hasta 38
ingredientes poco apetecibles. Aun así, los McNuggets son uno de los productos
estrella de esa cadena de restaurantes.

El fin de semana pasado, Noé Sana celebró su cumpleaños en un McDonald's. Se
juntaron 14 amigas y querían pedir 2 McNuggets para cada una. El problema es
que los vendían únicamente en cajas de 6, 9 y 20 piezas y no fueron capaces de
encontrar una combinación con la que comprar exactamente los 28 que
necesitaban.

## Entrada
Cada caso de prueba comienza con un número $2 \leq n \leq 20$ indicando el
número de tamaños de cajas de nuggets que tienen en venta en una determinada
cadena de restaurantes. En la línea siguiente aparecen $n$ números $a_1$,
$a_2$, ..., $a_n$ separados por espacios, donde $a_i$ es el número de piezas de
las cajas de tipo $i$. Se garantiza que $a_i \lt a_{i+1}$, $2 \leq a_1 \leq
10.000$ y $a_n \leq 5.000.000$.

La entrada termina con un 0 que no debe procesarse.

## Salida
Por cada caso de prueba el programa escribirá el mayor número de nuggets que no
se puede conseguir comprando cajas completas de las disponibles para la venta.
Si no hay respuesta posible porque siempre se puede encontrar un número mayor
que no se puede comprar se escribirá INFINITO.

Se garantiza que, de existir, el número será menor que $50 \cdot 10^9$.

## Entrada de ejemplo
```
3
6 9 20
4
271 277 281 283
2
4 12
0
```

## Salida de ejemplo
```
43
13022
INFINITO
```
