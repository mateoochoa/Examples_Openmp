/***************************************************************************************************/
/*           Archivo: cliente.c                                                                    */
/*             Autor: Miguel Angel and Luis Mateo                                                  */
/*             Email: miguelan.ruiz@correo.usa.edu.co; luis.ochoa3@correo.usa.edu.co               */
/*         Ubicacion: Bogota / Colombia                                                            */
/*                                                                                                 */
/*                                                                                                 */
/*      Descripcion:                                                                               */
/* Se desea implementar un algoritmo de multiplicacion de matrices clasica (filas por columnas),   */
/* que cumpla las siguietnes caracteristicas:                                                      */
/* 1. Se reserva la memoria para el tamaño de la matriz                                            */
/* 2. Se entregan los argumentos de la matriz y el numero de hilos                                 */
/* 3. Las matrices deben ser inicializadas                                                         */
/* 4. Debe paralelizarse los bucles con la biblioteca OpenMP                                       */
/* 5. Debe existir un modulo que implemente toma de rendimiento y presentacion                     */
/* 6. Debe existir un MAKEFILE para la compilacion del codigo                                      */
/*                                                                                                 */
/***************************************************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include "utilsMP.h"

# ifndef MIN
# define MIN(x,y) ((x)<(y)?(x):(y))
# endif
/* Definicion del tamaño maximo de la matriz */
# define DATA_N (1024*1024*64*3)
/* Matrices vistas desde el vector */
static double  MEM_CHUNK[DATA_N];

void Matrix_Init_col(int N, double *a, double *b, double *c)
{
  int j,k;
/* Inicializacion de matrices */
  for (k=0; k<N; k++)
    for (j=0; j<N; j++) {
      a[j+k*N] = 2.0*(j+k);
      b[j+k*N] = 3.2*(j-k);
      c[j+k*N] = 1.0;      
    }
}

void test(int N, double *a, double *b, double *c)
{
  int j,k;
/* Inicializacion de matrices */
printf("A: \n");
  for (k=0; k<N; k++){
    for (j=0; j<N; j++) {
      a[j+k*N] = j+k;
      b[j+k*N] = j+k;
      c[j+k*N] = 0.0;
      printf("%f ", a[j+k*N]);
    }
  printf("\n");
  }
  printf("B:\n");
  for (k=0; k<N; k++){
    for (j=0; j<N; j++) {
      a[j+k*N] = j+k;
      b[j+k*N] = j+k;
      c[j+k*N] = 0.0;
      printf("%f ", b[j+k*N]);
    }
  printf("\n");
  }
}

void print_matrix(int N, double *a, double *b, double *c)
{
  int j,k;
/* Inicializacion de matrices */
printf("C: \n");
  for (k=0; k<N; k++){
    for (j=0; j<N; j++) {
      printf("%f;", c[j+k*N]);
    }
  }
}

int main (int argc, char **argv)
{
  int N; 
  /*Validacion de Argumentos*/
  if(argc <= 2){
    printf("client sizeMatrix nThreads\n");
    return -1;
  }
  /* Obtencion del tamaño de la matriz por el usuario */
  N = (int)atof(argv[1]);
  argc--;
  argv++;

  if (N > 1024*8)
  {
    printf("Unvalid MatrixSize\n");
    return -1;
  }
  /* Asignacion de hilos a la region paralela*/
  argsInit(argc, argv);

#pragma omp parallel
{
  /*Inicio de la region paralela{}*/

  int     i, j, k, SZ = N;
  double  *a, *b, *c;
  a = MEM_CHUNK;
  b = a + SZ*SZ;
  c = b + SZ*SZ;
  int num_thread;

  num_thread = mpParallel();
  /*Solo por master()*/
  #pragma omp master
    Matrix_Init_col(SZ, a, b, c);    

  /* Invocacion de toma rendimiento (inicio) */  
  mpStart(num_thread);

  /*Inicio de seccion paralela "for" para multiplicacion de matrices*/
#pragma omp for
  for (i=0; i<SZ; i++){
    for (j=0; j<SZ; j++) {
      double *pA, *pB, S;
      S=0.0;
      pA = a+(i*SZ); pB = b+j;
      for (k=SZ; k>0; k--, pA++, pB+=SZ)
        S += (*pA * *pB);
      c[i*SZ+j]= S;
    }
  }
  /*Invocacion de toma rendimiento (Fin)*/  
  mpStop(num_thread);
  
  /*Fin de la region paralela{}*/
}
  /*Invocacion de impresion de funcion */
  mpEnd();
  return 0;
}