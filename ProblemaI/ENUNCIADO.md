# Problema I - Billar irregular

Una variante popular del juego del billar es el "Billar Francés" o "Carambola".
Esta variante del juego es técnicamente muy compleja, ya que se juega con tres
bolas en una mesa sin troneras, y el objetivo es marcar puntos realizando
diversos trucos.

Nadine tenía bastantes ganas de probar este nuevo juego, pero la mesa que se ha
comprado por internet... Bueno, muy rectangular no es. De hecho, es un polígono
convexo de $n$ lados.

Como todavía está aprendiendo el juego, vamos a empezar con algo sencillo.
Nadine tiene en el interior de la mesa una bola de billar, y quiere llevarla a
un punto distinto. ¿De cuántas formas puede golpear la bola para que rebote
exactamente una vez en el borde de la mesa y llegue a la posición deseada?

Cuando una bola golpea el borde de la mesa, el ángulo entre su dirección de
entrada y la normal del borde es igual al de la normal y la dirección de
salida. Se asume que el tamaño de la bola es despreciable.

## Entrada
La entrada comienza con un entero positivo $T$, que indica el número de casos
de prueba.

Cada caso de prueba comienza con una línea con un entero positivo $n$ ($3 \lt n
\lt 300$), con el número de vértices de la mesa.

Las siguientes $n+2$ líneas contienen cada una dos números reales entre –100 y
100 con las coordenadas de un punto. Los primeros dos puntos son la posición
inicial y final de la bola, respectivamente. Los siguientes n representan los
vértices de la mesa de billar, en el sentido contrario de las agujas del reloj.

Los polígonos de la entrada son simples y convexos. Los puntos de origen y
destino están en el interior de dicho polígono. Ninguna trayectoria
origen–destino cumpliendo las condiciones del enunciado pasará a menos de
$10^{−4}$ de distancia de un vértice.

## Salida
Para cada caso de prueba se escribirá el número de trayectorias tales que la
bola comience y termine en las posiciones dadas, y se mueva en línea recta
excepto por un rebote que hace en la frontera del polígono.

El rebote es perfectamente inelástico, es decir, el ángulo entre la dirección
entrante y la normal del borde de la mesa es igual al de la normal y la
dirección saliente.

## Entrada de ejemplo
```
2
4
0.0 0.0
5.0 0.0
10.0 0.0
0.0 10.0
-10.0 0.0
0.0 -10.0
6
0.0 0.0
5.0 0.0
10.0 0.0
0.001 9.999
-0.001 9.999
-10.0 0.0
-0.001 -9.999
0.001 -9.999
```

## Salida de ejemplo
```
4
4
```
