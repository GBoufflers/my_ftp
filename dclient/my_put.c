#include	"client.h"

void            send_error(int sock, char *message)
{
  char          buff[1024];

  bzero(buff, 1024);
  strcpy(buff, message);
  if (write(sock, buff, 1024) == -1)
    my_exit("fail to write on server", -1);
}

void            do_send(int sock, char *file, char filelocation[1024], FILE *f)
{
  char          buff[1024];

  bzero(buff, 1024);
  while (fgets(buff, 1024, f) != NULL)
    {
      if (write(sock, buff, 1024) == -1)
	my_exit("fail to write on server", -1);
      bzero(buff, 1024);
    }
  fclose(f);
  bzero(buff, 1024);
  strcpy(buff, "endOfTransmition");
  if (write(sock, buff, 1024) == -1)
    my_exit("fail to write on server", -1);
}

void            send_file(int sock, char buff[1024], char *file, char *path)
{
  char          filelocation[1024];
  FILE          *f;

  f = NULL;
  bzero(filelocation, 1024);
  strcat(filelocation, path);
  strcat(filelocation, "/");
  strcat(filelocation, file);
  puts(filelocation);
  f = fopen(filelocation, "r");
  if (f == NULL)
    {
      puts(filelocation);
      puts("the file does not exist");
      send_error(sock, "the file does not exist");
    }
  else
    {
      if (write(sock, buff, 1024) == -1)
	my_exit("fail to write on server", -1);
      do_send(sock, file, filelocation, f);
    }
}

  void		my_put(int sock, char buff[1024], char *path)
  {
    char          **args;
    int           i;

    i = 0;
    args = totab(buff, ' ');
    if (getSize(args) == 2)
      {
	while (args[1][i] != '\0')
	  {
	    if (args[1][i] == '\n')
	      args[1][i] = '\0';
	    i++;
	  }
	send_file(sock, buff, args[1], path);
      }
    else
      send_error(sock, "Usage : get <file>");
  }
