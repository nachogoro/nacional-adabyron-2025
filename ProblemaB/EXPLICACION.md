# Introducción a la solución

Lo primero es obtener una lista de números primos desde el $1$ hasta $10^7$. Esto se puede lograr mediante la **criba de Eratóstenes**.

Luego, por cada número $n$ que queremos comprobar si es endogámico o no, realizamos lo siguiente:

1. Crearemos una **ventana deslizante** sobre la lista de números primos, que estará representada por dos índices: $l$ (el límite inferior) y $r$ (el límite superior). Esta ventana comienza conteniendo el primer número primo, es decir, el $2$.

2. Mantendremos la suma de los elementos de la ventana en una variable $sum$, que inicialmente valdrá $2$ (único elemento que contiene la ventana al principio).

3. Mientras no encontremos la lista de primos consecutivos que suman $n$, desplazaremos la ventana de la siguiente manera:
- Si $sum < n$ desplazamos **el límite superior hacia la derecha** ($r \leftarrow r+1$) para aumentar $sum$.
- En caso contrario (es decir, si $sum > n$, o si $sum = n$ pero la ventana tiene tamaño $< 2$), desplazamos el límite inferior hacia la derecha ($l \leftarrow l + 1$) para decrementar $sum$.

  Si en algún momento la ventana se sale de la lista de primos, entonces $n$ **no** será un número endogámico.

4. En el caso de que $sum = n$ entonces el número primo **más pequeño** y **más grande** de la serie serán los indicados por $l$ y $r$, respectivamente.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [B.cpp](src/B.cpp) | :white_check_mark: |

