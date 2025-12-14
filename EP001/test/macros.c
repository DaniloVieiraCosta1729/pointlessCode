#include <stdio.h>

#define MOVEFORWARD(x,y) \
    X(x) \
    Y(y)

#define X(x) x++;
#define Y(y) y--;

int main(int argc, char const *argv[])
{
    int x = 0;
    int y = 100;

    printf("=============Increase decrease=============\n");
    printf("\t%d\t\t\t%d\n", x, y);

    for (size_t i = 0; i < 50; i++)
    {
        MOVEFORWARD(x, y)
        printf("\t%d\t\t\t%d\n", x, y);
    }
    

    return 0;
}
