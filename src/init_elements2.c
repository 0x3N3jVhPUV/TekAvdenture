/*
** init_elements2.c for  in /home/afene-_a/tekad/tekadventure/thomas
** 
** Made by andy afene mebaley
** Login   <afene-_a@epitech.net>
** 
** Started on  Sat Sep 30 16:52:39 2017 andy afene mebaley
** Last update Sat Oct  7 02:51:59 2017 Thomas Mikhail
*/

#include "my.h"

t_elem		*init_explosions(float x, float y, char *path, float stype)
{
  t_elem        *tmp;

  if (!(tmp = malloc(sizeof(t_elem))))
    return (NULL);
  tmp->sprite = init_sprite(path, tmp);
  tmp->x = x;
  tmp->y = y;
  tmp->type = 3;
  tmp->hp = 100.0;
  tmp->dmg = 20.0;
  tmp->stype = stype;
  return (tmp);
}
