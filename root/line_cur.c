/*
** line_cur.c for line_cur in /home/debieb_a//Projets/temp3-42sh-bouffl_g
** 
** Made by alexandre debieb
** Login   <debieb_a@epitech.net>
** 
** Started on  Fri May 18 16:15:48 2012 alexandre debieb
** Last update Sat May 19 19:34:48 2012 alexandre debieb
*/

#include "../42SH.h"

int	my_cscreen(void)
{
  char	*tstr;

  tstr = NULL;
  if ((tstr = tgetstr("cl", NULL)) == 0)
    return (-1);
  tputs(tstr, 1, my_tputs);
  my_tputstr("$> ");
  return (0);
}

int	check_key(char *buff, t_term *terms)
{
  if (my_term_cmp(buff, terms->left) == 0)
    return (KLEFT);
  else if (my_term_cmp(buff, terms->up) == 0)
    return (KUP);
  else if (my_term_cmp(buff, terms->down) == 0)
    return (KDOWN);
  else if (my_term_cmp(buff, terms->right) == 0)
    return (KRIGHT);
  else if (my_term_cmp(buff, terms->backsp) == 0)
    return (KBACKSP);
  else if (my_term_cmp(buff, terms->delete) == 0)
    return (KDELETE);
  return (0);
}

int	replace_line(char *cmd)
{
  char	*tstr;

  tstr = NULL;
  if ((tstr = tgetstr("cr", NULL)) == 0)
    return (-1);
  tputs(tstr, 1, my_tputs);
  my_tputstr("$> ");
  my_tputstr(cmd);
  my_tputstr(" \b");
  return (0);
}

int	move_curs_l(t_term *terms, char *cmd)
{
  int	i;

  i = 0;
  if (cmd == NULL)
    return (0);
  if (replace_line(cmd) == -1)
    return (-1);
  while (i < (terms->cur - 1))
    i++;
  while (i < my_tlen(cmd))
    {
      my_tputs('\b');
      i++;
    }
  if (terms->cur > 0)
    (terms->cur)--;
  return (0);
}

int	move_curs_r(t_term *terms, char *cmd)
{
  int	i;

  i = 0;
  if (cmd == NULL)
    return (0);
  if (replace_line(cmd) == -1)
    return (-1);
  while (i <= terms->cur)
    i++;
  while (i < my_tlen(cmd))
    {
      my_tputs('\b');
      i++;
    }
  if (terms->cur < my_tlen(cmd))
    (terms->cur)++;
  return (0);
}
