/*
** menu.c for  in /home/thomas.mikhail/tekadventure/thomas
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Sun Oct  1 18:50:12 2017 Thomas Mikhail
** Last update Sat Oct  7 11:07:18 2017 Thomas Mikhail
*/

#include "my.h"

void		main_menu(t_disp *disp)
{
  int		end;
  t_menu	*menu;

  end = 0;
  menu = init_mainmenu("START", "EXIT");
  init_titlemenu("GALAMUS", menu);
  init_dispmainmenu(disp);
  while (end != -1)
    {
      mouse_menu(disp);
      end = check_choice(disp, menu);
      update_mouse_pos(disp, disp->window);
      disp->ship->bullets = update_mouse_click(disp, disp->ship->bullets);
      destroy_bullets(disp);
      update_all(disp);
      choice_mainmenu(disp, menu);
      display_mainmenu(disp, menu, 0);
      sfRenderWindow_setFramerateLimit(disp->window, 40);
    }
  semifree_disp(disp, menu);
}

void	init_dispmainmenu(t_disp *disp)
{
  disp->ship = init_ship(100, SCREEN_HEIGHT/2, SHIP, 0.3);
  disp->ship->sprite = update_sprite_ship(disp->ship, disp);
  disp->elems = push_frt(init_back(370, SCREEN_HEIGHT/2 - 100, START, 3.0)
			 , disp->elems);
  disp->elems = push_frt(init_back(370, SCREEN_HEIGHT/2 + 100, START, 3.0)
			 , disp->elems);
  disp->elems = push_frt(init_back(-430, -100, ASTE, 3.0), disp->elems);
}

void	choice_mainmenu(t_disp *disp, t_menu *menu)
{
  t_bullet  *tmp;

  tmp = disp->ship->bullets;
  while (tmp != NULL)
    {
      if (tmp->pos.x > 385 && tmp->pos.x < 620
	  && tmp->pos.y > 480 && tmp->pos.y < 500)
	{
	  menu->choice_start = 1;
	  sfText_setColor(menu->start, sfRed);
	}
      else if (tmp->pos.x > 385 && tmp->pos.x < 620
	       && tmp->pos.y > 680 && tmp->pos.y < 714)
	{
	  menu->choice_exit = 1;
	  sfText_setColor(menu->exit, sfRed);
	}
      tmp = tmp->next;
    }
}

void	display_mainmenu(t_disp *disp, t_menu *menu, int choice)
{
  sfRenderWindow_clear(disp->window, sfBlack);
  display_back(disp->elems, disp->window);
  display_cloud(disp->elems, disp->window, 0.5);
  if (disp->ship != NULL)
    display_ship(disp->ship, disp->window, disp->ship->stype);
  display_enemies(disp->elems, disp->window);
  if (disp->ship != NULL)
    display_bullets(disp->ship->bullets, disp->window);
  display_cloud(disp->elems, disp->window, 1.5);
  display_cloud(disp->elems, disp->window, 1.0);
  if (choice == 1)
    display_score(disp, disp->score);
  sfRenderWindow_drawText(disp->window, menu->start, NULL);
  sfRenderWindow_drawText(disp->window, menu->exit, NULL);
  sfRenderWindow_drawText(disp->window, menu->title, NULL);
  sfRenderWindow_display(disp->window);
}

int	check_choice(t_disp *disp, t_menu *menu)
{
  if (menu->choice_start == 1)
    return (-1);
  else if (menu->choice_exit == 1)
    {
      free_disp(disp);
      exit(0);
    }
  return (0);
}

