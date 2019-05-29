/*
** destroy.c for  in /home/thomas.mikhail/tekadventure/thomas
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Thu Sep 28 19:55:24 2017 Thomas Mikhail
** Last update Sat Oct  7 02:48:45 2017 Thomas Mikhail
*/

#include "my.h"

void		destroy_player(t_disp *disp)
{
  if (disp->ship->dead == 1)
    menu_retry(disp);
}
void		destroy_elements(t_disp *disp)
{
  destroy_bullets(disp);
  destroy_bullets_en(disp);
  destroy_enemies(disp);
}

void		destroy_enemies(t_disp *disp)
{
  t_elem	*tmp;
  t_elem	*prev;

  prev = NULL;
  tmp = disp->elems;
  while (tmp != NULL)
    {
      if (tmp->dead == 10 && tmp->type == 3 && tmp->spr_count_t == 0)
	prev = delete_enemies(tmp, prev, disp);
      else if (tmp->type == 3 && (tmp->x < -20 || tmp->x > 3000
				  || tmp->y < -20 || tmp->y > 3000))
	prev = delete_enemies(tmp, prev, disp);
      else
        prev = tmp;
      tmp = tmp->next;
    }
}

t_elem		*delete_enemies(t_elem *tmp, t_elem *prev, t_disp *disp)
{
  t_elem	*to_free;

  to_free = tmp;
  if (prev == NULL && disp->elems->next != NULL)
    {
      disp->elems = disp->elems->next;
      prev = NULL;
    }
  else if (prev == NULL && disp->elems->next == NULL)
    {
      prev = NULL;
      disp->elems = NULL;
    }
  else
    prev->next = prev->next->next;
  sfTexture_destroy(to_free->texture);
  sfSprite_destroy(to_free->sprite);
  free(to_free);
  return (prev);
}

t_bullet	*delete_bullets_en(t_bullet *tmp, t_bullet *prev, t_disp *disp)
{
  t_bullet	*to_free;

  to_free = tmp;
  if (prev == NULL && disp->bullets->next != NULL)
    {
      disp->bullets = disp->bullets->next;
      prev = NULL;
    }
  else if (prev == NULL && disp->bullets->next == NULL)
    {
      prev = NULL;
      disp->bullets = NULL;
    }
  else
    prev->next = prev->next->next;
  sfTexture_destroy(to_free->texture);
  sfSprite_destroy(to_free->sprite);
  free(to_free);
  return (prev);
}
