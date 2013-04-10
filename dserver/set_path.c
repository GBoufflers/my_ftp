#include		"server.h"

int			fill_struct(t_cli **cli, char *new, int isPresent)
{
  if (((*cli)->path = strdup(new)) == NULL)
    return (-1);
  if (((*cli)->fileloc = strdup(new)) == NULL)
    return (-1);
  if (((*cli)->checkloc = strdup(new)) == NULL)
    return (-1);
  if (isPresent == 0)
    if (mkdir((*cli)->logtmp, 0741) == -1)
      return (-1);
  if (chdir((*cli)->path) == -1)
    return (-1);
  return (0);
}

int			set_path(t_cli **cli)
{
  char			*new;
  DIR			*rep;
  struct dirent		*readfile;
  int			isPresent;

  rep = NULL;
  readfile = NULL;
  if ((new = getenv("PWD")) == NULL)
    return (-1);
  if ((rep = opendir(new)) == NULL)
    return (-1);
  isPresent = 0;
  while ((readfile = readdir(rep)) != NULL)
    if (strcmp(readfile->d_name, (*cli)->logtmp) == 0)
      {
	isPresent = 1;
	break;
      }
  (*cli)->passwdloc = strdup(new);
  new = strcat(new, "/");
  new = strcat(new, (*cli)->logtmp);
  return (fill_struct(cli, new, isPresent));
}
