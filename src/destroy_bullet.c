/*
** destroy_bullet.c for  in /home/thomas.mikhail/tekadventure/thomas
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Sat Oct  7 02:09:48 2017 Thomas Mikhail
** Last update Sat Oct  7 02:51:49 2017 Thomas Mikhail
*/

#include "my.h"

void		destroy_bullets(t_disp *disp)
{
  t_bullet      *tmp;
  t_bullet      *prev;

  prev = NULL;
  tmp = disp->ship->bullets;
  while (tmp != NULL)
    {
      if (tmp->pos.x < -20 || tmp->pos.x > 3000
          || tmp->pos.y < -20 || tmp->pos.y > 3000)
        prev = delete_bullets(tmp, prev, disp);
      else if (tmp->dead == 1)
	prev = delete_bullets(tmp, prev, disp);
      else
        prev = tmp;
      tmp = tmp->next;
    }
}

void		destroy_bullets_en(t_disp *disp)
{
  t_bullet      *tmp;
  t_bullet      *prev;

  prev = NULL;
  tmp = disp->bullets;
  while (tmp != NULL)
    {
      if (tmp->pos.x < -20 || tmp->pos.x > 3000
          || tmp->pos.y < -20 || tmp->pos.y > 3000)
        prev = delete_bullets_en(tmp, prev, disp);
      else if (tmp->dead == 1)
        prev = delete_bullets_en(tmp, prev, disp);
      else
        prev = tmp;
      tmp = tmp->next;
    }
}

t_bullet	*delete_bullets(t_bullet *tmp, t_bullet *prev, t_disp *disp)
{
  t_bullet      *to_free;

  to_free = tmp;
  if (prev == NULL && disp->ship->bullets->next != NULL)
    {
      disp->ship->bullets = disp->ship->bullets->next;
      prev = NULL;
    }
  else if (prev == NULL && disp->ship->bullets->next == NULL)
    {
      prev = NULL;
      disp->ship->bullets = NULL;
    }
  else
    prev->next = prev->next->next;
  sfTexture_destroy(to_free->texture);
  sfSprite_destroy(to_free->sprite);
  free(to_free);
  return (prev);
}

void		display_bullets(t_bullet *bullets, sfRenderWindow *window)
{
  t_bullet      *tmp;

  tmp = bullets;
  while (tmp != NULL)
    {
      sfSprite_setPosition(tmp->sprite, tmp->pos);
      sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
      tmp = tmp->next;
    }
}

void		display_bullets_en(t_bullet *bullets, sfRenderWindow *window)
{
  t_bullet      *tmp;

  tmp = bullets;
  while (tmp != NULL)
    {
      sfSprite_setPosition(tmp->sprite, tmp->pos);
      sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
      tmp = tmp->next;
    }
}
