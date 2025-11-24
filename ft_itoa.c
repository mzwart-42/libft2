#include <stdlib.h>
#include "libft.h"

static int	is_negative(int n)
{
	return (n < 0);
}

static unsigned int	num_len_incl_minus(int n, int base)
{
	unsigned int	len;

	len = is_negative(n);
	while (n)
	{
		n /= base;
		++len;
	}
	return (len);
}

#define BASE_10 10
#define NUL_TERM 1

char	*ft_itoa(int n)
{
	size_t	num_len;
	char *buf;

	num_len = num_len_incl_minus(n, 10);
	buf = malloc(num_len + NUL_TERM);
	if (!buf)
		return (NULL);
	if (is_negative(n))
		n *= -1;
	buf[num_len] = '\0';
	while (n && num_len--)
	{
		buf[num_len] = (n % BASE_10) + '0';
		n /= 10;
	}
	if (num_len)
		buf[0] = '-';
	return (buf);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*s;
	if (argc >= 2)
	{
		s = ft_itoa(ft_atoi(argv[1]));
		printf("\n%s", s);
		free(s);

		s = ft_itoa(atoi(argv[1]));
		printf("\n%s", s);
		free(s);
	}
}
