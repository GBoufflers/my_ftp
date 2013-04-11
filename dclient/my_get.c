#include	"client.h"

void	get_it(int sock, char file[1024], char *path)
{
  char	buff[1024];
  char	pathfile[1024];
  int	fd;
  int	ret;

  bzero(pathfile, 1024);
  strcat(pathfile, path);
  strcat(pathfile, "/");
  strcat(pathfile, file);
  if ((fd = open(pathfile, O_WRONLY | O_APPEND | O_CREAT, 0644)) != -1)
    {
      bzero(buff, 1024);
      if (read(sock, buff, 1024) == -1)
	my_exit("fail to read on server", -1);
      while (strcmp(buff, "endOfTransmition") != 0)
	{
	  writeInFile(fd, buff);
	  bzero(buff, 1024);
	  if (read(sock, buff, 1024) == -1)
	    my_exit(-1);
	}
    }
}

void	my_get(int sock, char buff[1024], char *path)
{
  char	answer[1024];
  
  if (write(sock, buff, 1024) == -1)
    my_exit();
  bzero(answer, 1024);
  if (read(sock, answer, 1024) == -1)
    my_exit("fail to read on server", -1);
  if (strcmp(answer, "the file does not exist") == 0)
    puts(answer);
  else if (strcmp(answer, "Usage : get <file>") == 0)
    puts(answer);
  else
    get_it(sock, answer, path);
}
