/*
** ia.c for  in /home/spare/CPE_2015_Allum1
** 
** Made by spare spare
** Login   <spare@epitech.net>
** 
e** Started on  Sat Feb 20 03:07:53 2016 spare spare
** Last update Sun Feb 21 23:07:02 2016 spare spare
*/

#include "allum1.h"

int	check_tab(t_allum *allum)
{
  int	i;
  int	counter;
  int	line;

  counter = 0;
  i = -1;
  while (++i < 4)
    {
      if (allum->tab[i] > 1)
	{
	  counter++;
	  line = i;
	}
    }
  if (counter > 1)
    return (0);
  if (counter == 1)
    {
      allum->matches = allum->tab[line] - 1;
      allum->line = line;
      allum->tab[line] = allum->tab[line] - (allum->tab[line] - 1);
      return (2);
    }
  return (0);
}

void	my_init_struct(int *a, int *b, int *c)
{
  *a = 0;
  *b = 0;
  *c = -1;
}

void	state(t_allum *allum, t_ia ia, int indic)
{
  if (indic == 0)
    {
      allum->line = ia.line;
      allum->matches = allum->tab[ia.line];
      allum->tab[ia.line] = allum->tab[ia.line] - allum->tab[ia.line];
    }
  if (indic == 1)
    {
      allum->line = ia.line_2;
      allum->matches = allum->tab[ia.line_2];
      allum->tab[ia.line_2] = allum->tab[ia.line_2] - 1;
    }
}

int	check_allum(t_allum *allum, t_ia ia)
{
  my_init_struct(&ia.cpt, &ia.counter, &ia.i);
  while (++ia.i < 4)
    {
      if (allum->tab[ia.i] > 1)
	{
	  ia.cpt++;
	  ia.line = ia.i;
	}
      if (allum->tab[ia.i] == 1)
	{
	  ia.counter++;
	  ia.line_2 = ia.i;
	}
    }
  if (ia.counter == 1 & ia.cpt == 1)
    {
      state(allum, ia, 0);
      return (2);
    }
  if (ia.counter == 2)
    {
      state(allum, ia, 1);
      return (2);
    }
  return (0);
}

int	check_one(t_allum *allum, t_ia ia)
{
  if (one_on_3(allum, ia) == 2)
    return (2);
  ia.i = -1;
  ia.cpt = 0;
  while (++ia.i < 4)
    if (allum->tab[ia.i] == 1)
      ia.cpt++;
  if (ia.cpt == 3)
    if (test(allum, ia) == 2)
      return (2);
  if (ia.cpt == 4)
      {
	ia.i = 0;
	while (ia.i < 4)
	  {
	    if (allum->tab[ia.i] == 1)
	      {
		allum->tab[ia.i] = allum->tab[ia.i] - 1;
		return (2);
	      }
	    ia.i++;
	  }
      }
  return (0);
}
