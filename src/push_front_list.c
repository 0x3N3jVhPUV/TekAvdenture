/*
** push_front_list.c for  in /home/thomas.mikhail/tekadventure/thomas
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Wed Sep 27 18:40:14 2017 Thomas Mikhail
** Last update Sat Oct  7 02:52:06 2017 Thomas Mikhail
*/

#include "my.h"
#include <stdlib.h>

t_elem		*push_frt(t_elem *tmp, t_elem *root)
{
  t_elem	*element;

  element = tmp;
  element->next = root;
  root = element;
  return (root);
}

t_bullet	*push_frtbls(t_bullet *tmp, t_bullet *root)
{
  t_bullet	*element;

  element = tmp;
  element->next = root;
  root = element;
  return (root);
}
