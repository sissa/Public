#include <stdio.h>

extern int inthash(int, int);

static int next_size(int size)
{
    int val = 1;
    while (val < size) val <<= 1;
    return val;
}

int main(int argc, char **argv)
{
    int i;
    const int keys[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        100, 200, 300, 9854873, 99875412, 1150384, 81785634, -1, -2, -3, -10 };
    const int nkeys = sizeof(keys)/sizeof(int);

    for (i = 0; i < nkeys; ++i) {
        printf(" key:% 12d inthash(% 12d, % 12d) = % 12d\n",
               i+1, keys[i], next_size(1000), inthash(keys[i], next_size(1000)));
    }
    return 0;
}
