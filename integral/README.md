# integral

En esta seccion se hace uso de diferentes metodos a nivel de paralelismo para realizar una integral. Para cada caso se tomaran variables privadas y compartidas, aplicando la misma funcion matematica logrando un aprovechamiento de las instancias en el stack para la generacion del resultado.

### Detalles

El algoritmo aplica una solucion de intregracion, en algunos casos haciendo uso de clausulas como reduccion, privatizacion de variables u optimizacion del **_overhead_** aplicando **_atomic_**. Como generalidad antes de iniciar la region paralela, se le entrega la implementacion al sistema operativo como un conjunto de subprocesos, donde este es el encargado de realizar la concurrencia y afinidad.
