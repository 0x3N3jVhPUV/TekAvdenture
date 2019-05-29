/*
** collision.c for  in /home/thomas.mikhail/tekadventure/thomas
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Sat Oct  7 02:13:43 2017 Thomas Mikhail
** Last update Sat Oct  7 03:36:54 2017 Thomas Mikhail
*/

#include "my.h"

void		check_collision(t_disp *disp)
{
  t_bullet      *tmp;
  t_elem        *en;

  tmp = disp->ship->bullets;
  while (tmp != NULL)
    {
      en = disp->elems;
      while (en != NULL)
        {
          if ((en->type == 3)
	      && (tmp->pos.x < en->x + 25.0 && tmp->pos.x > en->x - 25.0)
	      && (tmp->pos.y < en->y + 30.0 && tmp->pos.y > en->y - 25.0)
	      && en->dead == 0)
            {
              en->i = 1;
              en->sprite = init_sprite(PLAYER, en);
              tmp->dead = 1;
              disp->nbr_kill++;
	      disp->boom = 1;
            }
          en = en->next;
        }
      tmp = tmp->next;
    }
}

int		check_player_collision(t_disp *disp)
{
  t_bullet      *tmp;
  int           end;

  end = 0;
  tmp = disp->bullets;
  if (disp->ship->y > SCREEN_HEIGHT - 295)
    end = collision_player(disp);
  else
    {
      while (tmp != NULL)
        {
          if (tmp->pos.x < disp->ship->x + 25.0
	      && tmp->pos.x > disp->ship->x - 25.0
              && tmp->pos.y < disp->ship->y + 30.0
	      && tmp->pos.y > disp->ship->y - 25.0)
            end = collision_player(disp);
          tmp = tmp->next;
        }
    }
  update_animation_test(disp->ship);
  return (end);
}

int	collision_player(t_disp *disp)
{
  disp->ship->i = 1;
  disp->ship->sprite = init_sprite_ship(PLAYER, disp->ship);
  return (1);
}
