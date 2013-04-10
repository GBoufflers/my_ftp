#include	"client.h"

void		my_lls(char *path)
{
  DIR			*rep;
  struct dirent		*readfile;

  rep = NULL;
  readfile = NULL;
  puts(path);
  rep = opendir(path);
  if (rep == NULL)
    my_exit("fail on opendir", -1);
  while ((readfile = readdir(rep)) != NULL)
    {
      if (readfile->d_name[0] != '.')
	puts(readfile->d_name);
    }
}
