#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const size_t	src_len = ft_strlen(src);
	size_t	actual_coppied_len;

	if (!size)
		return (src_len);
	if (src_len + 1 > size)
		actual_coppied_len = size - 1;
	else
		actual_coppied_len = src_len;
	ft_memcpy(dst, src, actual_coppied_len);
	ft_bzero(dst + actual_coppied_len, size - actual_coppied_len);
	return (src_len);
}
