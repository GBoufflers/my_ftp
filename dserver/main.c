#include	"server.h"

int	handle_client(int cs)
{
  int		cont;
  t_cli		*cli;
  t_passwd	*passwd;

  if ((passwd = get_passwd_file()) == NULL)
    return (-1);
  if (init_cli(&cli, cs) == -1)
    return (-1);
  cont = 0;
  while (1 && cont == 0)
    {
      if (get_message(&cli) == -1)
	cont = -1;
      if (cont != -1)
	if (connection(passwd, &cli) == -1)
	  cont = -1;
      if (cont != -1)
	if (manage_cmd(&cli, &passwd) == -1)
	  cont = -1;      
    }  
  return (0);
}

int	main(int ac, char **av)
{
  t_server		*server;
  int			cfd;

  if (ac != 2)
    {
      puts("argument bitch !");
      return (-1);
    }
  init(&server, atoi(av[1]));
  handle_signal();
  while (42)
    {
      cfd = accept(server->fd, (struct sockaddr *)
		   (&(server->s_in_client)), &(server->s_in_size));
      if (cfd == -1)
	my_exit("error on accept", -1);
      printf("un client se connecte avec sur la socket %d\n", cfd);
      if (fork() == 0)
	handle_client(cfd);
    }
}
