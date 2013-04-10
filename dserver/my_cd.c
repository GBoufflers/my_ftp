#include	"server.h"

int		check_new_path(t_cli **cli)
{
  char		buff[1024];

  bzero(buff, 1024);
  if (strncmp((*cli)->checkloc, (*cli)->path, strlen((*cli)->checkloc)) == 0)
    {
      strcpy(buff, (*cli)->path);
      if (write((*cli)->cs, buff, 1024) == -1)
	{
	  puts("une erreur sur le write bitch !");
	  return (-1);
	}
    }
  else
    {
      if (((*cli)->path = strdup((*cli)->checkloc)) == NULL)
	return (-1);
      strcpy(buff, "Permission denied");
      if (write((*cli)->cs, buff, 1024) == -1)
	{
	  puts("une erreur sur le write bitch !");
	  return (-1);
	}
    }
  return (0);
}

int		do_cd(t_cli **cli, char *new)
{
  int		i;
  char		**dirs;
  char		buff[1024];

  i = 0;
  bzero(buff, 1024);
  if (chdir(new) != -1)
    {
      if (((*cli)->path = realpath(".", NULL)) == NULL)
	return (-1);
      if (check_new_path(cli) == -1)
	return (-1);
    }
  else
    {
      strcat(buff, new);
      strcat(buff, ": ain't a directory");
      if (write((*cli)->cs, buff, 1024) == -1)
	{
	  puts("une erreur sur le write bitch !");
	  return (-1);
	}	
    }
  return (0);
}

int		clean_and_do(t_cli **cli, char *line)
{
  line[strlen(line) - 1] = '\0';
  return (do_cd(cli, line));
}

int		my_cd(t_cli **cli)
{
  char		buff[1024];
  char		**arg;
  int		i;

  i = 0;
  arg = totab((*cli)->buff, ' ');
  if (getSize(arg) != 2)
    {
      strcpy(buff, "cd : usage <cd  Directory>");
      write((*cli)->cs, buff, strlen(buff));
      return;
    }
  return (clean_and_do(cli, arg[1]));
}
