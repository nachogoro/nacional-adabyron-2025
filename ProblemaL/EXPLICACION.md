# Introducción a la solución

El problema se reduce a saber si, tras cada noche, el valor obtenido es
superior o no a la mediana de los valores vistos hasta ahora.

## Aproximaciones demasiado lentas

Normalmente, la mediana de una colección de números puede obtenerse ordenando
los números de menor a mayor y quedándose con el número a la mitad (que es el
que deja a su izquierda tantos números como deja a su derecha).

Esta aproximación es demasiado lenta para este problema, puesto que queremos
calcular la mediana tras la inserción de cada número. Si hay $n$ números,
habremos de hacer $n$ ordenaciones, obteniendo un coste asintótico en el caso
peor de $O(n^{2} \log n)$.

Podríamos mejorar el coste hasta $O(n^2)$ si en lugar de calcular la mediana
tras cada inserción, ordenando los números, simplemente hacemos un recorrido de
todos los números vistos hasta ahora y vemos cuántos son menores que el número
que representa la noche actual, para ver si son más de la mitad o no. Esta
opción también es demasiado lenta.

## Opción 1: utilizar dos _heaps_

Una solución óptima consiste en llevar un cálculo de la mediana que actualizar
rápidamente con cada inserción sin tener que reordenar. Para eso utilizamos dos
*heaps*, uno de máximos y otro de mínimos. El montículo de máximos contiene la
mitad inferior de los números, y el montículo de mínimos contiene la mitad
superior de los números. Incluir un elemento requerirá simplemente una
inserción en uno de los dos montículos, y potencialmente un traspaso de algún
elemento de un montículo a otro para mantenerlos del mismo tamaño. El coste de
esta solución es por tanto $O(n \log n)$.

Puesto que nos interesa saber si hemos llegado más tarde que la mitad de los
días vistos hasta ahora (redondeando hacia arriba si el número de días es
impar), podemos almacenar en el montículo de máximos siempre un elemento más
que en el de mínimos en caso de que haya un número impar de días. De esta
manera, el criterio es siempre el mismo independientemente de si hay un número
par o impar de días ya vistos: si hoy hemos llegado más tarde que la cima del
montículo de máximos, habremos llegado más tarde que la mitad de los días
(redondeando hacia arriba).

## Opción 2: utilizar un árbol de Fenwick

Un _árbol de Fenwick_ (o árbol binario indexado, BIT en inglés) es una
estructura de datos que permite calcular en tiempo logarítmico el valor de la
suma de los elementos de un array en un determinado intérvalo, además de
actualizar en $O(\log n)$ el valor de uno de sus elementos. A este problema se
le conoce comunmente como _problema de suma de rango dinámica_ (Range Sum
Query, RSQ en inglés). Podéis encontrar más detalles sobre esta estructura de
datos y una implementación en
[cp-algorithms](https://cp-algorithms.com/data_structures/fenwick.html). En
particular, el árbol de Fenwick permite calcular la suma de los elementos del
array que se encuentran en una posición menor o igual a un determinado índice.

Supongamos que tenemos un array $a$, donde $a[i]$ denota la cantidad de noches
anteriores a un día $d$ determinado en la que se ha vuelto a la hora $a[i]$.
Por ejemplo, si nos encontramos en el cuarto día del primer caso de prueba del
ejemplo (con horas de llegada ``3 8 6 4``), este array tendría el valor
$$a = [0, 0, 0, 1, 1, 0, 0, 0, 1, 0, ...]$$
(empezando a contar por el cero). Si construimos un árbol de Fenwick sobre el
array $a$, podremos determinar de forma eficiente si Susana ha llegado a casa
más tarde que al menos la mitad de noches anteriores:

1. Para obtener el número de noches anteriores en las que Susana ha llegado a
   casa más temprano que a la hora $h_d$, podemos realizar una consulta de
rango en el intérvalo $[0, h_d-1]$ con el árbol de Fenwick.
2. Si este valor obtenido es mayor o igual a la mitad del número de noches
   anteriores $d$, incrementamos un contador con la respuesta.
3. Finalmente, incrementamos en 1 el elemento en la posición $h_d$ del array
   del árbol de Fenwick para repetir el mismo proceso con la siguiente noche.

No obstante, los valores de $h$ pueden llegar a ser muy grandes (hasta $10^9$),
de manera que el array $a$ con el que trabajamos podría llegar a tener
demasiadas entradas, lo cual supondría un problema de rendimiento y de costes
en términos de memoria. Es por eso que es necesario aplicar antes de nada una
técnica de programación llamada _compresión de coordenadas_, mediante la cual
cada valor $h[i]$ del array de entrada se mapea al número de valores diferentes
menores que $h[i]$. Esto hace que los elementos del array de entrada $h$ tengan
valores mucho más pequeños (entre $1$ y $n$), preservando además el orden
relativo de sus elementos. Por ejemplo, el resultado de aplicar compresión de
coordenadas sobre el array de entrada $h = [15, 12, 5, 8, 10]$ del segundo caso
de prueba del ejemplo sería el array $[5, 4, 1, 2, 3]$.

Finalmente, podemos resolver el problema con el nuevo array $h$ utilizando un
árbol de Fenwick mucho más pequeño y eficiente (de tamaño $O(n)$, donde $n$ es
el tamaño del array de entrada) con un coste asintótico de $O(n \log n)$.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [L_heaps.cpp](src/L_heaps.cpp) | :white_check_mark: |
| [L_fenwick.cpp](src/L_fenwick.cpp) | :white_check_mark: |

