#include	<stdio.h>
#include	<stdlib.h>

int		my_exit(char *message, int code)
{
  puts(message);
  exit(code);
}
