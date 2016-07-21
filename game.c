/*
** game.c for  in /home/spare/CPE_2015_Allum1
** 
** Made by spare spare
** Login   <spare@epitech.net>
** 
** Started on  Thu Feb 18 17:11:57 2016 spare spare
** Last update Sun Feb 21 23:28:54 2016 spare spare
*/

# include "allum1.h"

int	check_matches(int nb_m, int nb_l, t_allum *allum, char *str)
{
  nb_l = nb_l - 1;
  if (alpha(str) == 1)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (0);
    }
  if (nb_m == 0)
    {
      my_putstr("Error: you have to remove at least one match\n");
      return (0);
    }
  if (nb_m > allum->tab[nb_l])
    {
      my_putstr("Error: not enough matches on this line\n");
      return (0);
    }
  if (nb_m < 0)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (0);
    }
  return (1);
}

void	display_user(char *str, int nb_l, char *str_2, int nb_m)
{
  my_putstr(str);
  my_putnbr(nb_l);
  my_putstr(str_2);
  my_putnbr(nb_m);
  my_putstr(nb_m);
}

int	my_game(t_allum *allum, char *str)
{
  char	*tmp;

  tmp = str;
  if (str[0] == 'A')
    return (0);
  allum->matches = my_getnbr(my_epur_str(str));
  if ((check_matches(allum->matches, allum->line, allum, str)) == 1)
    return (1);
  else
    return (2);
}

int	my_game2(t_allum *allum)
{
  allum->tab[allum->line - 1] = allum->tab[allum->line - 1] - allum->matches;
  special_disp("Player removed ", allum->matches,
 " match(es) from line ",  allum->line);
}

int	game(t_allum *allum, t_game game)
{
  my_putstr("Your turn:\n");
  while (game.user_state != 2)
    {
      my_putstr("Line: ");
      game.user_state = 0;
      game.str = get_next_line(0);
      if (game.str[0] == 'A')
	return (0);
      game.tmp = game.str;
      allum->line = my_getnbr(my_epur_str(game.str));
      if ((check_line(allum->line, allum, game.tmp)) == 1)
	game.user_state++;
      if (game.user_state > 0)
	{
	  my_putstr("Matches: ");
	  game.str = get_next_line(0);
	  if (game.str[0] == 'A')
	    return (0);
	  if (my_game(allum, game.str) == 1)
	    game.user_state++;
	}
    }
  my_game2(allum);
  return (1);
}
