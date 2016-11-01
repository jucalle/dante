/*
** parfait.c for  in /home/callew_j/rendu/semestre2/IA/dante/sources/generateur
**
** Made by
** Login   <callew_j@epitech.net>
**
** Started on  Mon Oct  3 09:31:27 2016
** Last update Fri Oct  7 12:55:49 2016 
*/

#include <stdlib.h>
#include "gen.h"

void		change_north_west(char **maze, int i, int j, t_dante *dante)
{
  if (i - 1 >= 0 && maze[i - 1][j] == '1')
    dante->north = 1;
  if (j - 1 >= 0 && maze[i][j - 1] == '1')
    dante->west = 1;
}

void		one_wall_aside(char **maze, int i, int j, t_dante *dante)
{
  if (i - 1 >= 0 && dante->north == 1 && dante->west == 0)
    maze[i - 1][j] = '0';
  if (j - 1 >= 0 && dante->north == 0 && dante->west == 1)
    maze[i][j - 1] = '0';
}

void		two_walls_aside(char **maze, int i, int j, int random)
{
  random = rand()%2;
  if (j - 1 >= 0 && random == 0)
    maze[i][j - 1] = '0';
  else if (i - 1 >= 0 && random == 1)
    maze[i - 1][j] = '0';
}

void		algo_parfait(t_dante *dante, char **maze)
{
  int		i;
  int		j;
  int		random;

  i = 0;
  random = 0;
  while (i < dante->hauteur)
    {
      j = 0;
      dante->north = 0;
      dante->west = 0;
      while (j < dante->largeur)
	{
	  if (i == 0)
	    maze[i][j] = '0';
	  change_north_west(maze, i, j, dante);
	  one_wall_aside(maze, i, j, dante);
	  if (dante->north == 1 && dante->west == 1)
	    two_walls_aside(maze, i, j, random);
	  j += 2;
	}
      i += 2;
    }
}

void		gen_parfait(int largeur, int hauteur)
{
  t_dante	dante;
  char		**maze;

  init_dante(&dante, largeur, hauteur);
  if ((maze = malloc_maze(largeur, hauteur)) == NULL)
    return ;
  maze = init_maze(maze, largeur, hauteur);
  algo_parfait(&dante, maze);
  modif_maze(maze, largeur, hauteur);
}
