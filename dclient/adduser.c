#include	"client.h"

int		adduser(t_cli *cli)
{
  char		buff[1024];

  if (strncmp(cli->buff, "adduser", 7) == 0)
    {
      if (cli-buff[7]  != '\0' && cli->buff[7] == ' ')
	{
	  write(cli->sock, cli->buff, 1024);
	  bzero(buff, 1024);
	  read(cli->sock, buff, 1024);
	}
      else
	{
	  bzero(buff, 1024);
	  strcpy(buff, "Usage <adduser login pass>");
	}
      puts(buff);
    }
  return (0);
}
