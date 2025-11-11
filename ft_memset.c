// #include <string.h>
#include <aio.h>

void    *ft_memset(void *s, int c, size_t n)
{
    void    *original_s;

    original_s = s;
    while (n)
    {
        *(unsigned char *)s = c;
        ++s;
        --n;
    }

    return (original_s);
}
