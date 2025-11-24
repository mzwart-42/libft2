#include "libft.h"

char  *ft_strrchr(const char *s_begin, int c)
{
  char  *s;

  s = (char *)s_begin + ft_strlen(s_begin);
  while (s != s_begin && *s != c)
    --s;
  if (*s == c)
    return (s);
  return (NULL);
}
