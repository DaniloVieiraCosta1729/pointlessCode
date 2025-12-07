/*
    This file will hold all the tools that we will use to solve the problem. Let's solve it in tiny steps.

    note: thinking a little, about the function transf, it's seems an terrible idea to call a function that is going to read an especific address in RAM into an loop, so we will the final solution should have something easer to change, maybe using two registers to hold boxA and boxB or, even better, making it in a way that the gcc could apply some SIMD to make it faster. But, for now, let's make it with pointer to observe how it process of divide something by 2 and adding the result to the box and so forth.
*/

#include <stdio.h>

void transfWithPointer(int * boxA, int * boxB)
{
    if (*boxA % 2 == 0)
    {
        *boxA /= 2;
        *boxB += *boxA;
        return;
    }
    
    *boxB /= 2;
    *boxA += *boxB;
}

void showBoxes(int * a, int * b)
{
    printf("Box A = %d stones;\t\t\tBox B = %d stones;\n", *a, *b);
}

