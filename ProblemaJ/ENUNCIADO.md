# Problema J - El retorno del profesor Malvado

El profesor Gabriel Malvado ha vuelto y está más enfadado que nunca. El curso
pasado sus estudiantes lo denunciaron (bueno, al menos se quejaron mucho en
redes sociales) por usar oscuras artes algorítmicas para minimizar las notas
medias de la clase. Como consecuencia, este año se ha corrido la voz y solo dos
valientes se han matriculado en su asignatura: Ana Tembleque y Mario Temerario.

En esta asignatura, Ana y Mario tendrán que hacer varios exámenes parciales a
lo largo del curso. Cada parcial se puntúa con un número natural (no
necesariamente en el rango 0–10). La nota final del curso se calcula haciendo
una media ponderada de las notas de los parciales, donde el peso de cada
parcial en la nota final puede ser un número entre 0 y 1, posiblemente con
decimales. Los pesos de todos los parciales deben sumar 1.

Este año, Malvado ha decidido que quiere poner a sus dos estudiantes la nota
que le dé la gana y para ello va a decidir los pesos de cada examen a
posteriori, una vez conozca las notas individuales de cada estudiante en cada
examen parcial. Además, no se corta: está dispuesto a asignar un peso de 0 a
los parciales que no le convengan. Total, ¿quién se lo va a impedir? ¿Los dos
únicos estudiantes? Sin embargo, no lo tiene tan fácil porque, sea cual sea la
ponderación que utilice para cada parcial, ha de ser la misma para ambos
estudiantes. ¡Qué fastidio! Tendrá que hacer sus maldades dentro de ese límite.
De momento, está barajando distintas notas finales para Ana y Mario, pero se
pregunta cuáles de ellas son posibles y cuáles no.

## Entrada
La entrada consta de una serie de casos de prueba. Cada caso de prueba comienza
con una línea con dos números: $N$, el número de exámenes parciales realizados
a lo largo del curso y $Q$, el número de consultas que quieren realizarse ($1
\lt N, Q \lt 400.000$). Después vienen dos líneas con $N$ números enteros cada
una. La primera línea contiene las calificaciones obtenidas por Ana; la
segunda, las calificaciones de Mario. Cada calificación es un número entero
entre $0$ y $2 \cdot 10^9$. Por último, tenemos $Q$ líneas, cada una con un par
de números, que indican la nota media que el profesor quiere poner a Ana y a
Mario, respectivamente. De nuevo, estas notas medias son números enteros entre
0 y $2 \cdot 10^9$.

La entrada finaliza con dos ceros, caso que no se procesa.

## Salida
Para cada caso de prueba deben imprimirse $Q$ líneas, una por cada consulta.
Para cada par $(A, M)$ correspondiente a una consulta, debe imprimirse SI si
existe una ponderación de las notas válida y común a ambos estudiantes con la
que la nota final de Ana sea A y la de Mario sea M. En caso contrario, debe
imprimirse NO. Una ponderación es válida si asigna a cada prueba un peso
comprendido entre 0 y 1 y la suma de todos los pesos es 1.

Tras cada caso de prueba debe imprimirse una línea con tres guiones `---`.

## Entrada de ejemplo
```
4 3
6 10 0 0
8 2 0 10
5 1
4 5
10 8
0 0
```

## Salida de ejemplo
```
SI
SI
NO
---
```

## Notas
En el caso de prueba del ejemplo hay tres consultas. En la primera (5, 1), el resultado es SI porque si se asignan los pesos de 0.5 al segundo y al tercer parcial (y 0 a los restantes), Ana tendría $10 \cdot 0.5 + 0 \cdot 0.5 = 5$ como nota final, y David tendría $2 \cdot 0.5 + 0 \cdot 0.5 = 1$. En la segunda consulta (4, 5) es posible obtener sendas notas finales asignando un peso de 0.25 a cada parcial. Por último, la combinación (10, 8) no es posible, ya que necesitaríamos un peso de 1 en el segundo parcial (y 0 en los restantes) para que Ana tenga un 10, pero en ese caso Mario obtendría un 2, y no un 8.
