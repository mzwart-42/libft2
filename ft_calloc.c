#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	const size_t total = nmemb * size;
	char	*buf;

	if (total / nmemb != size)
		return (NULL);
	buf = malloc(total);
	if (!buf)
		return (NULL);
	ft_bzero(buf, total);
	return (buf);
}
