
#include	"server.h"

int		writeInFile(int fd, char buff[1024])
{
  int   i;

  i = 0;
  while (buff[i] != '\0')
    {
      if (write(fd, &buff[i], 1) == -1)
	return (-1);
      i++;
    }
  return (0);
}

int		do_put(int fd, t_cli **cli)
{
  char		buff[1024];
  
  bzero(buff, 1024);
  if (read((*cli)->cs, buff, 1024) == -1)
    return (-1);
  while (strcmp(buff, "endOfTransmition") != 0)
    {
      if (writeInFile(fd, buff) == -1)
	return (-1);
      bzero(buff, 1024);
      if (read((*cli)->cs, buff, 1024) == -1)
	return (-1);
    }
  return (0);
}

int		my_put(t_cli **cli)
{
  char		buff[1024];
  char		pathfile[1024];
  int		fd;
  int		i;
  char		**name;

  i = 0;
  name = totab((*cli)->buff, ' ');
  bzero(pathfile, 1024);
  strcat(pathfile, (*cli)->fileloc);
  strcat(pathfile, "/");
  strcat(pathfile, name[1]);
  while (pathfile[i] != '\0')
    {
      if (pathfile[i] == '\n')
	pathfile[i] = '\0';
      i++;
    }
  fd = open(pathfile, O_WRONLY | O_APPEND | O_CREAT, 0644);
  if (fd == -1)
    return (-1);
  return (do_put(fd, cli));
}
