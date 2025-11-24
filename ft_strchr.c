#include <stddef.h>

char *ft_strchr(const char *s, int c)
{
  while (*s && *s != c)
    ++s;
  if (*s == c)
    return ((char *)s);
  return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n && *s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
