/*
** debug.c for  in /home/thomas.mikhail/tekadventure/thomas
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Thu Sep 28 16:59:40 2017 Thomas Mikhail
** Last update Sat Oct  7 02:52:25 2017 Thomas Mikhail
*/

#include <stdio.h>
#include "my.h"

void		print_objects_debug(t_disp *disp)
{
  t_elem        *tmp;
  t_bullet      *bull;
  int           i;

  i = 0;
  bull = NULL;
  tmp = disp->elems;
  if (disp->ship->dead == 1)
    printf("\n\nDEAD\n\n");
  printf("q=%d,r=%d fire=%d\n",
	 disp->spr_count_q, disp->spr_count_r,disp->fire);
  printf("Ship :x=%f,y=%f\n", disp->ship->x, disp->ship->y);
  while (tmp != NULL)
    {
      if (tmp->type == 2)
	printf("Cloud ");
      else if (tmp->type == 1)
	printf("Back");
      printf("nb:%d-> type=%f,stype=%f,pos_x=%f,pos_y=%f\n",
             i,tmp->type, tmp->stype, tmp->x, tmp->y);
      tmp = tmp->next;
      i++;
    }
  i = 0;
  bull = disp->ship->bullets;
  while (bull != NULL)
    {
      printf("Bullets %d,x=%f,y=%f\n", i, bull->pos.x,bull->pos.y);
      bull = bull->next;
      i++;
    }
}
