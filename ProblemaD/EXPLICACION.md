# Introducción a la solución

Si las consultas no afectasen a las respuestas posteriores, bastaría con hacer
una búsqueda binaria para encontrar el valor más alto para el que se devuelve
"SI", estableciendo el instante 1 como un instante en el que la abuela
recordaba originalmente, y $T_{est}$ como un instante a partir del cual ya no.

Sin embargo, puesto que cada "SI" obtenido duplica dicho valor buscado,
realizamos una modificación: aunque realizaremos la búsqueda binaria sobre el
rango inicial $[0, T_{est}]$, haremos las consultas no sobre el punto medio $m$
del rango relevante, sino sobre $m \cdot 2^{aciertos}$.

De esta manera conseguimos ir reduciendo el espacio de búsqueda a la vez que
tenemos en cuenta la duplicación del último instante en el que la abuela
responderá que ya no recuerda la foto.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [D.cpp](src/D.cpp) | :white_check_mark: |

