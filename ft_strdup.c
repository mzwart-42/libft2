#include "libft.h"
#include <stdlib.h>

char *ft_strdup(const char *s)
{
	const size_t	src_len = ft_strlen(s);
	char	*buf;

	buf = malloc(src_len + 1);
	if (!buf)
		return (NULL);
	ft_memcpy(buf, s, src_len + 1);
	return (buf);
}
