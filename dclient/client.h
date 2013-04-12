#ifndef			__CLIENT_H__
#define			__CLIENT_H__

#include	<fcntl.h>
#include	<signal.h>
#include	<limits.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<sys/stat.h>
#include	<netdb.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<unistd.h>
#include	<dirent.h>

typedef struct sockaddr SOCKADDR;
typedef struct sockaddr_in SOCKADDR_IN;

typedef struct	s_cli
{
  int		isleaving;
  int		error;
  int		sock;
  int		logged;
  int		passed;
  SOCKADDR_IN	sin;
  char		buff[1024];
  char		*path;
}		t_cli;

char			**totab(char str[1024], char c);
int			local(t_cli *cl);
int			no_file(t_cli *cli);
int			transfer(t_cli *cli);
int			secu(t_cli *cli);
int			my_logout(t_cli *cli);
int			adduser(t_cli *cli);
int			my_lpwd(t_cli *cli);
int			my_lcd(t_cli *cli);
int			my_lmkdir(t_cli *cli);

#endif
