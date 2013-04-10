#include	"client.h"

int		my_logout(t_cli *cli)
{
  char		buff[1024];

  bzero(buff, 1024);
  if (strncmp(cli->buff, "quit", 4) == 0)
    {
      strcpy(buff, "logout");
      write(cli->sock, buff, 1024);
      puts("client is leaving");
      return (-1);
    }
  return (0);
}
