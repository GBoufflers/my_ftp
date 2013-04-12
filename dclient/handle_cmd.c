#include	"client.h"

int		handle_cmd(t_cli *cli)
{
  int		(*funcToCall[8])(struct s_cli *);
  int		i;
  int		ret;

  i = 0;
  my_puts("<3 ");
  bzero(cli->buff, 1024);
  funcToCall[0] = no_file;
  funcToCall[1] = local;
  funcToCall[2] = transfer;
  funcToCall[3] = my_logout;
  funcToCall[4] = adduser;
  funcToCall[5] = my_lpwd;
  funcToCall[6] = my_lcd;
  funcToCall[7] = my_lmkdir;
  ret = read(0, cli->buff, 1024);
  if (ret == -1)
    return (-1);
  while (i < 8)
    {
      if ((*funcToCall[i])(cli) == -1)
	return (-1);
      i++;
    }
  return (0);
}
