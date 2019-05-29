/*
** music.c for  in /home/thomas.mikhail/tekadv/save_clean_samedi5h00
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Sat Oct  7 03:34:23 2017 Thomas Mikhail
** Last update Sat Oct  7 03:51:50 2017 Thomas Mikhail
*/

#include "my.h"

void	play_explosion(t_disp *disp)
{
  if (disp->boom == 1)
    {
      sfMusic_play(disp->explo);
      disp->boom = 0;
    }
}
