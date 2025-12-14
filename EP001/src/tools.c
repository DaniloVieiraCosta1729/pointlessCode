/*
    This file will hold all the tools that we will use to solve the problem. Let's solve it in tiny steps.

    note: thinking a little, about the function transf, it's seems an terrible idea to call a function that is going to read an especific address in RAM into an loop, so the final solution should have something easer to cheaper to change its value, maybe using two registers to hold boxA and boxB or, even better, making it in a way that the gcc could apply some SIMD to make it faster. But, for now, let's make it with pointer to observe how it process of divide something by 2 and adding the result to the box and so forth.
*/

#include <stdio.h>
#include <stdlib.h>

void transfWithPointer(int * boxA, int * boxB)
{
    if (*boxA % 2 == 0)
    {
        *boxA = *boxA >> 1;
        *boxB += *boxA;
        return;
    }
    
    *boxB = *boxB >> 1;
    *boxA += *boxB;
}

void showBoxes(int * a, int * b)
{
    printf("Box A = %d stones;\t\t\tBox B = %d stones;\n", *a, *b);
}

// returns the number of iterations for solving the problem. 
int instance_solution(int * a, int * b) // bad solution
{
    int iterations = 0;
    for (size_t k = 1; k < 1019; k++)
    {
        for (size_t i = 0; i < 1000000; i++)
        {
            iterations++;
            if ((*a == k) || (*b == k))
            {
                break;
            }
            if (i == 999999)
            {
                printf("More than 1000000 iterations without confirming the statement of the problem.\n");
                printf("Box A: %d;\nBox B: %d\n", *a, *b);
                return -1;
            }
            
            transfWithPointer(a, b);            
        }
        
    }  
    
    return iterations;


}

#define MOVEFORWARD(x,y) \
    X(x) \
    Y(y)

#define X(x) x++;
#define Y(y) y--;

int solution()
{
    int total_iterations = 0;

    int * boxA = (int *)malloc(sizeof(int));
    int * boxB = (int *)malloc(sizeof(int));

    int a = 1;
    int b = 1019 - a;

    *boxA = 1;
    *boxB = 1019 - *boxA;

    while (*boxA < 510)
    {
        int c = instance_solution(boxA, boxB);
        if (c == -1)
        {
            free(boxA);
            free(boxB);
            return -1;
        }
        
        total_iterations += c;
        MOVEFORWARD(a,b)
        *boxA = a;
        *boxB = b;
    }

    printf("Box A: %d;\nBox B: %d\n",*boxA, *boxB);
    free(boxA);
    free(boxB);

    return total_iterations;
   
}
