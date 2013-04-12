#include	"server.h"

int	init_cli(t_cli **cli, int cs)
{
  if (((*cli) = malloc(sizeof(t_cli))) == NULL)
    return (-1);
  (*cli)->logaccepted = 0;
  (*cli)->passaccepted = 0;
  (*cli)->cs = cs;
  return (0);
}

int	init(t_server **server, int port)
{
  int	ret;

  if (((*server) = malloc(sizeof(t_server))) == NULL)
    return (-1);
  (*server)->s_in_size = sizeof((*server)->s_in_client);
  (*server)->port = port;
  if (((*server)->pe = getprotobyname("TCP")) == NULL)
    return (-1);
  if (((*server)->fd = socket(AF_INET, SOCK_STREAM,
			      (*server)->pe->p_proto)) == -1)
    return (-1);
  (*server)->s_in.sin_family = AF_INET;
  (*server)->s_in.sin_port = htons((*server)->port);
  (*server)->s_in.sin_addr.s_addr = INADDR_ANY;  
  ret = bind((*server)->fd, (const struct sockaddr *)
	     (&((*server)->s_in)), sizeof((*server)->s_in));
  if (ret == -1)
    return (-1);
  ret = listen((*server)->fd, 42);
  if (ret == -1)
    return (-1); 
  return (0);
}
