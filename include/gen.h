/*
** gen.h for dante in /home/sebastien/Rendu/dante
**
** Made by Sebastien Le Guischer
** Login   <sebastien@epitech.net>
**
** Started on  Wed Sep 28 15:40:51 2016 Sebastien Le Guischer
** Last update Fri Oct  7 12:55:32 2016 
*/

#ifndef GEN_H_
# define GEN_H_

typedef struct	s_dante
{
  int		north;
  int		west;
  int		hauteur;
  int		largeur;
}		t_dante;

void		init_dante(t_dante *dante, int largeur, int hauteur);
char		**malloc_maze(int largeur, int hauteur);
char		**init_maze(char **maze, int largeur, int hauteur);
int		good_dimensions(const char *str1, const char *str2);
int		my_strcmp(const char *str1, const char *str2);
void		gen_parfait(int largeur, int hauteur);
void		gen_imparfait(int largeur, int hauteur);
void		modif_maze(char **maze, int largeur, int hauteur);
void		algo_parfait(t_dante *dante, char **maze);

#endif /* !GEN_H_ */
