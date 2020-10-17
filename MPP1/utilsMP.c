/***************************************************************************************************/
/*           Archivo: utilsMP.c                                                                    */
/*             Autor: Miguel Angel and Luis Mateo                                                  */
/*             Email: miguelan.ruiz@correo.usa.edu.co; luis.ochoa3@correo.usa.edu.co               */
/*         Ubicacion: Bogota / Colombia                                                            */
/*                                                                                                 */
/*                                                                                                 */
/*      Descripcion:                                                                               */
/* Esta biblioteca se encarga de gestionar los parametros de flujo dentro de una region o se-      */
/* ccion paralela como son la inicializacion, identificacion y tomas de rendimiento. Incluso       */
/* permite la presentacion en consola de estas medidas.                                            */
/*                                                                                                 */
/***************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <sys/time.h>
#include <errno.h>
#include "utilsMP.h"

#define MAX_THREADS 16

/* Variables de rendimiento */
struct timeval start[MAX_THREADS];
struct timeval stop[MAX_THREADS];

static int nThreads;

/* Toma de tiempo inicial para rendimiento */
void mpStart(int threadID){
#pragma omp barrier
	gettimeofday(start+threadID,NULL);
}

/* Toma de tiempo final para rendimiento */
void mpStop(int threadID){
	gettimeofday(stop+threadID,NULL);
}

/* Funcion que establece numero de hilos */
void argsInit(int argc, char* argv[]){
	nThreads = (int) atoi(argv[1]);
	if (!nThreads || nThreads == MAX_THREADS){
		printf("Numero de threads invalido");
		exit(1);	
	}
	omp_set_num_threads(nThreads);
}

/* Funcion que identifica el hilo en ejecucion */
int mpParallel(void){
	int thread;
	thread = omp_get_thread_num();
	return thread;
}

/* Presentacion en pantalla de resultados */
void mpEnd(void){
	int thread;
	double average = 0.0;
	for(thread = 0; thread < nThreads; thread++){
		stop[thread].tv_usec -= start[thread].tv_usec;
		if (stop[thread].tv_usec == 0 ){
			stop[thread].tv_usec += 1000000;
			stop[thread].tv_usec --;		
		}
		stop[thread].tv_sec -= start[thread].tv_sec;		
		printf("%d; %9.0f\n",thread,(double)(stop[thread].tv_sec * 1000000 + stop[thread].tv_usec));
		average += stop[thread].tv_sec * 1000000 + stop[thread].tv_usec;
	}
	printf("p; %9.0f\n", average/nThreads);
}

