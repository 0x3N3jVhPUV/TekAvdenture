/*
** main.c for  in /home/thomas.mikhail/tekadventure/thomas
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Wed Sep 27 21:56:17 2017 Thomas Mikhail
** Last update Sat Oct  7 11:09:00 2017 Thomas Mikhail
*/

#include "my.h"

int		main_next(char *str)
{
  t_disp	*disp;

  if (!(disp = init_disp(GAME_NAME, SCREEN_WIDTH, SCREEN_HEIGHT)))
    return (84);
  if (check_ini(str, disp) ==  84)
    return (84);
  disp->melo = sfMusic_createFromFile(MUS);
  sfMusic_play(disp->melo);
  main_menu(disp);
  while (1)
    {
      disp = init_level_one(disp);
      level_one_loop(disp);
    }
  return (0);
}

int		main(int ac, char **av)
{
  if (ac == 1)
    {
      write(2, NOARG, 20);
      return (84);
    }
  else if (ac == 2)
    main_next(av[1]);
  else if (ac > 2)
    {
      write(2, TOOARG, 27);
      return (84);
    }
  return (0);
}

void		level_one_loop(t_disp *disp)
{
  sfEvent	event;

  while (1)
    {
      while (sfRenderWindow_pollEvent(disp->window, &event))
	{
	  if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
	    menu_game(disp);
	}
      disp->ship->sprite = update_sprite_ship(disp->ship, disp);
      disp->ship->bullets = update_cmd(disp);
      update_anim_ship(disp);
      spawn_enemies(disp);
      check_collision(disp);
      if (check_player_collision(disp))
	break;
      disp->bullets = update_all(disp);
      display_all(disp);
      destroy_elements(disp);
      sfRenderWindow_setFramerateLimit(disp->window, 40);
    }
  menu_retry(disp);
}

void	spawn_enemies(t_disp *disp)
{
  if (disp->j > 100)
    {
      srand(time(NULL));
      disp->elems =
	push_frt(init_enemies(1000, (rand() % (SCREEN_HEIGHT - 400)),
			      PLAYER2, 0.5), disp->elems);
      disp->j = 0;
    }
  else
    disp->j++;
}

t_disp			*init_level_one(t_disp *disp)
{
  disp->nbr_kill = 0;
  disp->ship = init_ship(100, SCREEN_HEIGHT/2, SHIP, 0.3);
  disp->elems = push_frt(init_back(0, 0, disp->back, 1.00), disp->elems);
  disp->elems = push_frt(init_back(1920, 0, disp->back, 2.0), disp->elems);
  disp->elems =
    push_frt(init_cloud(1920, 0, disp->scrolling_object, 1.0), disp->elems);
  disp->elems =
    push_frt(init_cloud(2500, 300, disp->scrolling_object, 0.5), disp->elems);
  return (disp);
}
