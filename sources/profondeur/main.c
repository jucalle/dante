/*
** main.c for dante in /home/sebastien/Rendu/dante/sources/profondeur
**
** Made by Sebastien Le Guischer
** Login   <sebastien@epitech.net>
**
** Started on  Tue Sep 27 18:24:47 2016 Sebastien Le Guischer
** Last update Sun Oct 23 15:37:35 2016 Sebastien Le Guischer
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "profondeur.h"

int	pars_map(int x, int y, t_map *map, int i)
{
  map->map[y][x] = 'o';
  if (i == 174467)
    return (-1);
  if (x == map->largeur - 1 && y == map->hauteur - 1)
      return (0);
  if (x + 1 < map->largeur && map->map[y][x + 1] == '*')
    if (pars_map(x + 1, y, map, i + 1) == 0)
      return (0);
  if (y + 1 < map->hauteur && map->map[y + 1][x] == '*')
    if (pars_map(x, y + 1, map, i + 1) == 0)
      return (0);
  if (x - 1 >= 0 && map->map[y][x - 1] == '*')
    if (pars_map(x - 1, y, map, i + 1) == 0)
      return (0);
  if (y - 1 >= 0 && map->map[y - 1][x] == '*')
    if (pars_map(x, y - 1, map, i + 1) == 0)
      return (0);
  map->map[y][x] = 'a';
  return (-1);
}

void	change_map(t_map *map)
{
  int	x;
  int	y;

  y = 0;
  while (y != map->hauteur)
    {
      x = 0;
      while (x != map->largeur)
	{
	  if (map->map[y][x] == 'a')
	    map->map[y][x] = '*';
	  x = x + 1;
	}
      y = y + 1;
    }
}

int	main(int ac, char **av)
{
  t_map	map;
  int	i;

  if (ac != 2)
    return (1);
  if (get_map(&map, av[1]) == 1)
    return (1);
  if (map.hauteur == 0)
    return (1);
  if (pars_map(0, 0, &map, 0) == -1)
    {
      fprintf(stderr, "No path found!\n");
      return (1);
    }
  change_map(&map);
  print_map(&map);
  i = 0;
  while (i != map.hauteur)
    {
      free(map.map[i]);
      i = i + 1;
    }
  free(map.map);
  return (0);
}
