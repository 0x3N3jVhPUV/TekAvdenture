/*
** getnextline.c for  in /home/afene-_a/rendu/CPE_2015_allum1
** 
** Made by andy afene-mebaley
** Login   <afene-_a@epitech.net>
** 
** Started on  Sun Jul 24 15:24:12 2016 andy afene-mebaley
** Last update Sat Oct  7 11:03:59 2017 Thomas Mikhail
*/

#include <unistd.h>
#include <unistd.h>
#include "get_next_line.h"

int		read_buffer(const int fd, char *curline)
{
  static int    i;
  static int    readbuffer = READ_SIZE;
  static char   buff[READ_SIZE];

  if (readbuffer == 0)
    *curline = '\0';
  if (i == 0 || i >= readbuffer)
    {
      i = 0;
      if ((readbuffer = read(fd, buff, READ_SIZE)) == -1)
        return (0);
    }
  if (readbuffer != 0)
    {
      if (buff[i] == '\n')
        *curline = '\0';
      else
        *curline = buff[i];
      i++;
    }
  return (readbuffer);
}

char		*my_malloc(char *oldline, int j)
{
  char          *newline;
  int           i;

  i = 0;
  if ((newline = malloc(j + sizeof(char) + 1)) == NULL)
    return (NULL);
  while (i <= j)
    {
      newline[i] = oldline[i];
      i = i + 1;
    }
  free (oldline);
  return (newline);
}

char		*get_next_line(const int fd)
{
  int           i;
  int           readbuffer;
  int           size;
  char          *curline;

  i = 0;
  size = (READ_SIZE + 1);
  if (fd < 0)
    return (0);
  if ((curline = malloc(size * sizeof(char) + 2)) == NULL)
    return (0);
  if ((readbuffer = read_buffer(fd, &curline[i])) == 0)
    return (0);
  while (curline[i] != '\0')
    {
      i = i + 1;
      curline = my_malloc(curline, size + i);
      readbuffer = read_buffer(fd, &curline[i]);
    }
  curline[i] = '\0';
  return (curline);
}
