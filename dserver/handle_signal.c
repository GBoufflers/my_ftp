#include        "server.h"

void            catch_it(int sig)
{
  puts("you can not kill the server");
  signal(2, catch_it);
}

int             handle_signal()
{
  signal(2, catch_it);
  return (0);
}
