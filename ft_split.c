#include "libft.h"
#include <stdlib.h>
#define NUL_TERM 1

static	size_t	count_words(const char *s, char delim)
{
	char	*next_delim;
	size_t	word_count;

	if (delim == '\0')
		return (1);
	word_count = 0;
	next_delim = (char *)s;
	while (next_delim)
	{
		s = next_delim;
		while (*s == delim)
			++s;
		if (*s)
			word_count++;
		next_delim = ft_strchr(s, delim);
	}
	return (word_count);
}

static size_t	count_delims(const char *str, int c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			++count;
		++str;
	}
	return (count);
}

static size_t	ft_strnlen(const char *str, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (len < maxlen && *str++)
		++len;
	return(len);
}

char	**ft_split(char const *s, char c)
{
	const size_t	word_count = count_words(s, c);
	char			**array;
	char			*word_dst;
	size_t			word_idx;
	size_t			word_len;

	if (!s)
		return (NULL);
	array = ft_calloc(1, (word_count + 1) * sizeof(char *) + \
		(ft_strlen(s) - count_delims(s, c) + (NUL_TERM * word_count)));
	if (!array)
		return (NULL);
	word_dst = (char *)(array + ((word_count + 1) * sizeof(char *)));
	word_idx = 0;
	while (word_idx < word_count)
	{
		while (*s == c)
			++s;
		word_len = ft_strnlen(s, ft_strchr(s, c) - s);
		ft_strlcpy(word_dst, s, word_len + 1);
		array[word_idx++] = word_dst;
		word_dst += (word_len + 1);
		s += word_len;
	}
	return (array);
}

// int main(int argc, char **argv)
// {
// 	char **array;
// 	if (argc == 2)
// 		array = ft_split(argv[argc - 1], ' ');
// 	free(array);
// 	return 0;
// }
