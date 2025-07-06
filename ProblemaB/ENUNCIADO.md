# Problema B - Números endogámicos

Carlos II, rey de España entre 1665 y 1700, no gozó de buena salud y, según
parece, tampoco de una mente brillante. Un nuncio papal de la época escribió de
él cuando tenía 20 años: "No puede enderezar su cuerpo sino cuando camina, a
menos de arrimarse a una pared, una mesa u otra cosa. Su cuerpo es tan débil
como su mente. [...] por lo común tiene un aspecto lento e indiferente, torpe e
indolente, pareciendo estupefacto. Se puede hacer con él lo que se desee, pues
carece de voluntad propia".

Una de las hipótesis más aceptadas de esos problemas de salud es el alto grado
de cosanguineidad que tenía. Y es que durante generaciones la dinastía de los
Habsburgo a la que pertenecía había sido muy propensa a la endogamia, es decir
a la unión en matrimonio de miembros de la misma familia. Sin ir más lejos, su
madre era sobrina de su padre y los padres de su abuelo materno eran primos.

De hecho, se ha calculado que el coeficiente de cosanguineidad de Carlos II era
de 25.4%, algo altísimo si tenemos en cuenta que el grado de un individuo cuyos
padres son hermanos es del 25%. Y altos coeficientes suelen provocar la
aparición de enfermedades hereditarias por la falta de variación genética (como
bien saben los criadores de perros que intentan mantener el índice por debajo
del 5%).

La endogamia, no obstante, no ha sido algo exclusivo de la dinastía de los
Habsburgo (los Reyes Católicos eran primos segundos). Ni siquiera se queda en
curiosidades de dinastías reales (Darwin se casó con su prima...) o de crianza
de perros, pues también en matemáticas podemos hablar de ese tipo de cruces.
Llamamos "números endogámicos" a aquellos que pueden expresarse como la suma de
dos o más números primos consecutivos. Por ejemplo son números endogámicos el 5
(= 2+3), el 15 (= 3+5+7) o el 20.000.010 (= 9.999.991+10.000.019).

## Entrada
La entrada está compuesta por un número indeterminado de casos de prueba, cada
uno en una línea. Cada línea contiene un número (hasta $10^9$) del que se
quiere conocer si es endogámico o no.

El último caso de prueba es seguido por una línea con un 0.

## Salida
Para cada caso de prueba se comprobará si el número puede expresarse como suma
de dos o más números primos consecutivos; aunque la definición no limita el
primo más alto, en nuestro caso admitiremos sumas de números primos no mayores
que $10^7$. En caso afirmativo se escribirá el número primo más pequeño y el
más grande de esa serie de primos. Si hay más de una forma de hacerlo, se
elegirá aquella que minimice el primer número de la serie. En caso de no ser un
número endogámico se escribirá NO.

## Entrada de ejemplo
```
5
6
15
39
20000010
0
```

## Salida de ejemplo
```
2 3
NO
3 7
3 13
NO
```
