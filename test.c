#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#include <limits.h>

#define CC1 "1234"

int main()
{
  int i;

  // i = ft_atoi("56");

  printf("%i %i\n" , INT_MIN, ft_atoi("    	-2147483648"));
  printf("%i %i\n", atoi(CC1), ft_atoi(CC1));
  return 0;
}
