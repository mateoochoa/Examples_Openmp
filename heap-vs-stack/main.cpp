/*************************************************************************************/
/*            Author: Mustafa Atik                                                   */
/*          Location: Berlin / Germany                                               */
/*           Contact: muatik@gmail.com                                               */
/*  Code reviewed by: Miguel Angel and Luis Mateo                                    */
/*                                                                                   */
/*                                                                                   */
/*      Description:                                                                 */
/* This code will show the difference between variables taken from the heap          */
/* vs created on the parallel region (stack) to compute on each thread.              */
/*                                                                                   */
/*************************************************************************************/

#include <iostream>
#include <omp.h>

int main() {
    
    int heap_sum = 0;
/*********************** Setting number of available threads *************************/
    omp_set_num_threads(3);
/*************************************************************************************/
    #pragma omp parallel
    {
	//printf("Threads running: %d\n", omp_get_num_threads());
/********************************* Private instance **********************************/
        int stack_sum=0;
/*************************************************************************************/
        stack_sum++;
        heap_sum++;
        printf("stack sum is %d\n", stack_sum);
        printf("heap sum is %d\n", heap_sum);
    }

    std::cout << "final heap sum is " << heap_sum << std::endl;

/***************************************** Output ************************************/
//    stack sum is 1
//    stack sum is 1
//    stack sum is 1
//    heap sum is 3
//    heap sum is 3
//    heap sum is 3
//    final heap sum is 3
    return 0;
}
