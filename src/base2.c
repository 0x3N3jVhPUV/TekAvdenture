/*
** base2.c for  in /home/afene-_a/tekad/tekadventure/src
** 
** Made by andy afene mebaley
** Login   <afene-_a@epitech.net>
** 
** Started on  Sat Oct  7 10:36:16 2017 andy afene mebaley
** Last update Sat Oct  7 11:02:47 2017 Thomas Mikhail
*/

#include "my.h"
#include "get_next_line.h"

int	my_strncmp(char *str, char *str2, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      if (str[i] != str2[i])
	return (1);
      i++;
    }
  return (0);
}

char	*my_ini_strcpy(char *dest, char *src)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (src[i] != '=')
    i++;
  i = i + 2;
  while (src[i])
    {
      dest[j] = src[i];
      i = i + 1;
      j = j + 1;
    }
  dest[j] = '\0';
  return (dest);
}

int		change(t_disp *disp)
{
  if (disp->i == 0)
    {
      if (my_strncmp(disp->str, "BACKGROUND = ", 13) == 0)
	disp->back = my_ini_strcpy(disp->back, disp->str);
      else
	return (84);
    }
  if (disp->i == 1)
    {
      if (my_strncmp(disp->str, "SCROLLING OBJECT = ", 19) == 0)
	disp->scrolling_object = my_ini_strcpy(disp->scrolling_object, disp->str);
      else
	return (84);
    }
  if (disp->i == 2)
    {
      if (my_strncmp(disp->str, "BULLET = ", 9) == 0)
	disp->bullet = my_ini_strcpy(disp->bullet, disp->str);
      else
	return (84);
    }
  return (0);
}

int	check_ini(char *str, t_disp *disp)
{
  if (str == NULL)
    return (84);
  if (!(disp->back = malloc(sizeof(char))))
    return (84);
  if (!(disp->scrolling_object = malloc(sizeof(char))))
    return (84);
  if (!(disp->bullet = malloc(sizeof(char))))
    return (84);
  if ((disp->fd = open(str, O_RDONLY)) == -1)
    return (84);
  disp->i = 0;
  while ((disp->str = get_next_line(disp->fd)))
    {
      if (change(disp) == 84)
	return (84);
      disp->i++;
    }
  close(disp->fd);
  return (0);
}
