#include "libft.h"

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    const size_t  little_len = ft_strlen(little);

    while (*big && len >= little_len)
    {
		if (ft_strncmp(big, little, little_len) == 0)
            return ((char *)big);
        ++big;
        --len;
    }
    return (NULL);
}

// #include <bsd/string.h>
// #include <stdio.h>
//
// // #define ARG(...) { __VA_ARGS__ }
//
// // #define INPUT "ARG("strnstr", "", 12)"
//
// int main()
// {
//     int    len = 1;
//     char    *big = "12343";
//     char    *little = "12";
//
//     printf("hi %s", strnstr("abc", "bc", 2));
//     printf("hi %s", ft_strnstr("abc", "bc", 2));
//
//     char    *me = strnstr(big, little, len);
//
//     // printf("%s\n", me);
//
//     return 0;
// }
