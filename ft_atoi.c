#include "include/libft.h"

// isspace according to man: '\t' '\n' '\v' '\f' '\r' ' '
static int  ft_isspace(int c)
{
  return ((c >= '\t' && c <= '\r') || c == ' ');
}

int ft_atoi(const char *str)
{
  long  res;
  int   is_negative;

  res = 0;
  while (ft_isspace(*str))
    ++str;
  
  is_negative = (*str == '-');
  if (is_negative)
    ++str;

  while (ft_isdigit(*str))
    res = res * 10 + ((unsigned int)(*str++) - '0');

  return ((int)res * (-1 * is_negative));
}
