#include	"client.h"

int		transfer(t_cli *cli)
{
  if (strncmp(cli->buff, "put", 3) == 0)
    {
      if (my_put(cli->sock, cli->buff, cli->path) == -1)
	return (-1);
    }
  else if (strncmp(cli->buff, "get", 3) == 0)
    {
      if (my_get(cli->sock, cli->buff, cli->path) == -1)
	return (-1);
    }
  return (0);
}
