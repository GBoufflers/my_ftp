#include	"client.h"

void		my_cd(int sock, char buff[1024])
{
  if (write(sock, buff, 1024) == -1)
    my_exit("fail to write on server", -1);
  bzero(buff, 1024);
  if (read(sock, buff, 1024) == -1)
    my_exit("fail to read on server", -1);
  else
    puts(buff);
}
