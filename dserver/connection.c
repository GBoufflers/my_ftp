#include	"server.h"

int	check_log(int cs, t_passwd *list, char login[1024])
{
  char		err[1024];
  char		ok[1024];
  t_passwd	*passwd;

  bzero(err, 1024);
  bzero(ok, 1024);
  strcpy(err, "ko");
  strcpy(ok, "ok");
  passwd = list;
  login[strlen(login) - 1] = '\0';
  while (passwd != NULL)
    {
      if (strcmp(login, passwd->login) == 0)
	{
	  if (write(cs, ok, 1024) == -1)
	    return (-1);
	  return (1);
	}
      passwd = passwd->next;
    }
  write(cs, err, 1024);
  return (0);
}

int	check_pass(int cs, t_passwd *list, char login[1024], char pass[1024])
{
  char		err[1024];
  char		ok[1024];
  t_passwd	*passwd;

  bzero(err, 1024);
  bzero(ok, 1024);
  strcpy(err, "ko");
  strcpy(ok, "ok");
  passwd = list;
  pass[strlen(pass) - 1] = '\0';
  while (passwd != NULL)
    {
      if (strcmp(login, passwd->login) == 0)
	if (strcmp(pass, passwd->pass) == 0)
	  {
	    if (write(cs, ok, 1024) == -1)
	      return (-1);
	    return (1);
	  }
      passwd = passwd->next;
    }
  if (write(cs, err, 1024) == -1)
    return (-1);
  return (0);
}

int	connection(t_passwd *passwd, t_cli **cli)
{
  if ((*cli)->logaccepted == 0)
    {
      (*cli)->logaccepted = check_log((*cli)->cs, passwd, (*cli)->buff);
      if ((*cli)->logaccepted == -1)
	return (-1);
      else if ((*cli)->logaccepted == 1)
	(*cli)->logtmp = strdup((*cli)->buff);
    }
  else if ((((*cli)->logaccepted) == 1) && (((*cli)->passaccepted) == 0))
    {
      (*cli)->passaccepted = check_pass((*cli)->cs, passwd,
					(*cli)->logtmp, (*cli)->buff);
      if ((*cli)->passaccepted == -1)
	return (-1);
      else if ((*cli)->passaccepted == 1)
	set_path(cli);
    }
  return (0);
}
