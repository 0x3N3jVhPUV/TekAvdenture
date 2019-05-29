/*
** game_menu.c for  in /home/thomas.mikhail/tekadventure/thomas
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Tue Oct  3 22:20:38 2017 Thomas Mikhail
** Last update Sat Oct  7 04:27:27 2017 Thomas Mikhail
*/

#include <unistd.h>
#include "my.h"

void	menu_game(t_disp *disp)
{
  t_menu	*menu;
  int		end;

  end = 0;
  menu = init_mainmenu("START", "EXIT");
  init_titlemenu("GALAMUS", menu);
  sleep(0.5);
  while (!end)
    {
      mouse_menu(disp);
      display_mainmenu(disp, menu, 1);
      end = choice_gamemenu(disp, menu, end);
    }
  sfFont_destroy(menu->font);
  sfText_destroy(menu->start);
  sfText_destroy(menu->exit);
  free(menu);
  sleep(1.0);
}

void	init_titlemenu(char *str, t_menu *menu)
{
  menu->pos_title.x = 360;
  menu->pos_title.y = SCREEN_HEIGHT/2 - SCREEN_HEIGHT/4;
  menu->title = sfText_create();
  sfText_setString(menu->title, str);
  sfText_setFont(menu->title, menu->font);
  sfText_setColor(menu->title, sfRed);
  sfText_setCharacterSize(menu->title, 40);
  sfText_setPosition(menu->title, menu->pos_title);
}

int	choice_gamemenu(t_disp *disp, t_menu *menu, int end)
{
  if (sfMouse_isButtonPressed(sfMouseLeft) && disp->mouse->m.x > 820
      && disp->mouse->m.x < 1095
      && disp->mouse->m.y > 460 && disp->mouse->m.y < 500)
    {
      menu->choice_start = 1;
      sfText_setColor(menu->start, sfRed);
      end = 1;
    }
  else if (sfMouse_isButtonPressed(sfMouseLeft) && disp->mouse->m.x > 860
	   && disp->mouse->m.x < 1060 && disp->mouse->m.y > 659
	   && disp->mouse->m.y < 684)
    {
      menu->choice_exit = 1;
      sfText_setColor(menu->exit, sfRed);
      free_disp(disp);
      exit (0);
    }
  return (end);
}

void	menu_retry(t_disp *disp)
{
  t_menu        *menu;
  int           end;

  end = 0;
  sfMusic_play(disp->explo);
  menu = init_mainmenu("RETRY", "EXIT");
  init_titlemenu("GALAMUS", menu);
  sleep(0.5);
  while (!end)
    {
      mouse_menu(disp);
      display_mainmenu(disp, menu, 1);
      end = choice_retrymenu(disp, menu, end);
    }
  if (disp->nbr_kill > disp->best)
    disp->best = disp->nbr_kill;
  semifree_disp(disp, menu);
  sleep(1.0);
}

int	choice_retrymenu(t_disp *disp, t_menu *menu, int end)
{
  if (sfMouse_isButtonPressed(sfMouseLeft) && disp->mouse->m.x > 820
      && disp->mouse->m.x < 1095 && disp->mouse->m.y > 460
      && disp->mouse->m.y < 500)
    return ((menu->choice_start = 1));
  else if (sfMouse_isButtonPressed(sfMouseLeft) && disp->mouse->m.x > 860
           && disp->mouse->m.x < 1060 && disp->mouse->m.y > 659
	   && disp->mouse->m.y < 684)
    {
      menu->choice_exit = 1;
      sfText_setColor(menu->exit, sfRed);
      free_disp(disp);
      exit(0);
    }
  return (end);
}
