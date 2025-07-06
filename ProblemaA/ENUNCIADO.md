# Problema A - ¡Otras elecciones!

El domingo 28 de mayo de 2023 se celebraron elecciones autonómicas en España.
Después de dos semanas de campaña electoral con todos los medios de
comunicación siguiendo a los candidatos a alcalde y presidente de pueblos y
Comunidades Autónomas los periodistas y analistas políticos pensaban que
seguirían unos meses de descanso hasta la siguiente cita electoral.

Nada más lejos de la realidad. A la vista de los resultados en las urnas, el
presidente del gobierno compareció al día siguiente, lunes 29 de mayo, ante
todos los medios de comunicación. Pocos sabían en ese momento que se estaba
fraguando un "_meme_" que habrían de recordar durante muchos años. En el
estudio de radio, Àngels Barceló, una conocida periodista española, escuchaba
atenta la comparecencia que se estaba emitiendo en directo en su programa tanto
por radio como por _streaming_ de vídeo. Fue entonces cuando el presidente
convocó elecciones generales anticipadas para el 23 de julio, en plenas
vacaciones de verano de Àngels. El gesto de exasperación que esta hizo al ver
que se iba al garete su merecido descanso estival fue épico. El meme había
nacido.

Su enojo inicial se vió incrementado pensando en que no solo se quedaba ella
sin vacaciones sino todos los periodistas de su equipo que se iban a pasar el
mes de julio recorriendo España detrás de los candidatos para cubrir todos y
cada uno de sus mítines. Para intentar minimizar las quejas ha cogido la lista
de todos los actos públicos que habrá y el mapa de España que le permite
estimar el tiempo que se tarda en ir de uno a otro. Ahora quiere calcular el
mínimo número de periodistas que necesita para que entre ellos se puedan
repartir los actos de forma que 1) cada acto tenga un periodista asignado que
cubra el evento entero, cuya duración se estima en una hora, y 2) los
periodistas tengan tiempo suficiente para ir desde un acto al siguiente
llegando con una hora de antelación.

## Entrada
El programa deberá procesar múltiples casos de prueba cada uno ocupando varias
líneas.

Un caso de prueba comienza con dos números, $P$ y $C$, indicando,
respectivamente, el número de poblaciones en las que se van a realizar mítines
políticos (entre 1 y 200) y el número de conexiones por carretera entre ellas,
respectivamente.

A continuación aparecen $C$ líneas, describiendo cada una de las conexiones
entre las poblaciones.  Una conexión se define con dos números distintos entre
1 y $P$ que indican las poblaciones que une esa conexión (en ambos sentidos),
junto con un tercer número, entre 1 y 10.000, con el número de horas necesarias
para recorrerla. Nunca habrá más de una conexión entre las mismas dos
poblaciones.

El caso termina con $P$ líneas más, una por cada una de las poblaciones, en
orden. Cada línea comienza con un número $N_{i}$ con la cantidad de mítines que
se dan en la población $i$, y le siguen $N_{i}$ números enteros distintos, de
menor a mayor, con la hora a la que comienza cada uno de los mítines, medidas
desde el inicio de la campaña electoral. Se garantiza que todas las ciudades
tienen al menos un mitin, que en total no habrá más de 200 y que la campaña
dura como mucho $5 \cdot 10^6$ horas.

## Salida
Por cada caso de prueba se escribirá el mínimo número de periodistas que se
necesitan para cubrir todos los eventos. Debe existir una distribución que
asigne a cada periodista una serie de eventos de forma que se garantice que el
periodista tiene tiempo suficiente para llegar desde un evento al siguiente con
al menos una hora de margen. Si en una ciudad hay dos mítines y se asignan
ambos al mismo periodista, aunque no tenga que desplazarse necesita también una
hora desde que termina uno hasta que empieza el siguiente para descansar y
cargar las baterías de sus dispositivos electrónicos.

Se puede suponer que el plan se preparará con suficiente antelación como para
que cada periodista pueda llegar a su primer evento con margen suficiente.
Todos los eventos duran una hora y los periodistas se quedan siempre hasta el
final.

## Entrada de ejemplo
```
3 3
1 2 2
3 1 5
2 3 1
2 0 13
1 4
1 8
4 4
3 1 2
1 4 3
1 2 2
4 2 6
1 5
1 6
2 1 12
2 10 14
```

## Salida de ejemplo
```
1
2
```
