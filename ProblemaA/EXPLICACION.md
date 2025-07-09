# Introducción a la solución

En las primeras C líneas de la entrada se nos proporciona un grafo no dirigido y ponderado, $G_1$, que representa las ciudades y el tiempo de viaje entre ellas. Dadas dos ciudades $A$ y $B$ y el tiempo directo entre ellas $t_{A,B}$,puede existir otra ciudad intermedia $C$ tal que el trayecto sea más corto:
$$t_{A,C}+t_{B,C} < t_{A,B}$$
Por tanto, es necesario modificar el grafo $G_1$ para que contenga los tiempos mínimos de viaje entre cada par de ciudades, permitiendo trayectos que pasen por otras poblaciones. esto se puede lograr usando el **algoritmo de Floyd-Warshall**.

En las siguientes $P$ líneas aparecen los mítines, ordenados por ciudad. El número total de mitines será $N = \sum N_i$. Podemos almacenar los mitines en una lista $m$ de $N$ elementos.

Una forma de modelar el problema es con un grafo no dirigido y ponderado, $G_2$, donde los nodos representan los mítines y las aristas el tiempo de viaje entre ellos.

Para construir $G_2$, consideramos para cada pareja de mitines: $(m_i, m_j)$:
- Si ambos están en la misma ciudad, el tiempo es $0$.
- Si están en ciudades distintas, el tiempo es $t_{c_i,c_j}$, siendo $c_i$ y $c_j$ las ciudades de los mitines. Este tiempo lo obtenemos del grafo $G_1$ ya procesado.

A continuación, a partir de $G_2$, creamos otro grafo dirigido, acíclico y no ponderado, $G_3$. Este grafo contendrá una arista desde $m_i$ a $m_j$ si después de haber ido a $m_i$ es posible asistir a $m_j$. Esto ocurre si se cumple la siguiente condición:
$$h_i+t_{m_i,m_j}+2 \leq h_j$$
donde $h_i$ y $h_j$ las horas a las que comienzan los mitines, y $t_{m_i,m_j}$ el tiempo de viaje entre los mitines (se obtiene de $G_2$). Sumamos $2$ horas porque el mitin anterior dura $1$ hora y hay que llegar con $1$ hora de antelación al mitin posterior.

Después de obtener el _DAG_ $G_3$,el objetivo es determinar el mínimo numero de caminos necesarios para visitar todos los nodos. En este contexto, los caminos representan periodistas, y los nodos representan los mítines. Este problema se conoce como **_Minimum Path Cover in DAG_** y se puede resolver mediante una reducción a **_matching bipartito_**.

Para ello en el que es necesario construir otro grafo auxiliar, como se describe [aquí](https://en.wikipedia.org/wiki/Maximum_flow_problem#Minimum_path_cover_in_directed_acyclic_graph). Existen diversas formas de resolver _matching bipartito_, como por ejemplo [reduciéndolo a un problema de flujo máximo](https://www.youtube.com/watch?v=eBwsdXgRos4) y usando el **algoritmo Dinic**, como se explica en [este vídeo](https://en.wikipedia.org/wiki/Dinic%27s_algorithm).

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [A.cpp](src/A.cpp) | :white_check_mark: |

