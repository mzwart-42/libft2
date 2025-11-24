#include "include/libft.h"

// isspace according to man: '\t' '\n' '\v' '\f' '\r' ' '
static int  ft_isspace(int c)
{
  return ((c >= '\t' && c <= '\r') || c == ' ');
}

int ft_atoi(const char *nptr)
{
  int   is_negative;
  long  res;

  res = 0;
  while (ft_isspace(*nptr))
    ++nptr;
  is_negative = (*nptr == '-');
  if (is_negative)
    ++nptr;
  while (ft_isdigit(*nptr))
	{
    res = (res * 10) + ((unsigned char)*nptr - '0');
		nptr++;
	}

  return ((int)res * (-1 * is_negative));
}
