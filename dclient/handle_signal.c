#include	"client.h"

void		catch_it(int sig)
{
  puts("use <quit> to leave");
  signal(2, catch_it);
}

int		handle_signal()
{
  signal(2, catch_it);
  return (0);
}
