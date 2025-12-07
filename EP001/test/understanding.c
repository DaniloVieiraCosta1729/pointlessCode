/*
    This file is intended to test the functions and to illustrate how the problem evolves over time.
*/

#include "../header/tools.h"
#include <stdlib.h>

extern int randomD(int n);
void iterations(int n, int * a, int * b);

int main(int argc, char const *argv[])
{
    int * boxA; 
    *boxA = randomD(400);
    int * boxB;
    *boxB = 1019 - *boxA;

    iterations(10, boxA, boxB);

    return 0;
}

void iterations(int n, int * a, int * b)
{
    for (size_t i = 0; i < n; i++)
    {
        transfWithPointer(a, b);
        showBoxes(a, b);
    }
    
}