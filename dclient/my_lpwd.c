#include	"client.h"

int		my_lpwd(t_cli *cli)
{
  if (strncmp(cli->buff, "lpwd", 4) == 0)
    puts(realpath(".", NULL));
}
