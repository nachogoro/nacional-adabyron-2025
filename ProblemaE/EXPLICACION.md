# Introducción a la solución

En resumen, el problema se puede expresar como:
> Disponiendo de un array $v$ de $n$ elementos enteros positivos y un valor
> $k$, hallar el subarray de al menos $k$ elementos consecutivos tal que la
> media de dicho subarray sea máxima.

Probar todos los subarrays posibles tendría un coste prohibitivo ($O(n^{2})$).
En su lugar, podemos utilizar una estrategia de búsqueda binaria, en la que
comprobamos si existe algún subarray de al menos $k$ elementos con un media
igual o superior a $m$.

En primer lugar establecemos la media teórica más alta y más baja que se puede
obtener en este array sin restricciones de longitud (como si $k=1$). En ese
caso, la media mínima corresponderá a un subarray de un único elemento (el
mínimo del array $e_{min}$), y la media máxima corresponderá también a un
subarray de un único elemento (el elemento máximo $e_{max}$).

El rango de medias posibles es por tanto $[e_{min}, e_{max}]$. Se nos pide una
precisión de $\epsilon=10^{-4}$, por lo que el espacio de búsqueda estará
compuesto de $\frac{e_{max} - e_{min}}{\epsilon}$ medias posible, y
necesitaremos $\log2{\frac{e_{max} - e_{min}}{\epsilon}}$ consultas. Buscaremos
la media más grande de todas las posibles que sea posible de obtener.

Necesitamos ahora una forma de comprobar, dada una media $m$, si es posible
obtener una media igual o superior a $m$ usando al menos $k$ elementos
consecutivos de $v$.

La media de la secuencia de elementos entre las posiciones $i$ y $j$ del array
es $avg_{i,j} = \frac{\sum_{k=i}^{j} v_k}{j - i + 1}$.

Estamos por tanto buscando un subarray de longitud $l \gtq k$ tal que la suma
de sus elementos $s$ verifique $s \geq m \cdot l$.

Otra form de verlo es que buscamos que $avg_{i,j} \geq m$, o lo que es lo
mismo: $avg_{i,j} - m \geq 0$:

$$
\frac{\sum_{k=i}^{j} v_k}{j - i + 1} - m \geq 0 \rightarrow
\frac{\sum_{k=i}^{j}{v_k} - m \cdot (j - i + 1)}{j - i + 1} \geq 0 \rightarrow
\frac{\sum_{k=i}^{j}{v_k - m}}{j - i + 1} \geq 0 \rightarrow
\frac{\sum_{k=i}^{j}{v_k - m}} \geq 0
$$

Es decir, la pregunta es equivalente a plantear un array $v \prime$ donde
$v \prime_{i} = v_i - m$ y comprobar si existe alguna secuencia de longitud
mayor o igual que $k$ tal que su suma sea mayor o igual que 0.

Dado un array $v \prime$, para saber si algún subarray tiene una suma mayor que
$s \prime$ utilizamos un vector de suma prefija $p$, en el que cada elemento $i$
representa la suma de los primos $i$ elementos de $v \prime$. Avanzaremos por
el vector $p$, llevando la cuenta por cada índice $i$ de cuál ha sido el valor
$q$ más pequeño encontrado hasta $i - k + 1$, y la diferencia entre $p_i$ y $q$
es la máxima suma que obtenerse en $v \prime$ para un subarray de longitud al
menos $k$ que acabe en $i$.

Si al menos una de las sumas de los subarrays es mayor o igual a 0, será
posible obtener una media mayor o igual a $m$.


# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [E.cpp](src/E.cpp) | :white_check_mark: |

