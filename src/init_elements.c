/*
** init_elements.c for  in /home/thomas.mikhail/tekadventure/thomas
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Tue Sep 26 20:40:23 2017 Thomas Mikhail
** Last update Sat Oct  7 10:56:50 2017 Thomas Mikhail
*/

#include "my.h"

t_ship		*init_ship(float x, float y, char *path, float stype)
{
  t_ship	*tmp;

  if (!(tmp = malloc(sizeof(t_ship))))
    return (NULL);
  if (!(tmp->sprite = init_sprite_ship(path, tmp)))
    return (NULL);
  tmp->x = x;
  tmp->y = y;
  tmp->stype = stype;
  tmp->bullets = NULL;
  tmp->a.x = 0;
  tmp->a.y = 0;
  tmp->b.x = 0;
  tmp->b.y = 0;
  tmp->i = 0;
  tmp->spr = 0;
  tmp->dead = 0;
  tmp->spr_count_t = 0;
  tmp->spr_count_r = 0;
  tmp->spr_count_s = 0;
  tmp->att_speed = 20;
  return (tmp);
}

t_elem		*init_cloud(float x, float y, char *path, float stype)
{
  t_elem	*tmp;

  if (!(tmp = malloc(sizeof(t_elem))))
    return (NULL);
  tmp->sprite= init_sprite(path, tmp);
  tmp->x = x;
  tmp->y = y;
  tmp->type = 2;
  tmp->stype = stype;
  return (tmp);
}

t_elem		*init_back(float x, float y, char *path, float stype)
{
  t_elem	*tmp;

  if (!(tmp = malloc(sizeof(t_elem))))
    return (NULL);
  tmp->sprite = init_sprite(path, tmp);
  tmp->x = x;
  tmp->y = y;
  tmp->type = 1;
  tmp->stype = stype;
  return (tmp);
}

t_disp			*init_disp(char *name, int width, int height)
{
  t_disp                *disp;

  if (!(disp = malloc(sizeof(t_disp))))
    return (NULL);
  disp->window = create_window(name, width, height);
  disp->elems = NULL;
  if (!(disp->ship = malloc(sizeof(t_ship))))
    return (NULL);
  disp->view = init_view(disp->window);
  disp->mouse = malloc(sizeof(t_mouse));
  disp->spr_count_q = 0;
  disp->spr_count_r = 0;
  disp->rst1 = 0;
  disp->bmaxspeed = 7;
  disp->fire = 0;
  disp->nbr_kill = 0;
  disp->start = 0;
  disp->boss = 0;
  disp->j = 0;
  disp->boom = 0;
  disp->bullets = NULL;
  disp->explo = sfMusic_createFromFile(EXP);
  disp->event = malloc(sizeof(sfEvent));
  disp->score = init_score(disp);
  return (disp);
}

t_elem		*init_enemies(float x, float y, char *path, float stype)
{
   t_elem        *tmp;
   sfVector2i	 c;

   if (!(tmp = malloc(sizeof(t_elem))))
     return (NULL);
   tmp->sprite = init_sprite(path, tmp);
   tmp->x = x;
   tmp->y = y;
   tmp->type = 3;
   tmp->hp = 100.0;
   tmp->dmg = 20.0;
   tmp->stype = stype;
   tmp->dead = 0;
   tmp->spr = 1;
   tmp->spr_count_s = 0;
   tmp->spr_count_t = 0;
   tmp->a = vector2i(312, 384);
   tmp->b = vector2i(1, 3);
   c = vector2i(tmp->spr_count_s, tmp->spr_count_t);
   tmp->sprite = cut_sprite(tmp->sprite, tmp->a, tmp->b, c);
   tmp->i = 0;
   tmp->fire = 0;
   return (tmp);
}
