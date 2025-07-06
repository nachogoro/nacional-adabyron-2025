# Problema E - El engaño de Oskar
Oskar Schindler, popularizado por la película de Steven Spielberg de 1993 "La
lista de Schindler", fue un empresario alemán que salvó de una muerte segura a
unos mil doscientos judíos durante el Holocausto de la Segunda Guerra Mundial.

Para eso se sirvió de su fábrica de esmaltados, ubicada inicialmente en
Cracovia (Polonia). Desde allí utilizó judíos como mano de obra barata y con
esa excusa los fue alejando del campo de concentración de Plaszow y de su
despiadado comandante Amon Göth. Mantenerlos a salvo, no obstante, se fue
complicando con el avance de la guerra pues los oficiales nazis cada vez fueron
más reacios a permitírselo y tuvo que dedicar gran cantidad de dinero a
sobornos aun cuando la fábrica funcionaba a la perfección. Incluso
proporcionaba material de guerra para el bando alemán.

La situación pasó a ser crítica cuando Alemania comenzó a perder la guerra.
Invirtiendo gran cantidad de dinero consiguió desplazar la fábrica y a "sus
judíos" (los bautizados como _Schindlerjuden_, "Judíos de Schindler") a
Brünnlitz (Republica Checa). Allí ya ni siquiera se empeñó en hacer que la
fábrica fuera viable económicamente; muchos de los empleados no eran adecuados
para esos trabajos y la mayoría de las máquinas apenas funcionaban por lo que
terminó comprando de forma ilegal munición a otros proveedores que luego
mostraba como fabricada allí.

Los momentos más delicados se daban cuando en esos últimos meses de guerra se
enfrentaba a las inspecciones de los oficiales nazis. Antes de subirlos a su
despacho para agasajarlos con bebidas alcohólicas adquiridas en el mercado
negro, debía dar un paseo con ellos por la línea de producción mostrándoles el
buen hacer de algunas de sus máquinas. El problema era decidir qué máquinas
enseñar para que el rendimiento medio de todas ellas fuera el mayor posible.

## Entrada
La entrada estará compuesta por distintos casos de prueba, cada uno ocupando
dos líneas.

La primera línea de cada caso contiene dos números; el primero indica el número
$n$ de máquinas que hay en la fábrica (hasta 300.000), y el segundo es el
número mínimo de máquinas que hay que enseñar a los oficiales nazis durante la
visita ($1 \leq k \leq n$). La segunda línea contiene el rendimiento de cada
una de las máquinas (números entre 0 y 100.000).

Tras el último caso de prueba viene una línea con dos ceros que no debe
procesarse.

## Salida
Por cada caso de prueba aparecerá una única línea con la mayor media del
rendimiento que se puede conseguir que perciban los oficiales nazis si les
enseñamos al menos $k$ máquinas consecutivas de la línea de producción.

El número de decimales mostrados de la media debe ser suficiente para que el
error entre el valor escrito y el real sea menor que $10^{−4}$.

## Entrada de ejemplo
```
5 1
0 10 0 10 0
5 2
0 10 0 10 0
5 3
0 10 0 10 0
5 4
0 10 0 10 0
2 2
50000 100000
0 0
```

## Salida de ejemplo
```
10
6.66667
6.66667
5
75000
```
