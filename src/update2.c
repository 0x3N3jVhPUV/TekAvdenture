/*
** update2.c for  in /home/thomas.mikhail/tekadventure/thomas
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Thu Sep 28 22:25:06 2017 Thomas Mikhail
** Last update Sat Oct  7 11:10:50 2017 andy afene mebaley
*/

#include "my.h"

sfSprite	*update_sprite_enemies_ship(t_elem *elems)
{
  sfVector2i    c;
  sfSprite      *tmp;

  if (elems->i == 1)
    {
      elems->a = vector2i(900, 900);
      elems->b = vector2i(8, 8);
    }
  else
    {
      elems->a = vector2i(312, 384);
      elems->b = vector2i(1, 3);
    }
  c = vector2i(elems->spr_count_t, elems->spr_count_s);
  tmp = cut_sprite(elems->sprite, elems->a, elems->b, c);
  return (tmp);
}

t_bullet	*update_enemies(t_elem *enemies, t_bullet *en_bullets, t_disp *disp)
{
  enemies->sprite = update_sprite_enemies_ship(enemies);
  update_animation(enemies);
  if (disp->nbr_kill % 8 == 0 && disp->boss == 0 && disp->nbr_kill != 0)
    en_bullets = create_bullet_big(en_bullets, enemies, disp);
  if (disp->nbr_kill % 10 == 0 && disp->boss == 1 && disp->nbr_kill != 0)
    disp->boss = 0;
  en_bullets = create_bullet(en_bullets, enemies);
  enemies->x -= 3.2;
  return (en_bullets);
}

t_bullet	*create_bullet_big(t_bullet *bullets, t_elem *elem, t_disp *disp)
{
  t_bullet	*bullet;
  int		i;

  i = 0;
  while (i < 3)
    {
      bullet = malloc(sizeof(t_bullet));
      bullet->sprite = init_sprite_bullet(BULLET, bullet);
      bullet->pos = vector2f(elem->x, elem->y + 20.0);
      sfSprite_setPosition(bullet->sprite, bullet->pos);
      bullet->cvelocity.x = 9.5;
      bullet->cvelocity.y = i;
      bullets = push_frtbls(bullet, bullets);
      i++;
    }
  disp->boss = 1;
  return (bullets);
}

t_bullet	*create_bullet(t_bullet *bullets, t_elem *elem)
{
  int		ramdom;
  t_bullet	*bullet;

  srand(time(NULL));
  ramdom = rand() % 2;
  if (ramdom == 1 && elem->fire == 0)
    {
      bullet = malloc(sizeof(t_bullet));
      bullet->sprite = init_sprite_bullet(BULLET, bullet);
      bullet->pos = vector2f(elem->x, elem->y + 20.0);
      sfSprite_setPosition(bullet->sprite, bullet->pos);
      bullet->cvelocity.x = 9.5;
      bullet->cvelocity.y = 0;
      bullets = push_frtbls(bullet, bullets);
      elem->fire++;
    }
  else if (ramdom == 1 && elem->fire < 2)
    elem->fire++;
  else if (ramdom == 1 && elem->fire > 2)
    elem->fire = 0;
  return (bullets);
}

void	update_enemies_bullets(t_bullet *bullets)
{
  t_bullet     *tmp;

  tmp = bullets;
  while (tmp != NULL)
    {
      tmp->pos.x -= tmp->cvelocity.x;
      tmp->pos.y -= tmp->cvelocity.y;
      tmp = tmp->next;
    }
}
