/*
** display.c for  in /home/thomas.mikhail/tekadventure
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Thu Sep 28 21:35:50 2017 Thomas Mikhail
** Last update Sat Oct  7 11:03:18 2017 Thomas Mikhail
*/

#include "my.h"

void		display_all(t_disp *disp)
{
  sfRenderWindow_clear(disp->window, sfBlack);
  display_back(disp->elems, disp->window);
  display_ship(disp->ship, disp->window, disp->ship->stype);
  display_enemies(disp->elems, disp->window);
  display_bullets(disp->ship->bullets, disp->window);
  display_bullets_en(disp->bullets, disp->window);
  display_cloud(disp->elems, disp->window, 1.5);
  display_cloud(disp->elems, disp->window, 1.0);
  display_score(disp, disp->score);
  play_explosion(disp);
  sfRenderWindow_display(disp->window);
}

void		display_enemies(t_elem *en, sfRenderWindow *window)
{
  t_elem        *tmp;

  tmp = en;
  while (tmp != NULL)
    {
      if (tmp->type == 3)
        {
          sfSprite_setScale(tmp->sprite, vector2f(tmp->stype, tmp->stype));
          sfSprite_setPosition(tmp->sprite, vector2f(tmp->x, tmp->y));
          sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
        }
      tmp = tmp->next;
    }
}

void		display_back(t_elem *back, sfRenderWindow *window)
{
  t_elem	*tmp;

  tmp = back;
  while (tmp != NULL)
    {
      if (tmp->type == 1)
	{
	  sfSprite_setPosition(tmp->sprite, vector2f(tmp->x, tmp->y));
	  sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
	}
      tmp = tmp->next;
    }
}

void		display_cloud(t_elem *cloud, sfRenderWindow *window, float stype)
{
  t_elem	*tmp;

  tmp = cloud;
  while (tmp != NULL)
    {
      if (tmp->type == 2 && stype == tmp->stype)
	{
	  sfSprite_setScale(tmp->sprite, vector2f(tmp->stype, tmp->stype));
	  sfSprite_setPosition(tmp->sprite, vector2f(tmp->x, tmp->y));
	  sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
	}
      tmp = tmp->next;
    }
}

void	display_ship(t_ship *ship, sfRenderWindow *window, float stype)
{
  sfSprite_setScale(ship->sprite, vector2f(stype, 0.4));
  sfSprite_setOrigin(ship->sprite, vector2f((145), ((99/2))));
  sfSprite_setPosition(ship->sprite, vector2f(ship->x, ship->y));
  sfRenderWindow_drawSprite(window, ship->sprite, NULL);
}
