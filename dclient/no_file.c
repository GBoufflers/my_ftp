#include	"client.h"

int		no_file(t_cli *cli)
{
  if (strncmp(cli->buff, "cd", 2) == 0)
    {
      if (my_cd(cli->sock, cli->buff) == -1)
	return (-1);
    }
  else if (strncmp(cli->buff, "pwd", 3) == 0)
    {
      if (my_pwd(cli->sock) == -1)
	return (-1);
    }
  else if (strncmp(cli->buff, "ls", 2) == 0)
    {
      if (my_ls(cli->sock) == -1)
	return (-1);
    }
  return (0);
}
