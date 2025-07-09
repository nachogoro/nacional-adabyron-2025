# Introducción a la solución

Sean $a_i$ y $m_i$ las notas del examen parcial $i$ de Ana y Mario, respectivamente. El problema consiste en demostrar que existe los pesos $p_1,...,p_N$ tales que:

$$\begin{pmatrix}
A \\ M
\end{pmatrix} =
\begin{pmatrix}
a_1 \\ m_1
\end{pmatrix} p_1
+ \dots +
\begin{pmatrix}
a_N \\ m_N
\end{pmatrix} p_N
$$

cumpliendo que $\sum p_i = 1$ y $\forall p_i \geq 0$

En otras palabras, lo que buscamos es saber si $(A,M)$ es **combinación convexa** de los puntos $(a_i,m_i)$.

Esto equivale a comprobar si el punto $(A,M)$ está dentro de la **envoltura convexa** (convex hull) de los puntos $(a_i,m_i)$.

Para calcular la envoltura convexa se puede utilizar el [algoritmo de Andrew](https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain), con $O(N \log N)$.

Para verificar si el punto $(A,M)$ está dentro del polígono convexo, se puede emplear **búsqueda binaria angular**: consiste en consiste en localizar en $O(\log N)$ el triángulo del polígono que podría contener el punto (dividiendo el polígono a la mitad en cada paso), y luego comprobar si el punto está dentro del triángulo. [En este vídeo](https://www.youtube.com/watch?v=aoxOPx2BIHE) se muestra visualmente cómo funciona la búsqueda.

Durante el algoritmo se utiliza en varios puntos el producto vectorial en 2D (que retorna un escalar), útil para determinar la orientación de un giro (antihorario o horario) según el signo del resultado.

En total, la complejidad temporal del algoritmo es $O(N \log N + Q \log N)$.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [J.cpp](src/J.cpp) | :white_check_mark: |

