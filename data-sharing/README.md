# data-sharing

En esta seccion se desarrolla el manejo de variables privadas inicializadas o no, para su implementacion dentro de la region paralela (Una vez realizado el Fork).

En la implementacion de directivas est´a:

- **private:** Un nuevo objeto del mismo tipo y tamaño se declara una vez para cada subproceso en el equipo, y el nuevo objeto ya no se almacena asociado con el objeto original.
- **firstprivate:** Las copias privadas de las variables se inicializan desde el objeto original existente antes de la construcción paralela.

### Detalles

Antes de iniciar la region paralela, se inicializan 4 variables desde el heap y 1 en el entorno global. A partir de aqui, se establece mediante las directivas, cuales entraran en la region paralela y sus condiciones de instancia. Por tanto algunas no estaran de modo compartido e incluso otras vendran a compartirse unicamente en la region paralela.
 
### Comparativa de variables contenidas:

| Variable         | Descripcion                                                     |
|------------------|-----------------------------------------------------------------|
| G                | Compartida de manera global a cada hilo                         |
| a                | Privada para cada hilo disponible                               |
| b                | Privada con inicializacion desde el main()                      |
| c                | Compartida desde el heap a todos los hilos                      |
| t                | Instanciada en el heap, pero tambien de forma privada sin inicializar        |
| s                | Variable estatica unicamente existente en la region paralela    |
