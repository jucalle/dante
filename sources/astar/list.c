/*
** list.c for  in /home/callew_j/rendu/semestre2/IA/dante/sources/astar
**
** Made by
** Login   <callew_j@epitech.net>
**
** Started on  Tue Oct 11 18:58:51 2016
** Last update Tue Oct 11 19:00:45 2016 
*/

#include <stdlib.h>
#include "astar.h"

int		add_neighbor_in_open(t_first *f, t_open *neighbor)
{
  if (f != NULL)
    {
      neighbor->next = f->first;
      f->first = neighbor;
      return (0);
    }
  return (1);
}

int		count_open(t_first *f)
{
  int		nb_cells;
  t_open	*tmp;

  nb_cells = 0;
  if (f != NULL)
    {
      tmp = f->first;
      while (tmp != NULL)
	{
	  if (tmp->closed == 0)
	    nb_cells++;
	  tmp = tmp->next;
	}
    }
  return (nb_cells);
}

t_first		*init_first(t_map *map)
{
  t_first	*f;
  t_open	*open;

  if ((f = malloc(sizeof(t_first))) == NULL
      || (open = malloc(sizeof(t_open))) == NULL)
    return (NULL);
  if (f == NULL || open == NULL)
    return (NULL);
  open->x = 0;
  open->y = 0;
  open->h_cost = (map->largeur - 1) * 10 + (map->hauteur - 1) * 10;
  open->closed = 0;
  open->next = NULL;
  open->parent = NULL;
  f->first = open;
  return (f);
}
