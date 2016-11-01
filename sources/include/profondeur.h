/*
** profondeur.h for dante in /home/sebastien/Rendu/dante
**
** Made by Sebastien Le Guischer
** Login   <sebastien@epitech.net>
**
** Started on  Tue Oct 18 15:11:37 2016 Sebastien Le Guischer
** Last update Tue Oct 18 15:14:23 2016 Sebastien Le Guischer
*/

#ifndef PROFONDEUR_H_
# define PROFONDEUR_H_

typedef struct	s_map
{
  int		hauteur;
  int		largeur;
  char		**map;
}		t_map;

void	print_map(t_map *map);
int	get_map(t_map *map, char *av);

#endif /* !PROFONDEUR_H_ */
