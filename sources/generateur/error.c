/*
** error.c for  in /home/callew_j/rendu/semestre2/IA/dante/sources/generateur
**
** Made by
** Login   <callew_j@epitech.net>
**
** Started on  Mon Oct  3 09:33:54 2016
** Last update Mon Oct  3 09:34:47 2016 
*/

int	good_dimensions(char *x, char *y)
{
  int	i;

  i = 0;
  while (x[i] != '\0')
    {
      if (x[i] < '0' || x[i] > '9')
	return (-1);
      i++;
    }
  i = 0;
  while (y[i] != '\0')
    {
      if (y[i] < '0' || y[i] > '9')
	return (-1);
      i++;
    }
  return (0);
}

int	my_strcmp(const char *str1, const char *str2)
{
  int	i;

  i = 0;
  while (str1[i] != '\0' && str2[i] != '\0')
    {
      if (str1[i] != str2[i])
	return (1);
      i += 1;
    }
  if (str1[i] != str2[i])
    return (1);
  return (0);
}
