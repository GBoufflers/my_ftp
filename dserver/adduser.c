#include	"server.h"

void		do_add(t_cli **cli, char *login, char *pass)
{
  char		pathfile[1024];
  char		buff[1024];
  char		*line;
  int		fd;

  bzero(pathfile, 1024);
  strcpy(pathfile, (*cli)->passwdloc);
  strcat(pathfile, "/passwd");
  fd = open(pathfile,  O_RDWR | O_CREAT | O_APPEND, 0644);
  line = strdup(login);
  strcat(line, "\t\t");
  strcat(line, pass);
  puts(line);
  write(fd, line, strlen(line));
  bzero(buff, 1024);
  strcpy(buff, login);
  strcat(buff, " has correctly been added to passwd");
  write((*cli)->cs, buff, 1024);
}

int		adduser(t_cli **cli)
{
  char		buff[1024];
  char		**args;

  if (strncmp((*cli)->buff, "adduser", 7) == 0)
    {
      args = totab((*cli)->buff, ' ');
      bzero(buff, 1024);
      if (getSize(args) == 3)
	do_add(cli, args[1], args[2]);
      else
	{
	  strcpy(buff, "Usage <adduser login pass>");
	  write((*cli)->cs, buff, 1024);
	}
    }
  return (0);
}
