/*
** largeur.h for  in /home/callew_j/rendu/semestre2/IA/dante
**
** Made by
** Login   <callew_j@epitech.net>
**
** Started on  Tue Oct 11 19:23:14 2016
** Last update Wed Oct 12 15:52:20 2016 
*/

#ifndef LARGEUR_H_
# define LARGEUR_H_

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_larg
{
  int		block;
  t_pos		pos;
  struct s_larg	*son;
  struct s_larg	*dad;
}		t_larg;

typedef struct	s_first
{
  t_larg	*first;
}		t_first;

typedef struct	s_map
{
  int		hauteur;
  int		largeur;
  char		**map;
}		t_map;

void		print_map(t_map *map);
int		stock_map(t_map *map, char *av);
int		get_map(t_map *map, char *av);
int		add_to_the_list(t_first *f, t_larg *son, t_map *map);
int		add_sons(t_first *f, t_larg *actual, t_map *map);
t_larg		*get_next(t_first *f);
int		largeur(t_first *f, t_map *map);
int		not_already_in_list(t_first *f, t_larg *son);
void		change_son_pos(t_larg *son, int y, int x);
int		count_open(t_first *f);

#endif /* !LARGEUR_H_ */
