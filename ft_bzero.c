#include <stddef.h>

void    bzero(void *s, size_t n)
{
    while (n)
    {
        *(unsigned char *)s = 0;
        ++s;
        --n;
    }
}
