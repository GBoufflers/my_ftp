#include	"client.h"

void		my_ls(int sock)
{
  char	buff[1024];

  bzero(buff, 1024);
  strcpy(buff, "ls");
  if (write(sock, buff, 1024) == -1)
    my_exit("fail to write on server", -1);
  strcpy(buff, "begin");
  while (strcmp(buff, "endOfTransmition") != 0)
    {
      bzero(buff, 1024);
      if (read(sock, buff, 1024) == -1)
	my_exit("fail to read on server", -1);
      if (strcmp(buff, "endOfTransmition") != 0)
	puts(buff);
    }
}
