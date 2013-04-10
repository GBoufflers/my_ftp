#include	"server.h"

int		my_logout(t_cli **cli)
{
  if (strncmp((*cli)->buff, "logout", 6) == 0)
    {
      puts("a client is leaving");
      return (-1);
    }
  return (0);
}
