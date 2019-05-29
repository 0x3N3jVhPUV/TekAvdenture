/*
** score.c for  in /home/thomas.mikhail/tekadventure/thomas
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Sat Oct  7 00:07:50 2017 Thomas Mikhail
** Last update Sat Oct  7 04:30:13 2017 Thomas Mikhail
*/

#include "my.h"

t_score		*init_score(t_disp *disp)
{
  t_score	*tmp;

  tmp = malloc(sizeof(t_score));
  tmp->pos_score.x = 430;
  tmp->pos_score.y = 25;
  tmp->pos_best.x = 435;
  tmp->pos_best.y = 0;
  tmp->font = sfFont_createFromFile(FONT);
  tmp->score = sfText_create();
  tmp->best = sfText_create();
  tmp->nb = 0;
  disp->best = 0;
  return (tmp);
}

void	display_score(t_disp *disp, t_score *s)
{
  sfText_setString(s->best, my_str_cat("BEST ", int_to_str(disp->best)));
  sfText_setString(s->score, my_str_cat("SCORE ", int_to_str(disp->nbr_kill)));
  sfText_setFont(s->score, s->font);
  sfText_setFont(s->best, s->font);
  sfText_setColor(s->score, sfRed);
  sfText_setColor(s->best, sfRed);
  sfText_setCharacterSize(s->best, 15);
  sfText_setCharacterSize(s->score, 15);
  sfText_setPosition(s->score, s->pos_score);
  sfText_setPosition(s->best, s->pos_best);
  sfRenderWindow_drawText(disp->window, s->best, NULL);
  sfRenderWindow_drawText(disp->window, s->score , NULL);
}

char	*int_to_str(int nbr)
{
  int   size;
  int   tmp;
  int	nb;
  char  *res;

  nb = nbr;
  tmp = nbr;
  size = 0;
  while (nb > 9)
    {
      size++;
      nb = nb / 10;
    }
  size++;
  res = malloc(sizeof(char) * (size + 1));
  my_putnbr(tmp, res, 0);
  res[size] = '\0';
  return (res);
}

void	my_putnbr(int nb, char *s, int size)
{
  char  c;

  if (nb > 9)
    {
      my_putnbr(nb / 10, s, size++);
      my_putnbr(nb % 10, s, size);
    }
  else
    {
      c = nb + 48;
      s[size] = c;
    }
}
