/*
** str.c for  in /home/thomas.mikhail/tekadventure/thomas
** 
** Made by Thomas Mikhail
** Login   <thomas.mikhail@epitech.net>
** 
** Started on  Sat Oct  7 01:23:37 2017 Thomas Mikhail
** Last update Sat Oct  7 02:50:03 2017 Thomas Mikhail
*/

#include "my.h"

char	*my_str_cat(char *str, char *s)
{
  char  *res;
  int   i;
  int   j;

  j = 0;
  i = 0;
  res = malloc(sizeof(char) * (my_strlen(str) + my_strlen(s) + 1));
  while (str[i] != '\0')
    {
      res[i] = str[i];
      i++;
    }
  while (s[j] != '\0')
    {
      res[i] = s[j];
      i++;
      j++;
    }
  res[i] = '\0';
  return (res);
}

int	my_strlen(char *s)
{
  int   i;

  i = 0;
  while (s[i] != '\0')
    i++;
  return (i);
}
