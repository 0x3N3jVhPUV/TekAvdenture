/*
** get_next_line.h for  in /home/afene-_a/CPE_2015_getnextline
** 
** Made by andy afene-mebaley
** Login   <afene-_a@epitech.net>
** 
** Started on  Tue Jun  7 14:14:31 2016 andy afene-mebaley
** Last update Sun Jul 24 15:31:04 2016 andy afene-mebaley
*/

# ifndef READ_SIZE
#  define READ_SIZE (14)

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(const int);
char	*my_malloc(char*, int);
int	read_buff(const int, char*);

# endif /* !READ_SIZE */
