# Introducción a la solución

Este problema se puede resolver usando **programación dinámica**.

Definimos $dp_{i,j}$ como el **número de  rectángulos de un solo color** que tienen como **esquina inferior derecha** la celda con fila $i$ y columna $j$.

Definimos $v_{i,j}$ como el **número de celdas consecutivas de mismo color que hay en la columna $j$**, comenzando desde la fila $i$ hacia arriba.

Por ejemplo, dada la siguiente matriz de colores:
$$\begin{pmatrix}
6 & 6 & 6 & 6 \\
6 & 6 & 1 & 6
\end{pmatrix}$$
la matriz $v$ correspondiente es:
$$\begin{pmatrix}
1 & 1 & 1 & 1 \\
2 & 2 & 1 & 2
\end{pmatrix}$$

Los posibles rectángulos que contribuyen a $dp_{i,j}$ son:
- **Los rectángulos verticales** (ancho $1$): hay exactamente $v_{i,j}$.
- **Los rectángulos con ancho $2$**: existen si las celdas $(i,j-1)$ y $(i,j)$ son del mismo color, y su cantidad es $\min(v_{i,j},v_{i,j-1})$. En caso contrario, hay $0$.
- **Los rectángulos con ancho $3$**: existen si las celdas $(i,j-2)$, $(i,j-1)$ y $(i,j)$ son del mismo color, y su cantidad es $\min_{k=j-2}^{j}(v_{i,k})$. En caso contrario, hay $0$.
- **En general, para cualquier ancho, $w$**, si las celdas $(i,j-w+1),\dots,(i,j)$ son del mismo color, hay $\min_{k=j-w+1}^{j}(v_{i,k})$ rectángulos. Si no, hay $0$.

Por tanto, podemos escribir:
$$dp_{i,j} = \sum_{w=1}^W{\min_{k=j-w+1}^j{v_{i,k}}}$$
siendo $W$ el **ancho máximo en el que al menos existe un rectángulo** que acaba en $(i,j)$.

La solución, es decir, el **número total de rectángulos** es:
$$\sum_{i=1}^F \sum_{j=1}^C dp_{i,j}$$

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [K.cpp](src/K.cpp) | :white_check_mark: |

