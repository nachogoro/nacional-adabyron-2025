# Introducción a la solución

Para encontrar la secuencia de primos consecutivos menores que $10^7$ que suman
$n$, en primer lugar necesitamos calcular todos los primos menores que $10^7$.
Lo hacemos una única vez y lo reutilizaremos para todos los casos de prueba.

Podemos usar para eso la [criba de
Eratóstenes](https://es.wikipedia.org/wiki/Criba_de_Erat%C3%B3stenes),
obteniendo el array $p$ de primos.

Una vez disponimos de un vector que contiene todos los números primos de
interés en orden, podemos utilizar un algoritmo de ventana deslizante para
encontrar la secuencia más temprana cuyos elementos suman $n$.

Una ventana deslizante estará representada por dos índices: $left$ (el límite
inferior) y $right$ (el límite superior). Comenzará conteniendo los dos
primeros números primos, y llevando una cuenta de su suma $sum$.

Mientras los primos de nuestra ventana no sumen $n$, desplazaremos la ventana
de la siguiente manera:
1. Si $sum \lt n$ desplazamos **el límite superior hacia la derecha** ($right
   \leftarrow right+1$), actualizando la suma de la ventana para incluir al
nuevo primo: $suma = suma + p[right]$
2. Si $sum \gt n$ desplazamos **el límite inferior hacia la derecha** ($left
   \leftarrow left+1$), actualizando la suma de la ventana para excluir al
primo que acaba de abandonarla: $suma = suma - p[left-1]$
3. Si $sum = n$, nuestra solución son los primos apuntados por $left$ y $right$.
4. Si en algún momento alguno de nuestros índices excede el tamaño de $p$, el
   número no es endogámico.

Aprovechamos que el vector de primos es estrictamente creciente para establecer
una condición de parada temprana: puesto que la ventana ha de ser de mínimo dos
elementos, la ventana nunca podrá empezar más allá de $\frac{n}{2}$.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [B.cpp](src/B.cpp) | :white_check_mark: |

