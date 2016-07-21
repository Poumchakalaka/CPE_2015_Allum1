/*
** 2_game.c for  in /home/spare/CPE_2015_Allum1
** 
** Made by spare spare
** Login   <spare@epitech.net>
** 
** Started on  Thu Feb 18 21:08:02 2016 spare spare
** Last update Sun Feb 21 23:30:26 2016 spare spare
*/

# include "allum1.h"

int		check_end(t_allum *allum)
{
  int		i;
  int		cpt;

  cpt = 0;
  i = 0;
  while (i < 4)
    {
      if (allum->tab[i] == 0)
	cpt++;
      i++;
    }
  if (cpt == 4)
    return (1);
  else
    return (0);
}

void		special_disp(char *str, int nb, char *str_2, int nb_2)
{
  my_putstr(str);
  my_putnbr(nb);
  my_putstr(str_2);
  my_putnbr(nb_2);
  my_putchar('\n');
}

int		big_while(t_allum *allum)
{
  t_game	game_s;
  t_ia		ia;

  while (check_end(allum) != 1)
    {
      if (game(allum, game_s) == 0)
	return (0);
      disp(allum, 0);
      if (check_end(allum) == 1)
	{
	  my_putstr("You lost, too bad..\n");
	  return (0);
	}
      my_putstr("\nAI's turn...\n");
      two(allum, ia);
      special_disp("AI removed ", allum->matches,
 " match(es) from line ", allum->line + 1);
      disp(allum, 0);
      if (check_end(allum) == 1)
	{
	  my_putstr("I lost.. snif.. but I'll get you next time!!\n");
	  return (0);
	}
      my_putchar('\n');
    }
}
