#include "libft.h"

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    char    *cmp_little;
    char    *cmp_big;
    size_t  little_len;
    size_t  counter;

    if (!*little)
        return ((char *)big);
    little_len = ft_strlen(little);
    while (*big && len != 0 && (len - little_len) > 0)
    {
        cmp_little = (char *)little;
        cmp_big = (char *)big;
        counter = 0;
        while (counter != little_len && *cmp_big == *cmp_little)
        {
            ++cmp_big;
            ++cmp_little;
            ++counter;
        }
        if (counter == little_len)
            return ((char *)big);
        ++big;
        --len;
    }

    return (NULL);
}

#include <bsd/string.h>
#include <stdio.h>

// #define ARG(...) { __VA_ARGS__ }

// #define INPUT "ARG("strnstr", "", 12)"

int main()
{
    int    len = 0;
    char    *big = "12343";
    char    *little = "12";

    char    *ptr = strnstr(big, little, len);

    char    *me = ft_strnstr(big, little, len);

    printf("%s\n", ptr);
    printf("%s\n", me);

    return 0;
}
