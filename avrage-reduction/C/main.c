/*************************************************************************************/
/*            Author: Mustafa Atik                                                   */
/*          Location: Berlin / Germany                                               */
/*           Contact: muatik@gmail.com                                               */
/*        Implemented in C by:Miguel Angel and Luis Mateo                            */
/*      email: miguelan.ruiz@correo.usa.edu.co and luis.ochoa3@correo.usa.edu.co     */
/*                                                                                   */
/*  Description:                                                                     */
/*  This code make a measure of the performance making an average operation to the   */
/*  sum from 1 to 600 Millions, in one function it does with a variable private that */
/*  make a merge at the end of the operation of each thread and other that makes the */
/*  sum in a public variable.                                                        */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void avg_round_robin();
void avg_reduction();

int main() {
    avg_round_robin();
    avg_reduction();
    return 0;
}

/*  Calculate the average of the sum from 1 to 600 Millons*/
void avg_round_robin() {
    int N = 600000000;
    double tavg = 0;

    double timer_start = omp_get_wtime();
    omp_set_num_threads(16);
    /*  Creates a parallel work*/
    #pragma omp parallel
    {
        double avg;
        int id = omp_get_thread_num();
        int nthreads = omp_get_num_threads();
        /*Make the sum from 1 to 600 millions with a step of nthreads size*/
        for (int i = id; i < N; i+=nthreads) {
            avg += i;
        }
        /*Waits to the disponibility of the tavg variable and after sum its value*/
        #pragma omp atomic
        tavg += avg;
    }
    /*  save the time elapsed and make the average*/
    double timer_elapsed = omp_get_wtime() - timer_start;
    tavg = tavg / N;

    printf("threads: %d, avg_round: %f took: %f s\n", omp_get_max_threads(),tavg, timer_elapsed);    
    //     1 threads took 2.1
    //     4 threads took 0.7
    //    48 threads took 0.65
}

void  avg_reduction() {
    int N = 600000000; //600 M
    int j = 0;
    double tavg = 0;

    double timer_start = omp_get_wtime();
    omp_set_num_threads(48);
    /*  Define a parallel work with a "private variable that the hardware copy its value in the begining and
        at the end it sums its value to the original variable*/
    #pragma omp parallel for reduction(+:tavg)
    for (j = 0; j < N; ++j) {
        tavg += j;
    }

    double timer_elapsed = omp_get_wtime() - timer_start;
    tavg = tavg / N;

    printf("threads: %d, avg_reduction: %f took: %f s\n", omp_get_max_threads(),tavg, timer_elapsed);    
    //     1 threads took 2.1
    //     4 threads took 0.69
    //    48 threads took 0.65
}