# Problema H - Trileros
En la plaza central de la ciudad, todas las tardes se forma un corro alrededor
de Eladio, el trilero más rápido en esta orilla del Misisipi. Sobre su mesa,
una caja de frutas dada la vuelta, alinea con precisión una serie de cubiletes
idénticos, siempre impecables. A simple vista, su juego parece simple: esconde
una bolita bajo uno de los cubiletes, realiza una serie de intercambios entre
pares de cubiletes, moviendo sus manos con una velocidad hipnótica, y luego
reta a algún espectador a adivinar dónde ha terminado la bolita.

Pero el espectáculo no acaba ahí. Las apuestas vuelan. Algunos incautos colocan
billetes sobre la mesa convencidos de haber seguido el rastro de la bolita;
otros apuestan a ciegas confiando en la suerte. Sin embargo, la mayoría pierde.
Eladio no hace trampas, o eso dice, pero su rapidez y precisión deslumbran
tanto como desorientan. Solo los más atentos pueden seguir sus movimientos.

Tú formas parte de un grupo que ha decidido tomarse la revancha... pero no
apostando, sino investigando. Has conseguido las grabaciones completas de una
de sus sesiones, donde se documentan exactamente todos los intercambios que
hizo, en orden, entre pares de cubiletes. Para entender mejor su técnica, te
propones responder una pregunta crucial: dado un cubilete como posible posición
final de la bolita, ¿qué posición inicial permitiría que terminara allí después
de realizar todos los intercambios?

## Entrada
La primera línea contiene un único entero que indica el número de casos de
prueba que vendrán a continuación.

Para cada caso de prueba, en la primera línea se indican dos números separados
por un espacio: el número $N$ de cubiletes ($2 \leq N \leq 1.000$) y el número
$M$ de intercambios que se hacen ($0 \leq M \leq 1.000$).  A continuación se
dan $M$ líneas, cada una con dos números distintos entre 1 y $N$ separados por
un espacio, que representan dos cubiletes que se intercambian.

## Salida
Para cada caso de prueba se escribirá una línea con $N$ números separados por
espacios, cada uno entre 1 y $N$. El número $c_i$ en la posición $i$ indica que
si la bola empezara en el cubilete $c_i$ y se hicieran todos los intercambios
dados en orden, al final acabaría en el cubilete $i$.

## Entrada de ejemplo
```
2
2 1
2 1
3 3
2 1
1 3
1 2
```

## Salida de ejemplo
```
2 1
1 3 2
```
