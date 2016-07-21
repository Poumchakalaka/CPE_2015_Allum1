/*
** ia_2.c for  in /home/spare/CPE_2015_Allum1
** 
** Made by spare spare
** Login   <spare@epitech.net>
** 
** Started on  Sun Feb 21 19:43:31 2016 spare spare
** Last update Sun Feb 21 22:53:41 2016 spare spare
*/

#include "allum1.h"

int     test(t_allum *allum, t_ia ia)
{
  ia.i = 0;
  ia.cpt = 0;
  ia.counter = 0;
  while (ia.i < 4)
    {
      if (allum->tab[ia.i] > 1)
        {
          ia.counter = ia.i;
          ia.cpt++;
        }
      ia.i++;
    }
  if (ia.cpt == 1)
    {
      allum->line = ia.counter;
      allum->matches = allum->tab[ia.counter];
      allum->tab[ia.counter] = allum->tab[ia.counter] -
        allum->tab[ia.counter];
      return (2);
    }
}

int     one_on_3(t_allum *allum, t_ia ia)
{
  ia.i = -1;
  ia.cpt = 0;
  ia.counter = 0;
  while (++ia.i < 4)
    {
      if (allum->tab[ia.i] == 1)
        ia.cpt++;
      if (allum->tab[ia.i] == 0)
        ia.counter++;
    }
  if (ia.cpt == 3 && ia.counter == 1)
    {
      ia.i = -1;
      while (++ia.i < 4)
        {
          if (ia.i == 1)
            {
	      allum->line = ia.i;
	      allum->matches = 1;
              allum->tab[ia.i] = allum->tab[ia.i] - 1;
              return (2);
            }
        }
    }
  return (0);
}

int     two(t_allum *allum, t_ia ia)
{
  t_two	two;

  init(&two.nb_tab, &two.counter, &two.i, allum);
  if (check_one(allum, ia) == 2)
      return (0);
  if (little_check(allum) != 4)
    if (first_check(allum, ia) == 0)
      return (0);
  while (++two.i != 4)
    {
      two.save = allum->tab[two.i];
      while (two.counter < two.save)
        {
          allum->tab[two.i] = allum->tab[two.i] - 1;
          two.res_xor = xor(allum);
          if (two.res_xor == 0)
	    {
	      state_match_line(allum, two.i, two.save);
		return (two.counter);
	    }
          two.counter++;
        }
      init_change(&two.nb_tab, &two.counter);
      allum->tab[two.i] = two.save;
    }
}

int     xor(t_allum *allum)
{
  int   i;
  int   counter;

  counter = 0;
  i = 0;
  while (i < 4)
    {
      counter = counter ^ allum->tab[i];
      i++;
    }
  return (counter);
}
