// TODO: change to extern fn after finishing project
static size_t	ft_strnlen(const char *str, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (len < maxlen && *str)
		++len;
	return(len);
}

// NOTE: could be faster
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const size_t	dst_len = ft_strlen(dst);
	
	if (size <= dst_len + 1)
		return(dst_len + size);
	ft_memcpy(dst + dst_len, src, ft_strnlen(src, size - dst_len - 1));
	dst[size] = '\0';
	return(dst_len + ft_strlen(src));
}
	// size -= dst_len + 1;
	// ft_strlcpy(dst + dst_len, src, ft_strnlen(src, size - dst_len - 1) + 1);
