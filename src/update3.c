/*
** update3.c for  in /home/afene-_a/tekad/tekadventure/thomas
** 
** Made by andy afene mebaley
** Login   <afene-_a@epitech.net>
** 
** Started on  Sat Sep 30 16:48:41 2017 andy afene mebaley
** Last update Sat Oct  7 02:51:00 2017 Thomas Mikhail
*/

#include "my.h"

t_elem		*update_anim_explosion(t_elem *elems)
{
  elems->a = vector2i(900, 900);
  elems->b = vector2i(8, 8);
  elems->spr_count_s++;
  if (elems->spr_count_s == 0)
    {
      elems->spr_count_s = 0;
      elems->spr_count_t++;
    }
  if (elems->spr_count_t == 9)
    {
      elems->spr_count_t = 0;
      elems->a = vector2i(312, 384);
      elems->b = vector2i(1, 3);
      elems->dead = 1;
    }
  return (elems);
}

void	update_explosion_ship(t_ship *elems)
{
  sfVector2i	c;

  elems->a = vector2i(900, 900);
  elems->b = vector2i(8, 8);
  elems->spr_count_s++;
  if (elems->spr_count_s == 0)
    {
      elems->spr_count_s = 0;
      elems->spr_count_t++;
    }
  if (elems->spr_count_t == 9)
    {
      elems->spr_count_t = 0;
      elems->a = vector2i(312, 384);
      elems->b = vector2i(1, 3);
      elems->dead = 1;
    }
  c = vector2i(elems->spr_count_t, elems->spr_count_s);
  elems->sprite = cut_sprite(elems->sprite, elems->a, elems->b, c);
}

void		update_anim_ship(t_disp *disp)
{
  disp->spr_count_q++;
  if (disp->spr_count_q == 2)
    {
      disp->spr_count_q = 0;
      disp->spr_count_r++;
    }
  if (disp->spr_count_r == 4)
    disp->spr_count_r = 0;
}

void	update_animation_test(t_ship *elems)
{
  if (elems->i != 1 && elems->spr)
    {
      elems->spr_count_s++;
      if (elems->spr_count_s >= 3)
	{
          elems->spr_count_s = 0;
          elems->spr_count_t++;
	}
      if (elems->spr_count_t >= 2)
        elems->spr_count_t = 0;
      elems->spr = 0;
    }
  else if (elems->i != 1 && elems->spr == 0)
    elems->spr = 1;
  else
    update_explosion_ship(elems);
}

void	update_animation(t_elem *elems)
{
  if (elems->i != 1 && elems->spr)
    {
      elems->spr_count_s++;
      if (elems->spr_count_s >= 3)
	{
	  elems->spr_count_s = 0;
	  elems->spr_count_t++;
	}
      if (elems->spr_count_t >= 2)
	elems->spr_count_t = 0;
      elems->spr = 0;
    }
  else if (elems->i != 1 && elems->spr == 0)
    elems->spr = 1;
  else
    {
      elems = update_anim_explosion(elems);
      elems->fire = -1000;
      elems->dead++;
    }
}
