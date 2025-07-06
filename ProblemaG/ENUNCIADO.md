# Problema G - Familias de 7 países

En 1965 veía la luz la baraja de cartas "Familias de 7 países" vendida por la
marca Heraclio Fournier. Se usaba para el *juego de las siete familias*,
inventado en Inglaterra en 1851.

La baraja está formada por 42 cartas, cada una con un integrante de una de
siete familias (árabe, bantú, china, esquimal, india, mexicana y tirolesa).
Cada familia está formada por los naipes del padre, madre, hijo, hija, abuelo y
abuela.  Las ilustraciones, de José Luis López Fernández, creaban una escena
completa para cada familia al hacer que los fondos encajaran.

Cuando se cogen unas cuantas cartas de la baraja y se mezclan, los integrantes
de las distintas familias quedan distribuidos y separados. Llamamos
*dispersión* de una familia a la distancia, en cartas, entre sus integrantes
más distantes. Si en un mazo de cartas solo hay un integrante de una familia,
se considera que la dispersión de esa familia es 0. Si hay solo dos
integrantes, uno junto al otro, la dispersión es 1. La *dispersión de un mazo*
es la suma de la dispersión de cada familia que contiene.

En un determinado momento tenemos dos mazos distintos con unas cuantas cartas
de la baraja y queremos entrelazarlos de tal manera que el orden relativo de
las cartas de cada mazo no cambie.  Es decir, vamos a hacer una mezcla a la
americana pero imprecisa, porque entre cada par de cartas adyacentes de un mazo
se pueden meter un número arbitrario de cartas consecutivas del mazo opuesto (y
viceversa). ¿Cuál es la mínima dispersión que podemos conseguir en el mazo
final?

## Entrada
Cada caso de prueba está compuesto por dos mazos de cartas. Un mazo se
especifica con un primer número $1 \leq n \leq 3.000$ indicando la cantidad de
cartas del mazo. En la línea siguiente aparecen $n$ números (entre 1 y 3.000)
indicando la familia a la que pertenece cada carta, en el orden en el que
aparecen en el mazo.

## Salida
Por cada caso de prueba se escribirá la mínima dispersión posible que se puede
conseguir en un mazo obtenido por la mezcla de los dos iniciales, sabiendo que
el orden relativo de las cartas de cada mazo se debe mantener.

## Entrada de ejemplo
```
2
1 2
3
3 4 4
3
1 8 1
2
8 1
```

## Salida de ejemplo
```
1
5
```
