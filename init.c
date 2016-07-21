/*
** init.c for  in /home/spare/CPE_2015_Allum1
** 
** Made by spare spare
** Login   <spare@epitech.net>
** 
** Started on  Sun Feb 21 21:16:59 2016 spare spare
** Last update Fri Feb 26 22:45:23 2016 Clément Henry
*/

#include "allum1.h"

void	state_match_line(t_allum *allum, int i, int save)
{
  allum->matches = save - allum->tab[i];
  allum->line = i;
}

int     check_line(int nb, t_allum *allum, char *str)
{
  if (alpha(str) == 1)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (0);
    }
  if (nb > 4 || nb == 0)
    {
      my_putstr("Error: this line is out of range\n");
      return (0);
    }
  if (nb < 0)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (0);
    }
  if (allum->tab[nb - 1] == 0)
    {
      my_putstr("Error : this line is empty\n");
      return (0);
    }
  return (1);
}

void	init_change(int *a, int *b)
{
  *a = *a - *b;
  *b = 0;
}
