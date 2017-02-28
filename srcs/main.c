/*
** main.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 14:56:18 2017 detroy_j
** Last update Tue Feb 28 19:05:39 2017 detroy_j
*/

#include <unistd.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "options.h"
#include "tetriminos.h"

int	main(int ac, char **av)
{
  t_game	*game;
  t_options	*opts;

  opts = init_options();
  if ((opts->bin_name = malloc(sizeof(char) * my_strlen(av[0]) + 1)) == NULL)
    exit(84);
  my_strcpy(opts->bin_name, av[0]);
  get_arguments(opts, ac, av);
  game = malloc(sizeof(*game));
  game->first = game->last = NULL;
  game->tetriminos = 0;
  open_directory(game);
  order(game);
  if (opts->debug == 1)
    show_debug(game, opts);
  check_error_key(opts);
  return (free(opts), 0);
}
