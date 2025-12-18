/*
    This file will hold all the tools that we will use to solve the problem. Let's solve it in tiny steps.

    note: thinking a little, about the function transf, it's seems an terrible idea to call a function that is going to read an especific address in RAM into an loop, so the final solution should have something easer to cheaper to change its value, maybe using two registers to hold boxA and boxB or, even better, making it in a way that the gcc could apply some SIMD to make it faster. But, for now, let's make it with pointer to observe how it process of divide something by 2 and adding the result to the box and so forth.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BITSET_SIZE 1024
#define WORD_SIZE 64
#define UNSET(bitset, number) ((bitset)[(number)/WORD_SIZE]) &= ~(1ULL << (number)%WORD_SIZE)

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
void transfWithPointerWithoutShift(int * boxA, int * boxB)
{
    if (*boxA % 2 == 0)
    {
        *boxA = *boxA / 2;
        *boxB += *boxA;
        return;
    }
    
    *boxB = *boxB / 2;
    *boxA += *boxB;
}

void showBoxes(int * a, int * b)
{
    printf("Box A = %d stones;\t\t\tBox B = %d stones;\n", *a, *b);
}

// returns the number of iterations for solving the problem. 
int instance_solution(int * a, int * b, void (*transf)(int *, int *)) // bad solution
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
            
            transf(a, b);            
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
        int c = instance_solution(boxA, boxB, transfWithPointerWithoutShift);
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

int solution2()
{
    uint64_t bitset[BITSET_SIZE/WORD_SIZE];

    for (size_t i = 0; i < (BITSET_SIZE/WORD_SIZE); i++)
    {
        bitset[i] = 0xFFFFFFFFFFFFFFFF;
    }    

    uint32_t boxA = 1;
    uint32_t boxB = 1019 - boxA;

    UNSET(bitset, 0);
    for (size_t i = 1018; i < 1024; i++)
    {
        UNSET(bitset, i);
    }
    

    for (size_t i = 0; i < 1000000; i++)
    {
        if (boxA % 2 == 0)
        {
            boxA = boxA >> 1;
            boxB += boxA;

            UNSET(bitset, boxA);
            UNSET(bitset, boxB);

            if (i > 509)
            {
                if (memchr(bitset, 0, BITSET_SIZE/WORD_SIZE) == NULL)
                {
                    return i;
                }
            }

            continue;
            
        }

        boxB = boxB >> 1;
        boxA += boxA;

        UNSET(bitset, boxA);
        UNSET(bitset, boxB);

        if (i > 509)
        {
            if (memchr(bitset, 0, BITSET_SIZE/WORD_SIZE) == NULL)
            {
                return i;
            }
        }
        
    }
    
    printf("1,000,000,000 is not enough iterations to prove by brute force.");

    return 0;

}
