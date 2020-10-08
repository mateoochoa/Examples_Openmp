# OpenMP Repository

El presente GIT tiene como objetivo presentar el desarrollo de algoritmos basados en la implementacion de directivas OpenMP. De acuerdo a los requerimientos de la materia Fundamentos de Programación Paralela en la Universidad Sergio Arboleda, los cuales constan de realizar una explicación para cada código propuesto con su respectiva documentacion, además de la profundizacion de su contenido.

Este trabajo se basa en los ejemplos planteados por el usuario muatik de github
en el repositorio: https://github.com/muatik/openmp-examples

[![OpenMP](https://www.openmp.org/wp-content/uploads/openmp-enabling-hpc-since-1997.png)](https://www.openmp.org/)

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://github.com/mateoochoa/Examples_Openmp.git)

La biblioteca de procesamiento OpenMP es un API basada en estándares para C / C ++ y Fortran. Permite generar un nuevo flujo de proceso concurrente e incluso la implementación de afinidad, para el aprovechamiento mediante subprocesos de la ejecución de aplicaciones en multi hilo. Es diseñado para sistemas con superiores a 2 hilos con el propósito de garantizar eficacia en los resultados del proceso. El flujo se puede programar para que se ejecuten secciones específicas a modo de carga en hilos concretos, ganando así velocidad a través del paralelismo o distribución de subprocesos. De forma predeterminada, cada subproceso ejecuta la sección de código paralelizada de forma independiente. Las construcciones de trabajo compartido se pueden utilizar para dividir una tarea entre los subprocesos de modo que cada subproceso ejecute su parte asignada del código. Tanto el paralelismo de tareas y el paralelismo de datos se puede lograr utilizando OpenMP de esta manera.

OpenMP es un modelo de programación estándar para la programación paralela de
memoria compartida que permite:

- Portátil en todas las arquitecturas de memoria compartida
- Paralelizar bucles de interacion de forma indepentiente
- Permite la paralelización incremental
- Extensiones basadas en compiladores para los lenguajes de programación existentes
    - Principalmente por directivas
    - Algunas rutinas de la biblioteca (Programacion Modular)

# Integrantes

  - [Luis Mateo Ochoa Cañon]
  - [Miguel Angel Ruiz Torres]

# Caracteristicas Generales

  - Implementacion multiple de directivas y clausulas de procesamiento.
  - Comparativa de rendimiento para aplicacion multi-hilo en diferentes aplicaiones

Cambios significativos:
  - Migracion del codigo de C++ a C99. 
  - Habilitacion de regiones comparativas de acuerdo a las diferentes operaciones.
  - Documentacion general del funcionamiento para cada algoritmo.

El codigo para cada modulo generado, ha sido revisado y profundizado a modo de mejora con el proposito de caracterizar su funcionamiento respecto de: 

> Optimizacion de regiones Paralelas.
> Implementacion de memoria compartida entre hilos.
> Calculacion y uso de los conceptos.
> Consumo de manera segura entre subprocesos.




### Documentacion Tecnica

En las diferentes secciones se conserva el algoritmo original igualmente documentado, pero no hace uso completo de las funciones contenidas. Posteriormente al entendimiento se hace la migracion del lenguaje y se ponen en funcionamiento todas las secciones del codigo para conocer su aplicacion de forma comparativa.

### Instalacion

El algoritmo de als-movies requiere del uso adicional del paquete [Eigen](http://robots.uc3m.es/gitbook-installation-guides/install-eigen.html) para ser compilado y ejecutado.

No es necesaria la instalacion de dependencias adicionales. Para la compilacion en general de los demas algoritmos es necesario la implementacion de los comandos basicos para importar el OpenMP haciendo uso de **gcc**.

```sh
$  gcc main.c -fopenmp
```

### Desarrollo

Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.


#### Contribucion y Colaboradores:

Agradecimientos a [ muatik](https://github.com/muatik/openmp-examples) como creador base del contenido en este repositorio.


Licencia 
----

GNU General Public License V3


**Free Software, Hell Yeah!**


   [Luis Mateo Ochoa Cañon]: <https://github.com/mateoochoa>
   [Miguel Angel Ruiz Torres]: <https://github.com/miguelanruiz>
   
