/*
** my_free.c for  in /home/thomas.mikhail/tekadventure/thomas
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Sat Oct  7 02:16:07 2017 Thomas Mikhail
** Last update Sat Oct  7 03:59:07 2017 Thomas Mikhail
*/

#include "my.h"

void		semifree_disp(t_disp *disp, t_menu *menu)
{
  t_elem        *tmp;

  if (disp->bullets != NULL)
    free_bullets(disp);
  free(disp->bullets);
  free_ship(disp->ship);
  free(disp->ship);
  while (disp->elems)
    {
      tmp = disp->elems;
      sfSprite_destroy(disp->elems->sprite);
      sfTexture_destroy(disp->elems->texture);
      disp->elems = disp->elems->next;
      free(tmp);
    }
  free(disp->elems);
  if (menu != NULL)
    {
      sfFont_destroy(menu->font);
      sfText_destroy(menu->start);
      sfText_destroy(menu->exit);
      free(menu);
    }
}

void		free_bullets(t_disp *disp)
{
  t_bullet      *tmp;

  while (disp->bullets != NULL)
    {
      tmp = disp->bullets;
      sfSprite_destroy(disp->bullets->sprite);
      sfTexture_destroy(disp->bullets->texture);
      disp->bullets = disp->bullets->next;
      free(tmp);
    }
}

void		free_disp(t_disp *disp)
{
  t_elem        *tmp;

  free_ship(disp->ship);
  free(disp->ship);
  while (disp->elems)
    {
      tmp = disp->elems;
      sfSprite_destroy(disp->elems->sprite);
      sfTexture_destroy(disp->elems->texture);
      disp->elems = disp->elems->next;
      free(tmp);
    }
  sfRenderWindow_destroy(disp->window);
  sfMusic_destroy(disp->explo);
  sfMusic_destroy(disp->melo);
  free(disp);
}

void		free_ship(t_ship *ship)
{
  t_bullet      *tmp;

  while (ship->bullets != NULL)
    {
      tmp = ship->bullets;
      sfSprite_destroy(ship->bullets->sprite);
      sfTexture_destroy(ship->bullets->texture);
      ship->bullets = ship->bullets->next;
      free(tmp);
    }
}
