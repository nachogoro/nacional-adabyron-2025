# Introducción a la solución
Dados dos mazos (de tamaños $n_1$ y $n_2$, respectivamente), se pide hallar la **dispersión mínima** al combinarlos, manteniendo el orden relativo de las cartas en cada mazo. Es decir, buscamos entre todas las **intercalaciones** posibles de ambas **secuencias** aquella que minimice la dispersión.

La **dispersión total de un mazo** se define como:

$$D = \sum d_x$$

donde $d_x$ es la **dispersión de la familia** $x$, definida como:

$$d_x = l_x-f_x$$

siendo $f_x$ y $l_x$ la **posición de la primera y última carta** de la familia $x$, respectivamente. 

Por tanto, la fórmula completa es:

$$D = \sum{(l_x-f_x)}$$

Esto nos permite observar que **no es necesario** calcular la dispersión de cada familia por separado. Se puede ir sumando los $l_x$ y restando los $f_x$ **a medida que se construye el mazo combinado**.

---

Este problema se puede resolver usando **programación dinámica**. Definimos $dp_{i,j}$ como la dispersión _"parcial"_ mínima del mazo final al haber combinado las $i$ primeras cartas del 1º mazo y $j$ primeras cartas del 2º mazo. _"Parcial"_ se refiere a que en la dispersión faltarán algunos $l_x$ y $f_x$ porque no se han agregado todas las cartas.

Para cada $(i,j)$ tenemos dos opciones:
- Añadir una carta del 1º mazo (si $i<n_1$).
- Añadir una carta del 2º mazo (si $j<n_2$).

Para cada carta añadida puede pasar que:
- **Es la primera aparición** de su familia → restamos su posición ($f_x$) a la dispersión parcial.
- **Es la última aparición** de su familia → sumamos su posición ($l_x$) a la dispersión parcial.

Cada $dp_{i,j}$ se calcula a partir de $dp_{i-1,j}$ o $dp_{i,j-1}$ (si existen), por lo que es necesario quedarse con el **valor mínimo** de entre ambas opciones.

Para saber rápidamente si una carta es la 1º o la última de su familia se puede **precalcular** la posición de la primera y última carta de cada familia en cada mazo.

Al final, $dp_{n_1,n_2}$ contendrá la dispersión mínima del mazo final.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [G.cpp](src/G.cpp) | :white_check_mark: |

