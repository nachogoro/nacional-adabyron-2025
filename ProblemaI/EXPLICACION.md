# Introducción a la solución

Para cada segmento $\langle V_i, V_{i+1} \rangle$ del polígono, queremos determinar si existe un punto $C_i$ del segmento que esté conectado
con los puntos de origen y destino $A$ y $B$ formando el mismo ángulo con el segmento $\langle V_i, V_{i+1} \rangle$.

Este punto $C_i$ se puede encontrar usando la reflexión del punto de destino $B$ sobre la recta que une $V_i$ con $V_{i+1}$.
Una vez obtenido el punto de reflexión $B'$, el punto $C_i$ es la intersección del segmeno $AB'$ con la recta $V_iV_{i+1}$.

Finalmente, para comprobar si el punto $C_i$ se encuentra dentro del segmento $\langle V_i, V_{i+1} \rangle$,
será suficiente con ver que se cumplen las dos condiciones siguientes:
1. El ángulo $\angle A V_i B'$ es mayor que cero (i.e. los tres puntos se encuentran en sentido antihorario);
2. El ángulo $\angle A V_{i+1} B'$ es menor que cero (i.e. los tres puntos se encuentran en sentido horario).

Para obtener el punto $B'$, podemos aplicar la siguiente fórmula:
$$B' = V_i + 2 \vec{p} - \overrightarrow{V_iB},$$
donde $\vec{p}$ es la proyección del vector $\overrightarrow{V_iB}$ sobre el vector director $\vec{d} := \overrightarrow{V_iV_{i+1}}$:
$$\vec{p} = \vec{d} \cdot \frac{\langle \overrightarrow{V_iB}, \vec{d} \rangle}{\| \vec{d} \|^2},$$
donde $\langle \vec{u}, \vec{v} \rangle$ denota la operación producto escalar.
