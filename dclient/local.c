#include	"client.h"

int		local(t_cli *cli)
{
  if (strncmp(cli->buff, "lls", 3) == 0)
    {
      if (my_lls(cli->path) == -1)
	return (-1);
    }
  return (0);
}
