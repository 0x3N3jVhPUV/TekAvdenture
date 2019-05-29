/*
** base.c for  in /home/thomas.mikhail/tekadventure/thomas
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Tue Sep 26 21:38:17 2017 Thomas Mikhail
** Last update Sat Oct  7 02:48:37 2017 Thomas Mikhail
*/

#include "my.h"

sfVector2i	vector2i(int x, int y)
{
  sfVector2i    v;

  v.x = x;
  v.y = y;
  return (v);
}

sfVector2f	vector2f(float x, float y)
{
  sfVector2f    v;

  v.x = x;
  v.y = y;
  return (v);
}

sfRenderWindow		*create_window(char *name, int width, int height)
{
  sfRenderWindow        *window;
  sfVideoMode           mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    exit(84);
  return (window);
}

sfSprite		*cut_sprite(sfSprite *dydy, sfVector2i a, sfVector2i b, sfVector2i c)
{
  sfIntRect             rectangle;

  b.x += 1;
  b.y += 1;
  rectangle.left = ((a.x / b.x) * c.x);
  rectangle.top = ((a.y / b.y) * c.y);
  rectangle.width = a.x / b.x;
  rectangle.height = a.y / b.y;
  sfSprite_setTextureRect(dydy, rectangle);
  return (dydy);
}
