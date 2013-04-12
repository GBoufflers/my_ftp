#include	"client.h"

int		my_lmkdir(t_cli *cli)
{
  char		**args;

  if (strncmp(cli->buff, "lmkdir", 6) == 0)
    {
      if (cli->buff[6] != '\0' && cli->buff[6] == ' ')
	{
	  cli->buff[strlen(cli->buff) - 1] = '\0';
	  args = totab(cli->buff, ' ');
	  if (getSize(args) == 2)
	    mkdir(args[1], 0744);
	}
    }
  return (0);
}
