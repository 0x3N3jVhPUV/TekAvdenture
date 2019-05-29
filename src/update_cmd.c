/*
** update_cmd.c for  in /home/thomas.mikhail/tekadventure
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Thu Sep 28 21:35:13 2017 Thomas Mikhail
** Last update Sat Oct  7 10:58:02 2017 andy afene mebaley
*/

#include "my.h"

t_bullet	*update_mouse_click(t_disp *disp, t_bullet *bullets)
{
  t_bullet      *bullet;

  if (sfMouse_isButtonPressed(sfMouseLeft) && disp->fire == 0)
    {
      bullet = malloc(sizeof(t_bullet));
      bullet->sprite = init_sprite_bullet(disp->bullet, bullet);
      bullet->pos = vector2f(disp->playerpos.x, disp->playerpos.y);
      sfSprite_setPosition(bullet->sprite, bullet->pos);
      bullet->cvelocity.x = disp->mouse->aimnorm.x * disp->bmaxspeed;
      bullet->cvelocity.y = disp->mouse->aimnorm.y * disp->bmaxspeed;
      disp->ship->nb_bullets++;
      bullets = push_frtbls(bullet, bullets);
      disp->fire = 1;
    }
  else if (disp->fire > disp->ship->att_speed)
    disp->fire = 0;
  else if (disp->fire > 0)
    disp->fire = disp->fire + 1;
  return (bullets);
}

void	update_mouse_pos(t_disp *d, sfRenderWindow *win)
{
  float	pi;

  pi = 3.14159265;
  d->mouse->point = sfMouse_getPositionRenderWindow(win);
  sfRenderWindow_mapPixelToCoords(d->window, d->mouse->point, d->view);
  d->playerpos = sfSprite_getPosition(d->ship->sprite);
  d->mouse->m = sfMouse_getPositionRenderWindow(d->window);
  d->mouse->x = ((d->mouse->m.x) - (d->playerpos.x * 2));
  d->mouse->y = ((d->mouse->m.y) - (d->playerpos.y));
  d->mouse->angle = -atan2(d->mouse->x, d->mouse->y) * 180 / pi;
  sfSprite_setRotation(d->ship->sprite, (d->mouse->angle + 90));
  d->playerctr = sfSprite_getPosition(d->ship->sprite);
  d->mouse->poswind = sfMouse_getPositionRenderWindow(d->window);
  d->mouse->aim.x = (d->mouse->poswind.x) - (d->playerctr.x * 2);
  d->mouse->aim.y = (d->mouse->poswind.y) - (d->playerctr.y);
  d->mouse->aimnorm.x = d->mouse->aim.x / sqrt(pow(d->mouse->aim.x, 2)
					       + pow(d->mouse->aim.y, 2));
  d->mouse->aimnorm.y = (d->mouse->aim.y * 2) / sqrt(pow(d->mouse->aim.x, 2)
					       + pow(d->mouse->aim.y, 2));
}

void	update_keys(t_ship *ship)
{
  if (sfKeyboard_isKeyPressed(sfKeyQ) && (ship->x - SPEED > 0))
      ship->x -= SPEED;
  if (sfKeyboard_isKeyPressed(sfKeyD) && (ship->x + SPEED < SCREEN_WIDTH - 950))
      ship->x += SPEED;
  if (sfKeyboard_isKeyPressed(sfKeyZ) && (ship->y - SPEED > 0))
      ship->y -= SPEED;
  if (sfKeyboard_isKeyPressed(sfKeyS) &&
      (ship->y + SPEED < SCREEN_HEIGHT - 280))
      ship->y += SPEED;
}

t_bullet	*update_cmd(t_disp *d)
{
  update_mouse_pos(d, d->window);
  d->ship->bullets = update_mouse_click(d, d->ship->bullets);
  update_keys(d->ship);
  return (d->ship->bullets);
}
