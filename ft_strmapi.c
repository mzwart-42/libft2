#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_mapi;
	size_t	idx;

	s_mapi = (char *)malloc(ft_strlen(s) + 1);
	if (!s_mapi)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		s_mapi[idx] = f(idx, s[idx]);
		++idx;
	}
	return (s_mapi);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	idx;

	idx = 0;
	while (*s)
	{
		s[idx] = f(idx, s[idx]);
		++idx;
	}
	return (s);
}

static char	*safe_ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	if (!s)
		return (NULL);
	return (ft_strmapi(s, f));
}

#ifdef ARE_YOU_SERIOUS_RIGHT_MEOW
# define ft_strmapi(x) safe_ft_strmapi(x)
#endif

char	func(unsigned int i, char c)
{
	return c + 32;
}

int main()
{
	ft_strmapi("hi", func);
}
