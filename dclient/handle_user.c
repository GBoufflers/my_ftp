#include	"client.h"

int		manage_login(t_cli *cli)
{
  my_puts("login :");
  bzero(cli->buff, 1024);
  if (read(0, cli->buff, 1024) == -1)
    return (-1);
  xwrite(cli->sock, cli->buff, 1024);
  bzero(cli->buff, 1024);
  if (read(cli->sock, cli->buff, 1024) == -1)
    return (-1);
  if (strcmp(cli->buff, "ok") == 0)
    cli->logged = 1;
  return (0);
}

int		manage_pass(t_cli *cli)
{
  bzero(cli->buff, 1024);
  my_puts("password :");
  if (read(0, cli->buff, 1024) == -1)
    return (-1);
  xwrite(cli->sock, cli->buff, 1024);
  bzero(cli->buff, 1024);
  if (read(cli->sock, cli->buff, 1024) == -1)
    return (-1);
  if (strcmp(cli->buff, "ok") == 0)
    cli->passed = 1;
  return (0);
}

int		handle_user(t_cli *cli)
{

  if (cli->logged == 0)
    {
      if (manage_login(cli) == -1)
	return (-1);
    }
  else
    if (manage_pass(cli) == -1)
      return (-1);
  return (0);
}
