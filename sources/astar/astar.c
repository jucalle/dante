/*
** astar.c for  in /home/callew_j/rendu/semestre2/IA/dante/sources/astar
**
** Made by
** Login   <callew_j@epitech.net>
**
** Started on  Tue Oct 11 18:57:30 2016
** Last update Tue Oct 11 19:05:32 2016 
*/

#include <stdlib.h>
#include "astar.h"

void		get_neighbours_pos(t_open *neighbor, int y, int x)
{
  neighbor->y = y;
  neighbor->x = x;
}

t_open		*lowest_h_cost(t_first *f)
{
  int		i;
  int		save_i;
  int		min;
  t_open	*tmp;

  if (f != NULL && f->first != NULL)
    {
      i = 0;
      save_i = 0;
      tmp = f->first;
      if ((min = get_min(f)) == -1)
	return (NULL);
      while (tmp != NULL)
      	{
      	  if (tmp->closed == 0 && min >= tmp->h_cost)
      	    {
      	      save_i = i;
      	      min = tmp->h_cost;
      	    }
      	  i++;
      	  tmp = tmp->next;
      	}
      return (return_actual(f, save_i));
    }
  return (NULL);
}

int		set_neighbours(t_open *neighbor,
			       t_map *map, t_first *f, t_open *actual)
{
  int		ret;

  ret = 0;
  if (neighbor->x >= 0 && neighbor->x < map->largeur
      && neighbor->y >= 0 && neighbor->y < map->hauteur
      && map->map[neighbor->y][neighbor->x] != 'X'
      && (ret = is_it_closed(f, neighbor->y, neighbor->x)) != 1)
    {
      if (ret == -1)
	return (1);
      if ((ret = is_it_in_open(f, neighbor->y, neighbor->x)) != 1)
	{
	  if (ret == -1)
	    return (1);
	  neighbor->closed = 0;
	  neighbor->h_cost = ((map->largeur - 1)- neighbor->x) * 10
	    + ((map->hauteur - 1) - neighbor->y) * 10;
	  neighbor->parent = actual;
	  if (add_neighbor_in_open(f, neighbor) == 1)
	    return (1);
	}
    }
  return (0);
}

int		get_neighbours(t_map *map, t_first *f, t_open *actual)
{
  int		i;
  t_open	*neighbor;

  i = 0;
  while (i < 4)
    {
      if ((neighbor = malloc(sizeof(t_open))) == NULL)
	return (1);
      if (i == 0)
	get_neighbours_pos(neighbor, actual->y, actual->x - 1);
      else if (i == 1)
	get_neighbours_pos(neighbor, actual->y, actual->x + 1);
      else if (i == 2)
	get_neighbours_pos(neighbor, actual->y - 1, actual->x);
      else if (i == 3)
	get_neighbours_pos(neighbor, actual->y + 1, actual->x);
      if (set_neighbours(neighbor, map, f, actual) == 1)
	return (1);
      i++;
    }
  return (0);
}

int		astar(t_map *map, t_first *f)
{
  t_open	*actual;

  while (count_open(f) > 0)
    {
      if ((actual = lowest_h_cost(f)) == NULL)
	return (1);
      close_actual_from_open(f, actual);
      if (actual->y == map->hauteur - 1 && actual->x == map->largeur - 1)
	{
	  while (actual != NULL)
	    {
	      map->map[actual->y][actual->x] = 'o';
	      actual = actual->parent;
	    }
	  return (0);
	}
      if (get_neighbours(map, f, actual) == 1)
	return (1);
    }
  my_putsterror("No solution found\n");
  return (1);
}
