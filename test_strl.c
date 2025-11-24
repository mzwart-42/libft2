#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

// int main()
// {
// 	char	*buf = malloc(30);
// 	char	*a = "abc";
//
// 	printf("%i\n", strlcpy(buf, a, 3));
// 	printf(buf);
//
// }


#define LENGTH 20


int main()
{
	char	*buf = malloc(LENGTH);
	char	*a = "abc";

	ft_memset(buf, 0, LENGTH);
	printf("%i\n", ft_strlcat(buf, a, 4));
	printf("%i\n", ft_strlcat(buf, a, 6));
	printf(buf);

	printf("\n");
	ft_memset(buf, 1, LENGTH);
	printf("%i\n", strlcpy(buf, a, 1));
for (int i = 0; i < LENGTH; i++) {
    printf("%02x ", buf[i]);
}
}
