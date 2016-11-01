/*
** imparfait.c for  in /home/callew_j/rendu/semestre2/IA/dante/sources/generateur
**
** Made by
** Login   <callew_j@epitech.net>
**
** Started on  Mon Oct  3 09:48:10 2016
** Last update Sun Oct 23 13:11:00 2016 Callewaert
*/

#include <stdlib.h>
#include "gen.h"

void		break_walls(char **maze, int largeur, int hauteur)
{
  int		i;
  int		y;
  int		x;
  int		nb_walls_break;

  i = 0;
  y = 0;
  x = 0;
  nb_walls_break = (largeur * hauteur) / 2;
  while (i < nb_walls_break)
    {
      y = rand()%hauteur;
      x = rand()%largeur;
      if (maze[y][x] == '1')
	maze[y][x] = '0';
      i++;
    }
}

void		gen_imparfait(int largeur, int hauteur)
{
  char		**maze;
  t_dante	dante;

  init_dante(&dante, largeur, hauteur);
  if ((maze = malloc_maze(largeur, hauteur)) == NULL)
    return ;
  maze = init_maze(maze, largeur, hauteur);
  algo_parfait(&dante, maze);
  break_walls(maze, largeur, hauteur);
  modif_maze(maze, largeur, hauteur);
}
