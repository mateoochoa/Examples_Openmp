/*************************************************************************************/
/*            Author: Mustafa Atik                                                   */
/*          Location: Berlin / Germany                                               */
/*           Contact: muatik@gmail.com                                               */
/*        Implemented in C by:Miguel Angel and Luis Mateo                            */
/*      email: miguelan.ruiz@correo.usa.edu.co and luis.ochoa3@correo.usa.edu.co     */
/*                                                                                   */
/*  the simplest example of Openmp                                                   */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    /* Create a parallel region to print the ID of each thread*/
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        printf("hello  %d\n", ID);
        printf("hello again %d\n", ID);
    }
//    output:
//    hello  1
//    hello  0
//    hello  3
//    hello  2
//    hello again 1
//    hello again 0
//    hello again 3
//    hello again 2
    return 0;
}