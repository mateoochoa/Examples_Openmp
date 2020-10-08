/*************************************************************************************/
/*            Author: Mustafa Atik                                                   */
/*          Location: Berlin / Germany                                               */
/*           Contact: muatik@gmail.com                                               */
/*        Implemented in C by:Miguel Angel and Luis Mateo                            */
/*      Email: miguelan.ruiz@correo.usa.edu.co and luis.ochoa3@correo.usa.edu.co     */
/*          Location: Bogota / Colombia                                              */
/*                                                                                   */
/*      Description:                                                                 */
/* This codes show throught a implementation, how works the directives               */
/* private and firstprivate from OpenMP Library. When the code runs, will            */
/* show you the results about the shared and privated variables, on para-            */
/* llel region and out of there.                                                     */
/*                                                                                   */
/*************************************************************************************/

#include <stdio.h>
#include <omp.h>

/*************************** Function designed to this job ***************************/
void compare_cases();  
/*************************************************************************************/


/******************************** Global variable ************************************/
double G = 2.1;
/*************************************************************************************/


int main() {
    compare_cases();
    return 0;
}

void compare_cases() {

    int a=1, b=2, c=3, t=4;

/******************************* Defining available threads **************************/
    omp_set_num_threads(3);
/*************************************************************************************/

/**************************** Forking threads with conditions ************************/
#pragma omp parallel private(a), firstprivate(b)
    {
        // a will be private and, but not be initialized
        // b will be private and initialized
        // c will be shared to everyone;
        // t will be local; that is it is private, because is declared into this region and not static.

        int t = 5;

        static int s = 8; // will be shared to everyone; its static

        if (omp_get_thread_num() == 0)
            s = 2; // only can do thread number 0

        printf("thread id: %d, a: %d, b: %d, c: %d, t: %d, s: %d, G: %f, \n", omp_get_thread_num(), a, b, c, t, s, G);
        a = 21;
        b = 22;
        c = 23;
        t = 24;
    }

/************************ Join threads in order to just one **************************/

    printf("\nOut of the parallel region\n");
    printf("thread id: %d, a: %d, b: %d, c: %d, t: %d, G: %f, \n", omp_get_thread_num(), a, b, c, t, G);

//    OUTPUT:
//    thread id: 0, a: 0, b: 2, c: 3, t: 5, s: 2, G: 2.100000,
//    thread id: 2, a: 32752, b: 2, c: 3, t: 5, s: 2, G: 2.100000,
//    thread id: 1, a: 32767, b: 2, c: 3, t: 5, s: 2, G: 2.100000,
//
//    out of the parallel region
//    thread id: 0, a: 1, b: 2, c: 23, t: 4, G: 2.100000,
}
