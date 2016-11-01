/*
** largeur.c for  in /home/callew_j/rendu/semestre2/IA/dante/sources/largeur
**
** Made by
** Login   <callew_j@epitech.net>
**
** Started on  Wed Oct 12 15:46:05 2016
** Last update Wed Oct 12 16:05:21 2016 
*/

#include <stdlib.h>
#include "largeur.h"

int		add_to_the_list(t_first *f, t_larg *son, t_map *map)
{
  t_larg	*tmp;

  if (f == NULL || f->first == NULL || son == NULL)
    return (-1);
  if (son->pos.x >= 0 && son->pos.x < map->largeur
      && son->pos.y >= 0 && son->pos.y < map->hauteur
      && map->map[son->pos.y][son->pos.x] != 'X'
      && not_already_in_list(f, son) == 0)
    {
      tmp = f->first;
      while (tmp->son != NULL)
	tmp = tmp->son;
      tmp->son = son;
      son->block = 0;
      son->son = NULL;
    }
  return (0);
}

int		add_sons(t_first *f, t_larg *actual, t_map *map)
{
  int		i;
  t_larg	*son;

  i = 0;
  while (i < 4)
    {
      if ((son = malloc(sizeof(t_larg))) == NULL)
	return (-1);
      if (i == 0)
	change_son_pos(son, actual->pos.y - 1, actual->pos.x);
      else if (i == 1)
	change_son_pos(son, actual->pos.y + 1, actual->pos.x);
      else if (i == 2)
	change_son_pos(son, actual->pos.y, actual->pos.x - 1);
      else if (i == 3)
	change_son_pos(son, actual->pos.y, actual->pos.x + 1);
      if (add_to_the_list(f, son, map) == -1)
	return (-1);
      son->dad = actual;
      i++;
    }
  return (0);
}

t_larg		*get_next(t_first *f)
{
  t_larg	*tmp;

  if (f == NULL || f->first == NULL)
    return (NULL);
  tmp = f->first;
  while (tmp != NULL && tmp->block == 1)
    tmp = tmp->son;
  return (tmp);
}

int		largeur(t_first *f, t_map *map)
{
  t_larg	*actual;

  if (f == NULL)
    return (-1);
  while (count_open(f) > 0)
    {
      if ((actual = get_next(f)) == NULL)
	return (-1);
      actual->block = 1;
      if (actual->pos.y == map->hauteur - 1
	  && actual->pos.x == map->largeur - 1)
	{
	  while (actual->dad != NULL)
	    {
	      map->map[actual->pos.y][actual->pos.x] = 'o';
	      actual = actual->dad;
	    }
	  map->map[actual->pos.y][actual->pos.x] = 'o';
	  return (0);
	}
      if (add_sons(f, actual, map) == -1)
	return (-1);
      actual = actual->son;
    }
  return (1);
}
