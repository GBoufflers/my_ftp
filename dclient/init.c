#include	"client.h"

int		init(t_cli **cli, char *ip, char *port)
{
  if (((*cli) = malloc(sizeof(t_cli))) == NULL)
    return (-1);
  (*cli)->error = 0;
  (*cli)->logged = 0;
  (*cli)->passed = 0;
  if (((*cli)->sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (-1);
  (*cli)->sin.sin_addr.s_addr = inet_addr(ip);
  (*cli)->sin.sin_family = AF_INET;
  (*cli)->sin.sin_port = htons(atoi(port));
  if (((*cli)->path = getenv("PWD")) == NULL)
    return (-1);
  strcat((*cli)->path, "/");
  bzero((*cli)->buff, 1024);
  (*cli)->isleaving = 0;
  return (0);
}
