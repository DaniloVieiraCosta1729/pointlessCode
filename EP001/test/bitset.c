#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define SET(bitset, position) ((bitset)[(position)/64] |= (1ULL << ((position)%64)))
#define CLEAR(bitset, position) ((bitset)[(position)/64] &= ~(1ULL << ((position)%64)))

int main(int argc, char const *argv[])
{
    uint64_t bitmap[8];
    memset(bitmap, 0xFF, sizeof(bitmap));

    CLEAR(bitmap, 45);
    CLEAR(bitmap, 100);
    CLEAR(bitmap, 430);
    CLEAR(bitmap, 2);
    CLEAR(bitmap, 99);

    for (size_t i = 0; i < 512; i++)
    {
        if ((bitmap[i/64] & (1ULL << i%64)))
        {
            if (i % 120 == 0)
            {
                printf("\n");
            }

            printf("1");
            
        } else
        {
            printf("0");
        }        
    }   

    printf("\n");

    return 0;
}
