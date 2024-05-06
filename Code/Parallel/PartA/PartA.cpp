/* Importing the iostream library. */
#include <iostream>
/* Importing the OpenMP library. */
#include <omp.h>

/**
 * the main c++ library
 */
int main(){
 /* Declaring a variable called a and setting it to 0. */
    int a = 0;
    /* Setting the schedule type to static and the chunk size to 1. */
    #pragma omp parallel for schedule(static, 1)
   /* A for loop that is going to run 10 times. */
    for(int i = 0; i < 10; i++){
        /* Setting the value of a to the value of i. */
        a = i;
        /* Printing the value of a to the console. */
        std::cout << a << std::endl;
    }
    /* Returning the value 0 to the main function. */
    return 0;
}
