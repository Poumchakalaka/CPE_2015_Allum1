/*
** allum1.c for  in /home/spare/CPE_2015_Allum1
** 
** Made by spare spare
** Login   <spare@epitech.net>
** 
** Started on  Wed Feb 17 17:54:06 2016 spare spare
** Last update Sun Feb 21 23:10:41 2016 spare spare
*/

# include "allum1.h"

void	disp_char(int nb, char what, int indic)
{
  int	i;

  i = -1;
  while (++i != nb)
    my_putchar(what);
  if (indic == 1)
    my_putchar('\n');
}

void	disp(t_allum *allum, int indic)
{
  int	i;

  i = -1;
  disp_char(9, '*', 1);
  while (++i < 4)
    {
      my_putchar('*');
      disp_char(4 - i - 1, ' ', 0);
      disp_char(allum->tab[i], '|', 0);
      disp_char((i * 2 + 1) - allum->tab[i] + 4 - i - 1, ' ', 0);
      my_putchar('*');
      my_putchar('\n');
    }
  disp_char(9, '*', 1);
  if (indic == 1)
    my_putchar('\n');
}

void	init_tab(t_allum *allum)
{
  int	i;
  int	counter;

  i = 0;
  counter = 1;
  while (counter != 9)
    {
      allum->tab[i] = counter;
      counter += 2;
      i++;
    }
}

void	*init_struct(t_allum *allum)
{
  if ((allum->tab = malloc(sizeof(int) * 5)) == NULL)
    return (NULL);
  allum->nb_line = 4;
  allum->state = 0;
  allum->line = 0;
  allum->matches = 0;
  allum->total_matches = 16;
  init_tab(allum);
  disp(allum, 1);
}

int	my_allum1()
{
  t_allum	allum;

  init_struct(&allum);
  if (big_while(&allum) == 0)
    return (0);
}
