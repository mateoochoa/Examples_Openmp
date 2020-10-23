/***************************************************************************************************/
/*           Archivo: algoritmo_3.c                                                                    */
/*             Autor: Miguel Angel and Luis Mateo                                                  */
/*             Email: miguelan.ruiz@correo.usa.edu.co; luis.ochoa3@correo.usa.edu.co               */
/*         Ubicacion: Bogota / Colombia                                                            */
/*                                                                                                 */
/*                                                                                                 */
/*      Descripcion:                                                                               */
/* Se desea implementar un algoritmo de multiplicacion de matrices dos filas por dos filas a la vez*/
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
      a[j+k*N] = 2.0;
      b[j+k*N] = 1.0;
      c[j+k*N] = 0.0;
    }
}

void test(int N, double *a, double *b, double *c)
{
  int j,k;
/* Inicializacion de matrices */
printf("A: \n");
  for (k=0; k<N; k++){
    for (j=0; j<N; j++) {
      a[j+k*N] = 2.0;
      b[j+k*N] = 1.0;
      c[j+k*N] = 0.0;
      printf("%f ", a[j+k*N]);
    }
  printf("\n");
  }
  printf("B:\n");
  for (k=0; k<N; k++){
    for (j=0; j<N; j++) {
      a[j+k*N] = 2.0;
      b[j+k*N] = 1.0;
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

  num_thread = omp_get_thread_num();
  printf("Im: %d\n", num_thread);
  /*Solo por master()*/
  #pragma omp master
    Matrix_Init_col(SZ, a, b, c);

  /* Invocacion de toma rendimiento (inicio) */  
  mpStart(num_thread);
/*num_thread = omp_get_thread_num();
  printf("Im: %d\n", num_thread);*/
  /*Inicio de seccion paralela "for" para multiplicacion de matrices*/
#pragma omp for
 for (i=0; i<SZ; i=i+2){
    for (j=0; j<SZ; j=j+2) {
      double *pA, *pB, c0, c1, c2, c3;
      c0 = c1 = c2 = c3 = 0.0;
      pA = a+(i*SZ); pB = b+(j*SZ);
      for (k=SZ; k>0; k=k-2, pA = pA+2, pB = pB+2){
        double a0, a1, a2, a3, b0,b1, b2, b3;
	if(k==1){a0 = *pA; a2 = *(pA+SZ); b0 = *pB; b2 = *(pB+SZ); 
	c0 += a0*b0; c1 += a0*b2;c2 += a2*b0;c3 += a2*b2;}
	else{
	a0 = *pA; a1 = *(pA+1); a2 = *(pA+SZ); a3 = *(pA+SZ+1);
        b0 = *pB; b1 = *(pB+1); b2 = *(pB+SZ); b3 = *(pB+SZ+1);

	c0 += a0*b0 + a1*b1; 
	c1 += a0*b2 + a1*b3; 	
	c2 += a2*b0 + a3*b1; 	
	c3 += a2*b2 + a3*b3;  
	}
      }
      pB = c + i*SZ + j;
      if(j == SZ-1){*pB = c0; *(pB+SZ) = c2; break;}
      *pB = c0 ;
      *(pB+1) = c1;
      *(pB+SZ) = c2;
      *(pB+SZ+1) = c3;
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
