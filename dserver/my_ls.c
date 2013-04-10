#include	"server.h"

int		cut_it(t_cli **cli)
{
  int		i;

  i = 0;
  while ((*cli)->path[i] != '\0')
    {
      if ((*cli)->path[i] == '\n')
	(*cli)->path[i]	= '\0';
      i++;
    }
}

int		my_size(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      putchar(str[i]);
      i++;
    }
}

int		my_ls(t_cli **cli)
{
  char			buff[1024];
  DIR			*rep;
  struct dirent		*readfile;

  rep = NULL;
  readfile = NULL;
  if ((rep = opendir((*cli)->path)) == NULL)
    {
      perror("opendir");
      return (-1);
    }
  cut_it(cli);
  while ((readfile = readdir(rep)) != NULL)
    if (readfile->d_name[0] != '.')
      {
	bzero(buff, 1024);
	strcat(buff, readfile->d_name);
	if (write((*cli)->cs, buff, 1024) == -1)
	  return (-1);
      }
  bzero(buff, 1024);
  strcpy(buff, "endOfTransmition");
  if (write((*cli)->cs, buff, 1024) == -1)
    return (-1);
  return (0);
}
