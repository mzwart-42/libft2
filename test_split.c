#include "include/libft.h"
#include <stdio.h>


void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int main(int argc,char **argv)
{

	char **tabstr;
	int	i;

	if (argc == 2)
		tabstr = ft_split(argv[1], ' ');
	if (argc == 3)
		tabstr = ft_split(argv[1], argv[2][0]);

	i = 0;
	if (!(tabstr = ft_split("          ", ' ')))
		ft_print_result("NULL");
	else
	{
		while (tabstr[i] != NULL)
		{
			ft_print_result(tabstr[i]);
			write(1, "\n", 1);
			i++;
		}
	}
}
