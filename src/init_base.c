/*
** init_base.c for  in /home/thomas.mikhail/tekadventure/thomas
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Thu Sep 28 15:19:55 2017 Thomas Mikhail
** Last update Sat Oct  7 02:51:23 2017 Thomas Mikhail
*/

#include "my.h"

sfSprite	*init_sprite(char *path, t_elem *elems)
{
  sfTexture     *texture;
  sfSprite      *sprite;

  sprite = sfSprite_create();
  if (sprite == NULL)
    return (NULL);
  texture = sfTexture_createFromFile(path, NULL);
  if (texture == NULL)
    return (NULL);
  sfTexture_setSmooth(texture, sfTrue);
  sfSprite_setTexture(sprite, texture, sfTrue);
  elems->texture = texture;
  return (sprite);
}

sfView		*init_view(sfRenderWindow *window)
{
  sfView        *view;
  sfFloatRect	view_size;

  view_size.top = 0;
  view_size.left = 0;
  view_size.width = 1;
  view_size.height = 1;
  view = sfView_create();
  sfView_setViewport(view, view_size);
  sfRenderWindow_setView(window, view);
  return (view);
}

sfSprite	*init_sprite_ship(char *path, t_ship *elems)
{
  sfTexture     *texture;
  sfSprite      *sprite;

  sprite = sfSprite_create();
  if (sprite == NULL)
    return (NULL);
  texture = sfTexture_createFromFile(path, NULL);
  if (texture == NULL)
    return (NULL);
  sfTexture_setSmooth(texture, sfTrue);
  sfSprite_setTexture(sprite, texture, sfTrue);
  elems->texture = texture;
  return (sprite);
}

sfSprite	*init_sprite_bullet(char *path, t_bullet *elems)
{
  sfTexture     *texture;
  sfSprite      *sprite;

  sprite = sfSprite_create();
  if (sprite == NULL)
    return (NULL);
  texture = sfTexture_createFromFile(path, NULL);
  if (texture == NULL)
    return (NULL);
  sfTexture_setSmooth(texture, sfTrue);
  sfSprite_setTexture(sprite, texture, sfTrue);
  elems->texture = texture;
  elems->dead = 0;
  return (sprite);
}
