#ifndef		__SERVER_H__
#define		__SERVER_H__

#include	<fcntl.h>
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
#include	<limits.h>

#define	ROOT	"root"
#define PASS	"pass"

typedef struct	s_server
{
  struct protoent	*pe;
  struct sockaddr_in	s_in;
  struct sockaddr_in	s_in_client;
  int			fd;
  int			port;
  socklen_t		s_in_size;
  fd_set		readfds;
}		t_server;

typedef struct		s_passwd
{
  char			*login;
  char			*pass;
  struct s_passwd	*next;
}			t_passwd;

typedef struct		s_cli
{
  int			cs;
  char			*path;
  char			*fileloc;
  char			*checkloc;
  char			*logtmp;
  char			*passwdloc;
  char			buff[1024];
  int			len;
  int			logaccepted;
  int			passaccepted;
}			t_cli;

t_passwd		*get_passwd_file();
char			**totab(char str[1024], char c);
int			no_file(t_cli **cli);
int			transfer(t_cli **cli);
int			secu(t_cli **cli);
int			my_logout(t_cli **cli);
int			adduser(t_cli **cli);

#endif
