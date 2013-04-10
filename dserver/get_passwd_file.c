#include	"server.h"

t_passwd	*add_user_in_list(t_passwd *list, char *login, char *pass)
{
  t_passwd	*new;

  if ((new = malloc(sizeof(t_passwd))) == NULL)
    return (NULL);
  if ((new->login = strdup(login)) == NULL)
    return (NULL);
  if (pass[strlen(pass) - 1] == '\n')
    pass[strlen(pass) - 1] = '\0';
  if ((new->pass = strdup(pass)) == NULL)
    return (NULL);
  new->next = list;
  return (new);
}

void		display(t_passwd *list)
{
  while (list != NULL)
    {
      puts(list->login);
      puts(list->pass);
      list = list->next;
    }
}

t_passwd	*get_passwd_file()
{
  t_passwd	*new;
  char		**info;
  char		string[1024];
  FILE		*file;

  new = NULL;
  file = fopen("passwd", "r+");
  if (file != NULL)
    {
      while (fgets(string, 1024, file) != NULL)
	{
	  info = totab(string, '\t');
	  if ((new = add_user_in_list(new, info[0], info[1])) == NULL)
	    return (NULL);
	}
      if (fclose(file) == -1)
	return (NULL);
    }
  if ((new = add_user_in_list(new, ROOT, PASS)) == NULL)
    return (NULL);
  return (new);
}
