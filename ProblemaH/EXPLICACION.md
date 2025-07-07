# Introducción a la solución

Podemos simular el juego utilizando un vector $v$ en el que el elemento $i$
indica el contenido del cubilete $i$.

Para poder detectar dónde empezó cada bolita una vez que ha acabado el juego,
podemos comenzar el juego "marcando" cada bolita con su posición inicial:
```
v = [ 1, 2, 3, 4 ]
```

A continuación, podemos realizar los intercambios indicados (al intercambiar
las posiciones $i$ y $j$ procedemos a hacer _swap_ de $v[i]$ y $v[j]$).

Al acabar la simulación del juego, el contenido de $v[i]$ será la posición
inicial de la bolita que ha acabado en el cubilete $i$.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [H.cpp](src/H.cpp) | :white_check_mark: |

