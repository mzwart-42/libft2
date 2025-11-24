#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_mod;

	s_mod = s;
	while (n)
	{
		*s_mod = (unsigned char)c;
		++s_mod;
		--n;
	}
	return (s);
}

void	*ft_memchr(const void *s_begin, int c, size_t n)
{
	const unsigned char	*s = s_begin;
	size_t					i;
	
	i = 0;
	while (i < n && s[i] != (unsigned char)c)
		++i;
	if (s[i] == (unsigned char)c)
		return ((void *)&s[i]);
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*m1 = s1;
	const unsigned char	*m2 = s2;
	size_t	i;

	i = 0;
	while (i < n && m1[i] == m2[i])
		++i;
	return (m1[i] - m2[i]);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s = src;
	unsigned char	*d = dest;

	while (n--)
		*d++ = *s++;
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src || n == 0)
		return (dest);
	if (dest < src || (src + n) < dest)
		return(ft_memcpy(dest, src, n));
	while (n)
	{
		*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
		--n;
	}
	return (dest);
}
