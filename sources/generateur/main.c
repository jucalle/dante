/*
** main.c for dante in /home/sebastien/Rendu/dante/sources/profondeur
**
** Made by Sebastien Le Guischer
** Login   <sebastien@epitech.net>
**
** Started on  Tue Sep 27 18:24:47 2016 Sebastien Le Guischer
** Last update Mon Oct  3 09:48:50 2016 
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "gen.h"

int	main(int argc, char **argv)
{
  srand(getpid() * time(NULL));
  if (argc == 3)
    {
      if (good_dimensions(argv[1], argv[2]) == -1)
	return (-1);
      gen_imparfait(atoi(argv[1]), atoi(argv[2]));
    }
  else if (argc == 4)
    {
      if (good_dimensions(argv[1], argv[2]) == -1
	  || my_strcmp("parfait", argv[3]) == 1)
	return (-1);
      gen_parfait(atoi(argv[1]), atoi(argv[2]));
    }
  return (0);
}
