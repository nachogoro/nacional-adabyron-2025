# Problema D - La duración de los recuerdos

La vieja casa del pueblo tiene muchos achaques, hace décadas que pide en
silencio una reforma integral y por fin ha llegado el momento de atender sus
súplicas. Al mover los muebles y otros muchos trastos para facilitar la obra,
al fondo de un armario lleno de ropa que, de puro vieja, se ha puesto de moda y
olvidado varias veces, han aparecido unas fotos antiguas de otros paisajes y
otros tiempos con gente que ya nadie recuerda.

Hemos preguntado a la abuela y ha insistido en que una muchacha de jersey de
cuello alto y flequillo es ella. Pero cualquier parecido con la realidad es
pura coincidencia y nos cuesta mucho creerla. No ha sabido decirnos nada más
del resto, y es una pena pensar que aquellas gentes que una vez debieron ser
importantes en su vida hoy sean solo sombras del pasado borradas de su memoria.

Los recuerdos desaparecen pasado un tiempo que depende de su intensidad
emocional, y me encantaría saber cuánto duraron en la cabeza de la abuela los
que representan cada foto. Si tuviera una máquina del tiempo, viajaría hacia
atrás y hacia delante para encontrarme con ella y preguntarle si las recuerda.
La paradoja es que, según los expertos, cada vez que alguien trae a la memoria
un suceso de su pasado dobla el tiempo que lo recordará. De modo que el mero
hecho de encontrarme con mi joven abuela y enseñarle una de aquellas fotos
puede hacer que, al volver al presente, sí la recuerde. Obviamente, si la
abuela ya había olvidado el recuerdo cuando le enseño la foto, entonces la
pregunta no tiene ningún efecto sobre su memoria.

El objetivo es averiguar en qué momento la abuela olvidó cada una de las fotos
usando una máquina del tiempo que nos permite movernos a cualquier instante de
su vida.

La aplicación deberá procesar varios casos de prueba. Cada uno de ellos
comienza con el número de segundos (entre $1$ y $10^8$) que estimamos que le
pudo durar el recuerdo de una foto. Después, la aplicación realizará viajes en
el tiempo a segundos concretos tras la realización de la foto (el segundo 1 es
el momento en el que se tomó la instantánea) para preguntar a la abuela si la
recuerda. Para eso, escribirá el símbolo `?` seguido del número del segundo al
que se viaja.

A continuación, se podrá leer de la entrada la respuesta dada, que será SI o
NO. Ten en cuenta que las respuestas SI ¡cambian el futuro! duplicando la
duración del recuerdo.

Cuando la aplicación sepa el último segundo en el que la abuela tuvo el
recuerdo de la foto (antes de que empezáramos a viajar en el tiempo y a
recordárselo), escribirá `=>` seguido del número de segundo.

A continuación aparece un ejemplo de ejecución. La letra cursiva se utiliza
para indicar lo que la aplicación lee por la entrada estándar y la negrita lo
que escribe por la salida estándar.

La aplicación terminará cuando se lea un caso de prueba con el número de
segundos en 0.

_10_  
**? 6**  
_NO_  
**? 5**  
_SI_  
**? 6**  
_SI_  
**=> 5**  
_0_

## Notas
Al tratarse de un problema *interactivo* es importante que cada vez que tu
solución escriba algo que el juez deba leer se asegure de volcar la salida
(usando terminología inglesa, haga "*flush*"). La forma de hacerlo varía entre
lenguajes. En los admitidos en la competición puede hacerse con:

- C++: `cout << flush;` o, si quieres además escribir un salto de línea, `cout << endl;`
- C: `fflush(stdout);`
- Java: `System.out.flush();`
- Python: `print(..., flush=True)` o `sys.stdout.flush()`

Si la solución necesita un número excesivo de viajes en el tiempo (consultas)
para averiguar la duración original del recuerdo, tardará demasiado tiempo y
provocará que el juez devuelva un veredicto TIME-LIMIT.
