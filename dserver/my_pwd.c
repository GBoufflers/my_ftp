#include	"server.h"

int		my_pwd(t_cli **cli)
{
  char		buff[1024];

  bzero(buff, 1024);
  strcpy(buff, (*cli)->path);
  if (write((*cli)->cs, buff, 1024) == -1)
    return (-1);
  bzero(buff, 1024);
  return (0);
}
