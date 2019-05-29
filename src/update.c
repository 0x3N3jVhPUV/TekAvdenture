/*
** update_cmd.c for  in /home/thomas.mikhail/tekadventure/thomas
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Tue Sep 26 20:31:03 2017 Thomas Mikhail
** Last update Sat Oct  7 02:52:15 2017 Thomas Mikhail
*/

#include "my.h"

t_bullet		*update_all(t_disp *disp)
{
  t_elem	*tmp;

  tmp = disp->elems;
  while (tmp != NULL)
    {
      if (tmp->type == 1)
	update_back(tmp, disp);
      else if (tmp->type == 2)
	update_cloud(tmp);
      else if (tmp->type == 3)
	disp->bullets = update_enemies(tmp, disp->bullets, disp);
      tmp = tmp->next;
    }
  if (disp->spr_count_q >= 2)
    disp->spr_count_q = 0;
  update_enemies_bullets(disp->bullets);
  update_bullets(disp->ship->bullets);
  return (disp->bullets);
}

void	update_cloud(t_elem *cloud)
{
  if (cloud->stype == 1.5)
    cloud->x -= 3.3;
  else if (cloud->stype == 1.0)
    cloud->x -= 3.2;
  else if (cloud->stype == 0.5)
    cloud->x -= 3.1;
  if (cloud->x <= -1400)
    cloud->x = 2300;
}

void	update_back(t_elem *back, t_disp *disp)
{
  if (back->x <= 0 && back->stype == 2.0)
    {
      disp->rst1 = 1;
      back->x = 1620;
    }
  if (back->stype == 1.0 && disp->rst1)
    {
      back->x = 0;
      disp->rst1 = 0;
    }
  else if (back->stype != 3.0)
    back->x = back->x - 3.1;
}

sfSprite	*update_sprite_ship(t_ship *ship, t_disp *disp)
{
  sfVector2i    a;
  sfVector2i    b;
  sfVector2i    c;
  sfSprite      *tmp;

  a = vector2i(308, 396);
  b = vector2i(1, 3);
  c = vector2i(disp->spr_count_q, disp->spr_count_r);
  tmp = cut_sprite(ship->sprite, a, b, c);
  return (tmp);
}

void		update_bullets(t_bullet *bullets)
{
  t_bullet     *tmp;

  tmp = bullets;
  while (tmp != NULL)
    {
      tmp->pos.x += tmp->cvelocity.x;
      tmp->pos.y += tmp->cvelocity.y;
      tmp = tmp->next;
    }
}
