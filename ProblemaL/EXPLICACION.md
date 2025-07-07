# Introducción a la solución

El problema se reduce a saber si, tras cada noche, el valor obtenido es
superior o no a la mediana de los valores vistos hasta ahora.

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

La solución óptima consiste en llevar un cálculo de la mediana que actualizar
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

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [L.cpp](src/L.cpp) | :white_check_mark: |

