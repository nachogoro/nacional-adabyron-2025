# Problema L - Noches locas

A Susana le encanta salir por la noche con sus amigas. Disfruta tanto de esas
salidas que, siempre que puede, intenta llegar a casa un poco más tarde que la
noche anterior. Pero no siempre lo consigue: hay días en que no sale, otros en
los que la noche no da para mucho y regresa pronto, y algunos en los que
simplemente no mejora su marca.

Durante varias semanas, Susana ha ido apuntando a qué hora vuelve a casa,
siempre después de medianoche. Al repasar los datos, se ha llevado una pequeña
decepción: en muchos días no ha logrado superarse. Así que ha decidido cambiar
de estrategia.

En lugar de intentar batir su propio récord a diario, Susana se ha propuesto
una meta más modesta: contar cuántos días ha conseguido llegar a casa más tarde
que al menos la mitad de los días anteriores.  El primer día siempre cuenta,
claro, ya que no hay días anteriores con los que compararse.

Después de intentar hacerlo a mano, Susana se ha dado cuenta de que revisar
cada día contra todos los anteriores no es tan divertido como salir de fiesta,
así que ha decidido pedirte ayuda. ¿Puedes ayudarla?

## Entrada
La entrada comienza con el número de casos de prueba que vienen a continuación.
Cada caso consta de dos líneas. En la primera se indica el número $N$ ($0 \lt N
\leq 500.000$) de noches que Susana ha salido. En la segunda se muestra el
tiempo que ha estado fuera de casa cada noche después de medianoche, valores
enteros entre $0$ y $10^9$.

## Salida
Para cada caso de prueba se escribirá en una línea el número de noches en que
Susana ha llegado a casa más tarde que al menos la mitad de las noches
anteriores. Si el número de noches anteriores al día $d$ es impar, se
contabilizará el día $d$ si el número de noches anteriores en que llegó antes
que la hora de llegada del día $d$ es estrictamente mayor que el número de
noches en que llegó después o a la misma hora.

## Entrada de ejemplo
```
3
4
3 8 6 4
2
7 7
5
15 12 5 8 10
```

## Salida de ejemplo
```
3
1
2
```
