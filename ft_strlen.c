// #include <string.h>
#include <unistd.h>

size_t  ft_strlen(const char *str)
{
    size_t  len;

    len = 0;
    while (*str++)
        ++len;
    return len;
}

// int main()
// {
//     char *hello = "hoolllo";

//     return(ft_strlen(hello));
// }