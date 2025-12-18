#include <stdio.h>
#include <time.h>
#include "../../header/tools.h"

#define NANO 1e9

int main(int argc, char const *argv[])
{
    struct timespec begin, end;

    double timeRunning;

    clock_gettime(CLOCK_MONOTONIC, &begin);

    solution2();

    clock_gettime(CLOCK_MONOTONIC, &end);

    timeRunning = (double)(end.tv_sec - begin.tv_sec) + (double)(end.tv_nsec - begin.tv_nsec)/(double)NANO;

    printf("Time: %f\n", timeRunning);

    return 0;
}
