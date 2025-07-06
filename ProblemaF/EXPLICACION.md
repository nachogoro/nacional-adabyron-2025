# Introducción a la solución
Podemos pensar el problema como un grafo bipartito donde hay vértices de dos
tipos: _chicos_ y _chicas_, y las aristas que les unen son relación de amistad.
Una arista siempre saldrá de un nodo de un tipo e incidirá en un nodo del tipo
contrario.

Si hay $f$ chicas y cada una tiene $f_f$ amigos, habrá $f \cdot f_f$ aristas
salientes de los nodos _chica_. De igual forma, si hay _m_ chicos y cada uno
tiene $m_f$ amigas, habrá $m \cdot m_f$ aristas salientes de los nodos
_chico_.

Como cada arista sale de un nodo de un tipo e incide en un nodo de otro, ambas
cantidades deben ser idénticas:

$$f \cdot f_f = m \cdot m_f$$

El enunciado nos da en cada caso de prueba $f$, $f_f$ y $m_f$, y nos pide $m$,
que es cuestión de despejar:

$$m = \frac{f \cdot f_f}{m_f}$$

Para que exista solución, $m$ ha de ser un número entero.


# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [F.cpp](src/F.cpp) | :x: |

