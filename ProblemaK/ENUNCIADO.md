# Problema K - Mondrian y el neoplasticismo

Al acabar la Primera Guerra Mundial, Piet Mondrian, un pintor de Países Bajos,
volvió a París y entró de lleno en la corriente del arte abstracto, que ya no
abandonaría nunca. Redujo su paleta de colores al blanco, negro y los colores
primarios e incluso abandonó definitivamente el uso de las líneas diagonales,
siguiendo los principios del neoplasticismo que había definido un año antes.

Su arte es fácilmente reconocible por ser líneas formando áreas rectángulares
que muchas veces pintaba de colores, como en "Composición en rojo, amarillo,
azul, blanco y negro" (1921) o "Composición en Rojo, Azul y Amarillo" (1930).

Con el tiempo fue evolucionando y llegó a crear obras donde las líneas eran de
colores primarios y los rectángulos blancos, como en sus dos "New York City" (I
y II) o incluso pintó líneas de colores alternos en "Broadway Boogie-Woogie"
(1942) con la cuadrícula de Manhattan simulando las luces de la ciudad e
incorporando el ritmo del boogie-woogie. Su obra "New York City I" quedó
inacabada. En 2022 se descubrió que llevaba varias décadas expuesta al revés, y
se decidió dejarla así para evitar dañarla.

El aspecto de rejilla de sus pinturas y la simplicidad de las formas y los
colores resulta muy tentador para la pequeña Mar Tista, que intenta imitarlas
en hojas de cuadros. Cuando las tiene, se pregunta cuántas regiones
rectangulares distintas (no necesariamente máximas) puede seleccionar que sean
del mismo color.

## Entrada
La entrada está formada por distintos casos de prueba.

Cada caso de prueba comienza con una línea con la cantidad de filas y de
columnas de la imagen (ambos números entre 1 y 1.000). A continuación aparecen
tantas líneas como filas tiene la imagen con un número por columna
representando el color de esa zona. Cada color es un número natural no mayor
que 10.000.

## Salida
Por cada caso de prueba se escribirá una única línea con la cantidad de
rectángulos (alineados con los ejes) que pueden escogerse en la imagen que
tengan un único color. Se considerarán rectángulos de cualquier tamaño, desde
1×1.

## Entrada de ejemplo
```
1 3
10 20 30
1 4
10 10 10 10
2 4
6 6 6 6
6 6 1 6
```

## Salida de ejemplo
```
3
10
19
```
