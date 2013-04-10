#include	"server.h"

int		no_file(t_cli **cli)
{
  if (strncmp(((*cli)->buff), "cd", 2) == 0)
    {
      if (my_cd(cli) == -1)
	return (-1);
    }
  else if (strncmp(((*cli)->buff), "ls", 2) == 0)
    {
      if (my_ls(cli) == -1)
	return (-1);
    }
  else if (strncmp(((*cli)->buff), "pwd", 3) == 0)
    {
      if (my_pwd(cli) == -1)
	return (-1);
    }
  return (0);
}
