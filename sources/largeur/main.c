/*
** main.c for dante in /home/sebastien/Rendu/dante/sources/profondeur
**
** Made by Sebastien Le Guischer
** Login   <sebastien@epitech.net>
**
** Started on  Tue Sep 27 18:24:47 2016 Sebastien Le Guischer
** Last update Wed Oct 12 15:47:36 2016 
*/

#include <stdio.h>
#include <stdlib.h>
#include "largeur.h"

t_first		*init_first()
{
  t_first	*f;
  t_larg	*init;

  if ((init = malloc(sizeof(t_larg))) == NULL
      || (f = malloc(sizeof(t_first))) == NULL)
    return (NULL);
  init->block = 0;
  init->pos.x = 0;
  init->pos.y = 0;
  init->son = NULL;
  init->dad = NULL;
  f->first = init;
  return (f);
}

int		count_open(t_first *f)
{
  int		nb_open;
  t_larg	*tmp;

  nb_open = 0;
  if (f == NULL || f->first == NULL)
    return (0);
  tmp = f->first;
  while (tmp != NULL)
    {
      if (tmp->block == 0)
	nb_open++;
      tmp = tmp->son;
    }
  return (nb_open);
}

void		change_son_pos(t_larg *son, int y, int x)
{
  son->pos.y = y;
  son->pos.x = x;
}

int		not_already_in_list(t_first *f, t_larg *son)
{
  t_larg	*tmp;

  if (f == NULL || f->first == NULL || son == NULL)
    return (1);
  tmp = f->first;
  while (tmp != NULL)
    {
      if (tmp->pos.x == son->pos.x
	  && tmp->pos.y == son->pos.y)
	return (1);
      tmp = tmp->son;
    }
  return (0);
}

int		main(int ac, char **av)
{
  int		ret_larg;
  t_map		map;
  t_first	*f;

  f = NULL;
  ret_larg = 0;
  if (ac != 2)
    return (1);
  if (get_map(&map, av[1]) == 1)
    return (1);
  if ((f = init_first()) == NULL)
    return (1);
  if ((ret_larg = largeur(f, &map)) == -1)
    return (1);
  if (ret_larg == 1)
    {
      fprintf(stderr, "No solution found\n");
      return (1);
    }
  print_map(&map);
  return (0);
}
