/*
** load.c for tetris in /home/detroy_j/Documents/delivery/tetris/srcs/tetriminos
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Wed Feb 22 18:33:27 2017 detroy_j
** Last update Thu Feb 23 15:10:07 2017 detroy_j
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include "tetriminos.h"
#include "my.h"

static void	read_file_config(t_tetrimino *tetri, char *str)
{
  char		*value;
  int		i;

  i = 0;
  while ((value = my_strsep(&str, " ")) != NULL)
    {
      if (!is_number(value))
	tetri->valid = 0;
      else
	{
	  (i == 0) ? tetri->col = my_getnbr(value) : 0;
	  (i == 1) ? tetri->row = my_getnbr(value) : 0;
	  (i == 2) ? tetri->color = my_getnbr(value) : 0;
	}
      i++;
    }
  if (i != 3)
    tetri->valid = 0;
  if (str != NULL)
    free(str);
}

static int	read_file_map(t_tetrimino *tetri, char *str, int i, int l)
{
  int		j;
  int		k;

  j = 0;
  k = my_strlen(str);
  if (k > tetri->col)
    {
      tetri->valid = 0;
      return (0);
    }
  while (str[j] != '\0')
    {
      if (str[j] == '*' && l <= j)
	l = j;
      tetri->shape[i][j] = str[j];
      j++;
    }
  while (j < tetri->col)
    {
      tetri->shape[i][j] = ' ';
      j++;
    }
  tetri->shape[i][j] = '\0';
  return (l);
}

static int	get_name(t_tetrimino *t, char *name)
{
  int		i;
  int		j;

  i = j = 0;
  while (name[i++] != '\0')
    if (name[i] == '.')
      break;
  if ((t->name = malloc(sizeof(char) * (my_strlen(name) - i + 1))) == NULL)
    exit(84);
  while (j < i)
    {
      t->name[j] = name[j];
      j++;
    }
  t->name[j] = '\0';
  return (0);
}

int	load_file(t_game *game, char *name, char *path)
{
  t_tetrimino   *new;
  int   fd;
  char  *str;
  int   i;
  int   j;
  int   l;

  if ((fd = open(path, O_RDONLY)) < 0)
    return (0);
  if ((new = malloc(sizeof(*new))) == NULL)
    exit(84);
  str = NULL;
  get_name(new, name);
  new->valid = 1;
  new->col = new->row = new->color = -1;
  i = j = l = 0;
  if ((str = get_next_line(fd)) != NULL)
    read_file_config(new, str);
  if (new->row > 0 && new->col > 0)
    {
      if ((new->shape = malloc(sizeof(char *) * (new->row + 1))) == NULL)
	exit(84);
      while (i < new->row)
	if ((new->shape[i++] = malloc(sizeof(char) * (new->col + 1))) == NULL)
	  exit(84);
      new->shape[new->row] = NULL;
    }
  i = l = 0;
  while ((str = get_next_line(fd)) != NULL && j < new->row)
    {
      l = read_file_map(new, str, i, l);
      free(str);
      i++;
      j++;
    }
  if (l + 1 < new->col)
    new->valid = 0;
  new->next = game->first;
  new->prev = NULL;
  if (game->first)
    game->first->prev = new;
  else
    game->last = new;
  game->first = new;
  close(fd);
  return (0);
}