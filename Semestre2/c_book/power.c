#include <stdio.h>

long power(long base, long pow)
{
    long result = 1;

    for(int i = 0; i < pow; ++i)
        result = result*base;

    return result;
}

int main()
{
    printf("%d ^ %d = %ld\n", 2, 0, power(2,0));
    printf("%d ^ %d = %ld\n", 2, 1, power(2,1));
    printf("%d ^ %d = %ld\n", 2, 5, power(2,5));
    printf("%d ^ %d = %ld\n", 3, 3, power(3,3));
}
