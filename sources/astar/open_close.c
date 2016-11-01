/*
** open_close.c for  in /home/callew_j/rendu/semestre2/IA/dante/sources/astar
**
** Made by
** Login   <callew_j@epitech.net>
**
** Started on  Tue Oct 11 19:04:31 2016
** Last update Tue Oct 11 19:05:06 2016 
*/

#include <stdlib.h>
#include "astar.h"

int		get_min(t_first *f)
{
  t_open	*tmp;

  tmp = f->first;
  while (tmp != NULL && tmp->closed != 0)
    tmp = tmp->next;
  if (tmp == NULL)
    return (-1);
  if (tmp->closed == 0)
    return (tmp->h_cost);
  return (-1);
}

t_open		*return_actual(t_first *f, int save_i)
{
  int		i;
  t_open	*tmp;

  i = 0;
  tmp = f->first;
  while (tmp != NULL && i != save_i)
    {
      i++;
      tmp = tmp->next;
    }
  return (tmp);
}

t_first		*close_actual_from_open(t_first *f, t_open *actual)
{
  t_open	*tmp;

  if (f == NULL || actual == NULL)
    return (NULL);
  tmp = f->first;
  while (tmp != NULL)
    {
      if (tmp->x == actual->x && tmp->y == actual->y)
	{
	  tmp->closed = 1;
	  return (f);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

int		is_it_closed(t_first *f, int y, int x)
{
  t_open	*tmp;

  if (f != NULL)
    {
      tmp = f->first;
      while (tmp != NULL)
	{
	  if (y == tmp->y && x == tmp->x && tmp->closed == 1)
	    return (1);
	  tmp = tmp->next;
	}
      return (0);
    }
  return (-1);
}

int		is_it_in_open(t_first *f, int y, int x)
{
  t_open	*tmp;

  if (f != NULL)
    {
      tmp = f->first;
      while (tmp != NULL)
	{
	  if (y == tmp->y && x == tmp->x && tmp->closed == 0)
	    return (1);
	  tmp = tmp->next;
	}
      return (0);
    }
  return (-1);
}
