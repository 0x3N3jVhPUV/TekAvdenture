/*
** base_menu.c for  in /home/thomas.mikhail/tekadventure/thomas
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Wed Oct  4 01:29:25 2017 Thomas Mikhail
** Last update Sat Oct  7 02:49:27 2017 Thomas Mikhail
*/

#include "my.h"

void	mouse_menu(t_disp *d)
{
  d->mouse->point = sfMouse_getPositionRenderWindow(d->window);
  sfRenderWindow_mapPixelToCoords(d->window, d->mouse->point, d->view);
  d->mouse->m = sfMouse_getPositionRenderWindow(d->window);
  d->mouse->x = d->mouse->m.x;
  d->mouse->y = d->mouse->m.y;
}

t_menu		*init_mainmenu(char *start, char *exit)
{
  t_menu	*menu;

  menu = NULL;
  if (!(menu = malloc(sizeof(t_menu))))
    return (NULL);
  menu->choice_start = 0;
  menu->choice_exit = 0;
  menu->pos_start.x = 450;
  menu->pos_start.y = SCREEN_HEIGHT/2 + 135;
  menu->pos_exit.x = 425;
  menu->pos_exit.y = SCREEN_HEIGHT/2 - 65;
  menu->font = sfFont_createFromFile(FONT);
  menu->start = sfText_create();
  menu->exit = sfText_create();
  sfText_setString(menu->exit, exit);
  sfText_setString(menu->start, start);
  sfText_setFont(menu->start, menu->font);
  sfText_setFont(menu->exit, menu->font);
  sfText_setColor(menu->start, sfWhite);
  sfText_setCharacterSize(menu->start, 30);
  sfText_setCharacterSize(menu->exit, 30);
  sfText_setPosition(menu->start, menu->pos_exit);
  sfText_setPosition(menu->exit, menu->pos_start);
  return (menu);
}
