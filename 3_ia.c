/*
** 3_ia.c for  in /home/spare/CPE_2015_Allum1
** 
** Made by spare spare
** Login   <spare@epitech.net>
** 
** Started on  Sun Feb 21 19:46:57 2016 spare spare
** Last update Fri Feb 26 22:55:18 2016 Clément Henry
*/

#include "allum1.h"

int	alpha(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] <= '9' && str[i] >= '0')
	i++;
      else
	return (1);
    }
  return (0);
}

int     first_check(t_allum *allum, t_ia ia)
{
  if (check_allum(allum, ia) == 2)
    return (0);
  if (check_tab(allum) == 2)
    return (0);
  return (1);
}

int     little_check(t_allum *allum)
{
  int   i;
  int   cpt;

  cpt = 0;
  i = 0;
  while (i < 4)
    {
      if (allum->tab[i] > 0)
        cpt++;
      i++;
    }
  return (cpt);
}

void    init(int *a, int *b, int *c, t_allum *allum)
{
  *a =  allum->tab[0] + allum->tab[1] + allum->tab[2]
    + allum->tab[3];
  *b = 0;
  *c = -1;
}
