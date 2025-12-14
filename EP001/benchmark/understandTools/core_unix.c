#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("Number of online processors: %ld\n", sysconf(_SC_NPROCESSORS_ONLN));
    return 0;
}
