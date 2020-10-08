/* 
*
*/

#include "binary_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

u_int8_t size = 0;

void load_csv(const char path [], u_int8_t * ptr);
void factorize();
void als(u_int8_t * ptr, int maxUserId, int maxMovieId, int rank, int threadNumber);

int main(){        
  factorize();
}

void load_csv(const char path [],u_int8_t * ptr ){
    char line [100];
    u_int8_t i = 0;
    FILE  *indata = fopen(path,"r");
    while(fgets(line, 100, indata) != NULL){      
        *(ptr+3*i) = atoi(&line[0]);
        *(ptr+3*i+1) = atoi(&line[2]);
        *(ptr+3*i+2) = atoi(&line[4]);    
        i++;
    }
    size = i;
    fclose(indata);
}

void factorize(){
    char path [] = "../data.txt";
    u_int8_t ratings [28][3];
    u_int8_t *ptr = ratings[0];
    int maxUserId = 7;
    int maxUMovieId= 9;
    int cols = maxUMovieId, rows = maxUserId;    
    load_csv(path, ptr);
    for (int i = 4; i < 5; ++i) {
        printf("Thread number: %d\n",i);
        als(ratings, maxUserId, maxUMovieId, 4, 1);        
    }
}

void als(u_int8_t * ratings, int maxUserId, int maxMovieId, int rank, int threadNumber){
    struct C_MatrixXd *U, *M, *A, *W, *row, *col, *aux;
    int i =0, iteration = 0, j = 0, k=0;
    int ui = 0, mi = 0, ri = 0, pel [maxUserId];
    double Eta = 0.03;
    double eta = Eta, error = 0, start = 0, elapsed = 0;
    double errorHistory [150], tempU [4] = {0,0,0,0}, max [maxUserId];
    int maxIteration = 2000;

    U = MatrixXd_new(maxUserId, rank);
    M = MatrixXd_new(rank, maxMovieId);    
    MatrixXd_set_random(U);
    MatrixXd_set_random(M);

    A = MatrixXd_new(maxUserId, maxMovieId);
    W = MatrixXd_new(maxUserId, maxMovieId);
    MatrixXd_set_zero(A);
    MatrixXd_set_zero(W);

    /*for(i = 0; i< 29;i++){
        printf("%d - %d - %d\n",*(ratings+3*i),*(ratings+3*i+1),*(ratings+3*i+2));
    }*/        
    for(i = 0; i < size ; ++i){
        ui = *(ratings+3*i) -1;
        mi = *(ratings+3*i+1) -1;
        ri = *(ratings+3*i+2);
        MatrixXd_set_coeff(A, ui, mi, ri);
        MatrixXd_set_coeff(W, ui, mi, 1);
    }

      
    aux = MatrixXd_new(maxUserId, maxMovieId);   

    start = omp_get_wtime();    
    for(iteration = 0 ; iteration < maxIteration ; ++iteration){

        #pragma omp parallel for num_threads(threadNumber) schedule(static) private(ui, mi, ri, error, tempU)
        for(i = 0 ; i < size ; ++i){
            ui = *(ratings+3*i) -1;
            mi = *(ratings+3*i+1) -1;
            ri = *(ratings+3*i+2);
            for(j = 0 ; j < rank ; j++){
                error = error + MatrixXd_get_coeff(U,ui,j)*MatrixXd_get_coeff(M,j,ui);                
            }
            error = ri - error;
                    
            for(j = 0 ; j < rank-1 ; j++){
                tempU[j] = MatrixXd_get_coeff(U,ui,j)+eta*error*MatrixXd_get_coeff(M,j,ui);                
                MatrixXd_set_coeff(M, j, mi, MatrixXd_get_coeff(M,j,ui)+eta*error*MatrixXd_get_coeff(U,ui,j));
                MatrixXd_set_coeff(U, ui, j, tempU[j]);
            }
        }
        
        if (iteration % ((int) maxIteration / 15) == 0) {
            eta *= 0.8;
            errorHistory[k] = 0;
            MatrixXd_multiply(U,M, aux);

            for(i = 0 ; i < maxUserId ; i++){
                for(j = 0 ; j <maxMovieId ; j++){
                    errorHistory[k] = errorHistory[k] + pow(MatrixXd_get_coeff(W,i,j)*(MatrixXd_get_coeff(A,i,j) - MatrixXd_get_coeff(aux,i,j) ),2);
                }
            }
            k++;
        }
    }

    elapsed = omp_get_wtime() - start;
    printf("elapse: %f\n",elapsed);        
    for ( j = 0; j < k; ++j) {
        printf("error: %f\n", errorHistory[j]);
    }

    Map_MatrixXd_print(aux);

    for(i=0; i < maxUserId ; i++){
        max[i] = 0;
        for(j = 0 ; j< maxMovieId ; j++){
            if(max[i] < MatrixXd_get_coeff(aux,i,j)){
                max[i] = MatrixXd_get_coeff(aux,i,j);
                pel[i] = j;
            }
        }
        printf("Usuario: %d - Pelicula: %d\n",i,pel[i]);
    }

}