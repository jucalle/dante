/*
** print_maze.c for  in /home/callew_j/rendu/semestre2/IA/dante/sources/generateur
**
** Made by
** Login   <callew_j@epitech.net>
**
** Started on  Mon Oct  3 09:35:11 2016
** Last update Wed Oct 12 16:02:54 2016 
*/

#include <stdio.h>

void		print_maze(char **maze, int largeur, int hauteur)
{
  int		i;
  int		j;
  int		dont_print;

  i = 0;
  dont_print = 0;
  while (i < hauteur)
    {
      j = 0;
      while (j < largeur)
	{
	  if (i == hauteur - 1 && j == largeur - 1 && maze[i][j] == '1')
	    {
	      printf("*");
	      dont_print = 1;
	    }
	  if (maze[i][j] == '0')
	    printf("*");
	  if (maze[i][j] == '1' && dont_print != 1)
	    printf("X");
	  j++;
	}
      printf("\n");
      i++;
    }
}

void		modif_maze(char **maze, int largeur, int hauteur)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < hauteur - 1)
    i++;
  while (j < largeur - 1)
    j++;
  if (maze[i][j - 1] == '1' && maze[i - 1][j] == '1')
    maze[i][j - 1] = '0';
  print_maze(maze, largeur, hauteur);
}
