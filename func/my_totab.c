#include	"../dserver/server.h"

int             getSize(char **t)
{
  int           i;

  i = 0;
  while (t[i] != NULL)
    i++;
  return (i);
}

char		**totab(char str[1024], char c)
{
  char          **tabl;
  int           a;
  int           b;
  int           i;

  i = 0;
  a = 0;
  tabl = malloc((strlen(str) + 1) * sizeof(char *));
  while (str && str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == c)
	i++;
      else
	{
	  b = 0;
	  tabl[a] = malloc(strlen(str) + 1 * sizeof(char));
	  while (str[i] && (str[i] != c))
	    {
	      tabl[a][b] = str[i];
	      b++;
	      i++;
	    }
	  if (str[i] != '\0')
	    i++;
	  tabl[a][b] = '\0';
	  a++;
	}
    }
  tabl[a] = NULL;
  return (tabl);
}
