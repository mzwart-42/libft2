#include "libft.h"
#include <stdlib.h>

static size_t	ft_strnlen(const char *str, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (len < maxlen && *str++)
		++len;
	return(len);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_substr;
	char	*substr;

	if (!s || ft_strnlen(s, start + 1) < start + 1)
		return ((char *)s);
	len_substr = ft_strnlen(s + start, len);
	substr = malloc(len_substr + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len_substr + 1);
	return (substr);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t	joined_len;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	joined_len = ft_strlen(s1) + ft_strlen(s2);
	dst = malloc(joined_len + 1);
	if (!dst)
		return (NULL);
	dst[0] = '\0';
	ft_strlcat(dst, s1, joined_len + 1);
	ft_strlcat(dst, s2, joined_len + 1);
	return (dst);
}

char *ft_strtrim(char const *s1, char const *set)
{
	const char	*s1_begin = s1;
	char		*buf_begin;
	size_t		new_len;
	char		*buf;

	new_len = 0;
	while (*s1)
	{
		if (ft_strchr(set, *s1) == NULL)
			++new_len;
		++s1;
	}
	buf = malloc(new_len + 1);
	if (!buf)
		return (NULL);
	buf[new_len] = '\0';
	buf_begin = buf;
	s1 = s1_begin;
	while (*s1)
	{
		if (ft_strchr(set, *s1) == NULL)
			*buf++ = *s1;
		s1++;
	}
	return (buf_begin);
}
