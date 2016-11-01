/*
** main.c for dante in /home/sebastien/Rendu/dante/sources/profondeur
**
** Made by Sebastien Le Guischer
** Login   <sebastien@epitech.net>
**
** Started on  Tue Sep 27 18:24:47 2016 Sebastien Le Guischer
** Last update Wed Oct 12 16:04:08 2016 
*/

#include <unistd.h>
#include <stdlib.h>
#include "astar.h"

void		my_putsterror(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      write(2, &str[i], 1);
      i++;
    }
}

int		main(int ac, char **av)
{
  int		i;
  t_map		map;
  t_first	*f;

  i = 0;
  f = NULL;
  if (ac != 2)
    return (1);
  if (get_map(&map, av[1]) == 1)
    return (1);
  if ((f = init_first(&map)) == NULL)
    return (1);
  if (astar(&map, f) == 1)
    return (1);
  print_map(&map);
  while (i != map.hauteur)
    {
      free(map.map[i]);
      i = i + 1;
    }
  free(map.map);
  return (0);
}
