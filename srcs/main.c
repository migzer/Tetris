/*
** main.c for tetris in /home/detroy_j/Documents/delivery/tetris
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 20 14:56:18 2017 detroy_j
** Last update Thu Feb 23 14:56:10 2017 detroy_j
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
  get_arguments(opts, ac, av);
  game = malloc(sizeof(*game));
  game->first = game->last = NULL;
  open_directory(game);
  order(game);
  if (opts->debug == 1)
    show_debug(game, opts);
  check_error_key(opts);
  return (free(opts), 0);
}