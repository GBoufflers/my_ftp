#include	"server.h"

int		get_message(t_cli **cli)
{
  bzero((*cli)->buff, 1024);
  (*cli)->len = read((*cli)->cs, (*cli)->buff, 1024);
  if ((*cli)->len == -1)
    return (-1);
  (*cli)->buff[(*cli)->len - 1] = '\0';
  return (0);
}
