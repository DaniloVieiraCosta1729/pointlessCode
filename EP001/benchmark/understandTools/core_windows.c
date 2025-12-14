#include <windows.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    SYSTEM_INFO s;

    GetSystemInfo(&s);

    printf("Number of online processors: %lu\n", s.dwNumberOfProcessors);

    return 0;
}
