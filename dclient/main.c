#include	"client.h"

int		main(int ac, char **av)
{
  int		ret;
  t_cli		*cli;
  
  if (ac == 3)
    {
      if (init(&cli, av[1], av[2]) == -1)
	return (-1);
      ret = connect(cli->sock, (SOCKADDR *)&cli->sin, sizeof(cli->sin));
      if (ret == -1)
	return (-1);
      puts("connecte au server");
      while (1)
	{
	  if (handle_signal() == -1)
	    return (-1);
	  if (cli->logged == 1 && cli->passed == 1)
	    {
	      if (handle_cmd(cli) == -1)
		return (-1);
	    }
	  else
	    if (handle_user(cli) == -1)
	      return (-1);
	}
    }
}
