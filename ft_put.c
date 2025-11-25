#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	const char	nl = '\n';

	ft_putstr_fd(s, fd);
	write(fd, &nl, 1);
}

static unsigned int	num_len_incl_minus(int n, int base)
{
	unsigned int	len;

	len = (n < 0);
	while (n)
	{
		n /= base;
		++len;
	}
	return (len);
}

#define BASE_10 10
#define NUL_TERM 1
#define MAX_NUM_LEN 11

void	ft_putnbr_fd(int n, int fd)
{
	const size_t	n_len = num_len_incl_minus(n, 10);
	size_t			num_len;
	char			buf[MAX_NUM_LEN + NUL_TERM];

	num_len = n_len;
	buf[num_len] = '\0';
	if (n < 0)
		n *= -1;
	while (n && num_len--)
	{
		buf[num_len] = (n % BASE_10) + '0';
		n /= 10;
	}
	if (num_len)
		buf[0] = '-';
	write(fd, buf, n_len);
}

// int main()
// {
// 	ft_putchar_fd('c',1);
// 	ft_putendl_fd("hello",1);
// 	ft_putnbr_fd(123, 1);
// }
