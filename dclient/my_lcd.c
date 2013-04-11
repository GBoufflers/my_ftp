#include	"client.h"

int		my_lcd(t_cli *cli)
{
  char		**args;

  if (strncmp(cli->buff, "lcd", 3) == 0)
    {
      if (cli->buff[3] != '\0' && cli->buff[3] == ' ')
	{
	  cli->buff[strlen(cli->buff) - 1] = '\0';
	  args = totab(cli->buff, ' ');
	  if (getSize(args) == 2)
	    {
	      chdir(args[1]);
	      puts(cli->path);
	      cli->path = realpath(".", NULL);
	      puts(cli->path);
	    }
	}
    }
}
