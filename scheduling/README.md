# scheduling

Las clausulas de planificacion pertenecientes a OpenMP permiten distribuir las cargas de forma eficiente en relacion a su aplicacion. Basicamente el algoritmo posee 3:

- _Static_
- _Dynamic_
- _Auto_

La schedule(static, chunk-size) cláusula de la construcción de bucle especifica que el bucle for tiene el tipo de programación estática. OpenMP divide las iteraciones en trozos de tamaño chunk-sizey los distribuye en subprocesos en un orden circular.
Cuando no chunk-sizese especifica, OpenMP divide las iteraciones en fragmentos que son aproximadamente del mismo tamaño y distribuye como máximo un fragmento a cada hilo.

La schedule(dynamic, chunk-size) cláusula de la construcción de bucle especifica que el bucle for tiene el tipo de programación dinámica. OpenMP divide las iteraciones en trozos de tamaño chunk-size. Cada hilo ejecuta un fragmento de iteraciones y luego solicita otro fragmento hasta que no haya más fragmentos disponibles.
No existe un orden particular en el que se distribuyan los fragmentos a los subprocesos. El orden cambia cada vez que ejecutamos el ciclo for.

El tipo de programación schedule(auto) delega la decisión de la programación al compilador y/o al sistema de ejecución.


[![Dynamic](http://drive.google.com/uc?export=view&id=1esurMV4ZNn6xXMj7mTsOlpVcBgoCtGdj)](https://github.com/mateoochoa/Examples_Openmp)
[![Static](http://drive.google.com/uc?export=view&id=1lQKHnt7_gVIdYELDLWDThwra9BpgeRqf)](https://github.com/mateoochoa/Examples_Openmp)
[![Auto](http://drive.google.com/uc?export=view&id=1mfi9l84NkkYkv5ApP7Isv4uNHsZJeBu4)](https://github.com/mateoochoa/Examples_Openmp)

### Detalles

La primera tarea que realiza el for, al igual que las demas, sera programar mediante forma estatica y con una segmentacion automatica por el compilador o entorno, una ejecucion con carga uniformemente repartida hacia los hilos dispuestos por el algoritmo. De manera que cada hilo tendra un similar numero de iteraciones en cada region paralela.
