#include	"server.h"

int		send_error(int sock, char *message)
{
  char		buff[1024];

  bzero(buff, 1024);
  strcpy(buff, message);
  if (write(sock, buff, 1024) == -1)
    return (-1);
  return (0);
}

int		do_send(t_cli **cli, char *file, char filelocation[1024], FILE *f)
{
  char		buff[1024];

  bzero(buff, 1024);
  strcpy(buff, file);
  if (write((*cli)->cs, buff, 1024) == -1)
    return (-1);
  while (fgets(buff, 1024, f) != NULL)
    {
      if (write((*cli)->cs, buff, 1024) == -1)
	return (-1);
      bzero(buff, 1024);
    }
  if (fclose(f) == -1)
    return (-1);
  bzero(buff, 1024);
  strcpy(buff, "endOfTransmition");
  if (write((*cli)->cs, buff, 1024) == -1)
    return (-1);
  return (0);
}

int		send_file(t_cli **cli, char *file)
{
  char		filelocation[1024];
  FILE		*f;

  f = NULL;
  bzero(filelocation, 1024);
  strcat(filelocation, (*cli)->path);
  strcat(filelocation, "/");
  strcat(filelocation, file);
  if ((f = fopen(filelocation, "r")) == NULL)
    return (send_error((*cli)->cs, "the file does not exist"));
  return (do_send(cli, file, filelocation, f));
}

int		my_get(t_cli **cli)
{
  char		**args;
  int		i;

  i = 0;
  args = totab((*cli)->buff, ' ');
  if (getSize(args) == 2)
    {
      while (args[1][i] != '\0')
	{
	  if (args[1][i] == '\n')
	    args[1][i] = '\0';
	  i++;
	}
      return (send_file(cli, args[1]));
    }
  else
    return (send_error((*cli)->cs, "Usage : get <file>"));
}
