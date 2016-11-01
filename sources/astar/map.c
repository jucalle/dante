/*
** map.c for  in /home/callew_j/rendu/semestre2/IA/dante/sources/largeur
**
** Made by
** Login   <callew_j@epitech.net>
**
** Started on  Tue Oct 11 19:26:41 2016
** Last update Tue Oct 18 15:18:07 2016 Sebastien Le Guischer
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "astar.h"

void		print_map(t_map *map)
{
  int		i;

  i = 0;
  while (i != map->hauteur)
    {
      printf("%s\n", map->map[i]);
      i = i + 1;
    }
}

int	detect_error(char *line, int largeur)
{
  int	i;

  if ((int)strlen(line) != largeur)
    return (1);
  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] != '*' && line[i] != 'X')
	return (1);
      i = i + 1;
    }
  return (0);
}

int		stock_map(t_map *map, char *av)
{
  int		i;
  FILE		*fd;
  size_t	len;
  char		*str;

  i = 0;
  if ((fd = fopen(av, "r")) == NULL)
    return (1);
  str = NULL;
  len = 0;
  while (getline(&str, &len, fd) != -1)
    {
      map->map[i] = strdup(str);
      map->map[i][map->largeur] = '\0';
      if (detect_error(map->map[i], map->largeur) == 1)
	return (1);
      i = i + 1;
    }
  fclose(fd);
  return (0);
}

int		get_map(t_map *map, char *av)
{
  FILE		*fd;
  char		*str;
  size_t	len;

  map->hauteur = 0;
  if ((fd = fopen(av, "r")) == NULL)
    return (1);
  str = NULL;
  len = 0;
  while (getline(&str, &len, fd) != -1)
    map->hauteur = map->hauteur + 1;
  map->largeur = strlen(str) - 1;
  fclose(fd);
  if ((map->map = malloc(sizeof(char *) * map->hauteur)) == NULL)
    return (1);
  if (stock_map(map, av) == 1)
    return (1);
  return (0);
}
