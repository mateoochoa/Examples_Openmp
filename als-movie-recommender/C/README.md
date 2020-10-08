# als-movie-recommender

De un archivo externo "data.txt" que debe contener n filas con tres valores, las cuales representan un Id de usuario, Id de pelicula y un puntaje del 1 al 10, se extraen los valores mencionados con anterioridad para despues usarlos en el calculo de recomendación de pelicula por usuario.

La sección del programa en paralelo se ejecuta un total de 2000 veces en el cual se define cautro hilos de trabajo, con un asignamiento de tareas estatica y variables privadas.


#Compilación

Para compilar el código se descargó la versión 3.2 de la biblioteca Eigen (de: http://eigen.tuxfamily.org/index.php?title=Main_Page#Download), posterior a esto se descomprime la biblioteca y se ingresa a la siguiente ruta: demos/mix_eigen_and_c en la cual se digitan los siguientes comandos para crear un archivo binario de la biblioteca para C:

    g++ -c binary_library.cpp -O2 -msse2 -I ../..

luego, copiamos el archivo binary_library.o en el mismo directorio en el que se encuentra el código a compilar y finalmente se compila con el siguiente comando:

    gcc main.c binary_library.o -o mainc -lstdc++ -fopenmp -lm
