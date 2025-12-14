/*
    This code tests the bad solution and shows how many iterations it performs to get the answer that could be reached by a human with the invariants concept.
*/

#include <stdio.h>
#include "../header/tools.h"

int main(int argc, char const *argv[])
{
    int iterations = solution();

    printf("Iterations: %d\n", iterations);

    return 0;
}
