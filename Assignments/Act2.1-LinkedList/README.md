
# Act 2.1 - Linked List

Carolina Vildósola Guzmán  
A01287373

## Descripción

En esta actividad se hizo una lista encadenada usando templates para que pudiera funcionar con diferentes tipos de datos. La lista está formada por nodos, donde cada nodo guarda un dato y un apuntador al siguiente nodo. Para comprobar que esto funcionara con diferentes tipos de datos fui haciendo pruebas utilizando enteros y strings.

## Archivos

- Node.h: aquí esta la estructura de los nodos, donde se guarda el dato y el apuntador al siguiente nodo
- LinkedList.h: aquí estan las funciones y operaciones de la lista encadenada
- main.cpp: aquí esta el programa principal, donde fui probando las diferentes funciones con enteros y strings.

## Funciones 

En la lista se pueden hacer diferentes operaciones como:

- Agregar un elemento al principio.
- Agregar un elemento al final.
- Insertar un elemento después de una posición.
- Borrar un dato.
- Borrar un elemento por posición.
- Obtener un dato por posición.
- Actualizar un dato.
- Actualizar un dato por posición.
- Buscar un dato y obtener su posición.
- Utilizar el operador "[]"
- Copiar una lista utilizando el operador "="

## Templates

Use template <typename T> para poder usar la misma lista con diferentes tipos de datos para no tener que hacer una lista diferente para cada uno, y para comprobar que esto funcionara hice pruebas utilizando "int" y "string"

## Prompts utilizados

En la actividad use ChatGpt y Copilot como apoyo para poder entender mejor algunas partes que se me hicieron complicadas. Tmabién lo use para organizar mejor mis ideas.
Algunos de los prompts que use fueron:

- "No quiero que me des pedazos de código ya hechos quiero que vayamos paso a paso, juntando cada parte, cada sección y cada función que necesitamos para que el código funcione. Yo te voy a ir diciendo las ideas que se me ocurran sobre cómo podría hacerlo o cómo podría empezar, y también te voy a ir mandando pedacitos de mi código para que me digas si voy bien o mal.
Como te dije, no quiero que tú me des el código directo quiero ir intentando hacerlo yo y que tú me vayas guiando. Solo si yo te pido una pista o alguna idea clave porque ya no sé cómo seguir, puedes ayudarme un poco más, pero sin darme el código completo".

- "No entiendo muy bien cómo funciona una Linked List con nodos y apuntadores. ¿Me puedes explicar cómo se conectan head, next y los nodos?"

- "¿Cómo puedo insertar un nodo después de una posición específica sin perder la conexión con el resto de la lista?"

- "¿Cómo puedo recorrer una Linked List para encontrar una posición específica y qué debo cuidar con los índices?"

- "¿Me puedes explicar cómo funciona la sobrecarga del operador "[]" en una Linked List y por qué debe regresar una referencia?"
-


## Reflexión

### ¿Qué parte del código te propuso la IA que aceptaste tal cual y por qué era correcta?

Una de las cosas que si acepté fue usar un apuntador auxiliar para recorrer la lista. La idea era empezar desde head e ir avanzando con aux = aux->next. Esto si me hizo sentido porque cada nodo tiene un apuntador hacia el siguiente y así podía recorrer la lista sin cambiar directamente head. 

### ¿Qué parte modificaste y cómo verificaste que tu cambio era mejor?

Fui modificando algunas de las sugerencias que me daba la IA para que quedaran de acuerdo con la estructura que ya quería y tenía en mi código. 
Una de las cosas en las que tuve mucho cuidado fue con las posiciones y los índices, ya que dependiendo de la función necesitaba llegar al índice que era indicado o al nodo anterior.
Y para poder comprobar que estuviera funcionando fui haciendo pruebas con listas pequeñas, donde podía fácil darme cuenta que dato debia estar en cada posición, también fui haciendo pruebas con enteros y strings para comprobar que todo siguiera funcionando con los diferentes tipos de datos.

### ¿Dónde se equivocó la IA y cómo lo detectaste?

No encontré un error gigante en las sugerencias que me iba dando la IA, pero si hubo momentos donde la IA interpretaba y a veces no me entendia mi idea de como yo quería hacer el código, por ejemplo: al trabajar con la función de insertar, en un momento la IA interpretó que quería insertar el nuevo dato en el índice que yo indicaba, cuando realmente lo que yo quería era insertarlo después de ese índice. Esto hizo que mi dato terminara en una posición que no quería. 

Me pude dar cuenta al hacer pruebas con listas pequeñas, donde podía saber facilmente cual elemento debía quedar en cada posición y así pude ver que aunque el código si compilaba, el resultado no era lo que buscaba. 

### ¿Qué harías diferente si no tuvieras Copilot/ChatGPT?

Si no tuviera Copilot o ChatGPT creo que me hubiera tardado muchisimo más en hacer la actividad, sobre todo por el hecho de la comprensión de cosas que no tenía muy claras, el aclarar dudas, detección de errores y sintaxis. En eso si es una ayuda enorme.
Y sobre todo las partes de apuntadores y sobrecarga de operadores, me hubiera tardado mucho porque fueron las partes que más me costaron entender.

Si no tuviera estos apoyos tendria que tardarme porbablemnte mucho más tiempo bsucando en internet soluciones, siento que si puede tener su beneficio eso porque es un reto mayor pero con el tiempo que tenemos defintivamente es más fáci apoyarte de la IA. Probablemnte me la viviria en asesorias si no tuviera estas grandes herramientas y tendria que hacer muchisimas más pruebas. Siento que ocuparía ser más organizada en todo lo que conlleva esta actividad si no tuviera la IA.

## Compilación

Para compilar el programa:

g++ -std=c++20 main.cpp -o main

Para ejecutarlo:

./main