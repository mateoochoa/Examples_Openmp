# heap-vs-stack

La directiva OpenMP define una estructura de acceso a las variables que son compartidas, comunmente provenientes del heap. Cuando estas no son instanciadas individualmente para cada hilo, requieren de esta programacion para la realizacion de cambios.

### Detalles

Una vez definida una ejecucion para tres hilos, la region paralela accede a una variable compartida e instancia otra de manera privada para demostrar como los 3 hilos casi que instantaneamente toman una variable y la modifican, pero aquella que es privada solo es accesible por su hilo propietario.
 
### Comparativa de variables contenidas:

| Variable         | Descripcion                                                     |
|------------------|-----------------------------------------------------------------|
| stack_sum        | Variable accesible desde el heap por todos los hilos            |
| heap_sum         | Instancia privada de los hilos en ejecucion                     |

