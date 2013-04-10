#include	"server.h"

void		my_print(char c)
{
  write(1, &c, 1);
}

void		my_len(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_print('l');
      i++;
    }
  my_print('\n');
}

int		manage_cmd(t_cli **cli)
{
  int		i;
  int		(*funcToCall[4])(struct s_cli **);

  i = 0;
  if ((((*cli)->logaccepted) == 1) && (((*cli)->passaccepted) == 1))
    {
      funcToCall[0] = no_file;
      funcToCall[1] = transfer;
      funcToCall[2] = my_logout;
      funcToCall[3] = adduser;
      while (i < 4)
	{
	  if ((*funcToCall[i])(cli) == -1)
	    return (-1);
	  i++;
	}
    }
  return (0);
}
