/*************************************************************************************/
/*            Author: Mustafa Atik                                                   */
/*          Location: Berlin / Germany                                               */
/*           Contact: muatik@gmail.com                                               */
/*        Implemented in C by:Miguel Angel and Luis Mateo                            */
/*      email: miguelan.ruiz@correo.usa.edu.co and luis.ochoa3@correo.usa.edu.co     */
/*                                                                                   */
/*  Description:                                                                     */
/*  This code calculates the elapsed time of each thread in task of process them and */
/*  also took the quantity of tasks realized by each one                             */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

typedef struct Node Node, *Node_int, *Node_int_data;
typedef struct Queu Queu,*Queu_add_int, *Queu_add_node, *Queu_remove;

struct Node
{
    int data;
    struct Node* next = NULL;
};

int main(){
    
    return 0;
}