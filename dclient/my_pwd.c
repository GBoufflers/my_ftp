#include	"client.h"

void		my_pwd(int sock)
{
  char	buff[1024];

  bzero(buff, 1024);
  strcpy(buff, "pwd");
  if (write(sock, buff, 1024) == -1)
    my_exit("fail to write on server", -1);
  bzero(buff, 1024);
  if (read(sock, buff, 1024) == -1)
    my_exit("fail to read on server", -1);
  puts(buff);
  bzero(buff, 1024);
}
