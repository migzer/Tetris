/*
** my_memset.c for my_memset.c in /home/detroy_j/Documents/delivery/PSU_2016_tetris/lib/my
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Mar  6 14:55:42 2017 detroy_j
** Last update Mon Mar  6 15:02:15 2017 detroy_j
*/

#include <string.h>

void	*my_memset(void *str, int c, size_t n)
{
  size_t	i;

  i = 0;
  while (i < n)
    ((char *) str)[i++] = c;
  return (str);
}
