/*
** astar.h for  in /home/callew_j/rendu/semestre2/IA/dante
**
** Made by
** Login   <callew_j@epitech.net>
**
** Started on  Tue Oct 11 18:53:54 2016
** Last update Tue Oct 11 19:20:17 2016 
*/

#ifndef ASTAR_H_
# define ASTAR_H_

typedef struct	s_open
{
  int		x;
  int		y;
  int		h_cost;
  int		closed;
  struct s_open	*next;
  struct s_open	*parent;
}		t_open;

typedef struct	s_first
{
  t_open	*first;
}		t_first;

typedef struct	s_map
{
  int		hauteur;
  int		largeur;
  char		**map;
}		t_map;

int		get_min(t_first *f);
t_open		*return_actual(t_first *f, int save_i);
t_first		*close_actual_from_open(t_first *f, t_open *actual);
int		is_it_closed(t_first *f, int y, int x);
int		is_it_in_open(t_first *f, int y, int x);
void		print_map(t_map *map);
int		stock_map(t_map *map, char *av);
int		get_map(t_map *map, char *av);
int		add_neighbor_in_open(t_first *f, t_open *neighbor);
int		count_open(t_first *f);
t_first		*init_first(t_map *map);
int		astar(t_map *map, t_first *f);
void		my_putsterror(char *str);

#endif /* !ASTAR_H_ */
