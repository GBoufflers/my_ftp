#include	"client.h"

int		check_dir_client(t_cli **cli)
{
  int		isPresent;
  DIR		*rep;
  struct dirent	*readfile;

  rep = NULL;
  readfile = NULL;
  isPresent = 0;
  if ((rep = opendir(realpath(".", NULL))) == NULL)
    return (-1);
  while ((readfile = readdir(rep)) != NULL)
    if (strcmp(readfile->d_name, "dataclient") == 0)
      {
	isPresent = 1;
	break;
      }
  if (isPresent == 0)
    if (mkdir((*cli)->path, 0741) == -1)
      return (-1);
  if (chdir((*cli)->path) == -1)
    return (-1);
  return (0);
}

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
  strcat((*cli)->path, "/dataclient/");
  if (check_dir_client(cli) == -1)
    return (-1);
  bzero((*cli)->buff, 1024);
  (*cli)->isleaving = 0;
  return (0);
}
