/*
** init.c for  in /home/callew_j/rendu/semestre2/IA/dante/sources/generateur
**
** Made by
** Login   <callew_j@epitech.net>
**
** Started on  Mon Oct  3 09:33:04 2016
** Last update Wed Oct 12 16:02:17 2016 
*/

#include <stdlib.h>
#include "gen.h"

char		**malloc_maze(int largeur, int hauteur)
{
  int		i;
  int		max_larg;
  int		max_haut;
  char		**maze;

  i = 0;
  if (largeur == 0 || hauteur == 0)
    return (NULL);
  max_haut = hauteur + (hauteur - 1);
  max_larg = largeur + (largeur - 1);
  if ((maze = malloc(sizeof(char *) * (max_haut + 1))) == NULL)
    return (NULL);
  while (i < max_haut)
    {
      if ((maze[i] = malloc(sizeof(char) * (max_larg + 1))) == NULL)
	return (NULL);
      i++;
    }
  maze[i] = NULL;
  return (maze);
}

char		**init_maze(char **maze, int largeur, int hauteur)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < hauteur + (hauteur - 1))
    {
      j = 0;
      while (j < largeur + (largeur - 1))
	{
	  if (j % 2 == 0 && i % 2 == 0)
	    maze[i][j] = '0';
	  else if (j % 2 != 0 && i % 2 == 0)
	    maze[i][j] = '1';
	  else if (i % 2 != 0)
	    maze[i][j] = '1';
	  j++;
	}
      maze[i][j] = '\0';
      i++;
    }
  return (maze);
}

void		init_dante(t_dante *dante, int largeur, int hauteur)
{
  dante->north = 0;
  dante->west = 0;
  dante->largeur = largeur + (largeur - 1);
  dante->hauteur = hauteur + (hauteur - 1);
}
