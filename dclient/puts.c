#include	"client.h"

void		my_puts(char *str)
{
  if (write(1, str, strlen(str)) == -1)
    my_exit("error on write", -1);
}

void		writeInFile(int fd, char buff[1024])
{
  int	i;

  i = 0;
  while (buff[i] != '\0')
    {
      if (write(fd, &buff[i], 1) == -1)
	my_exit("error to write on fd", -1);
      i++;
    }
}
