/*
** allum1.h for  in /home/spare/CPE_2015_Allum1
** 
** Made by spare spare
** Login   <spare@epitech.net>
** 
** Started on  Wed Feb 17 18:23:26 2016 spare spare
** Last update Sun Feb 21 22:42:54 2016 spare spare
*/

#ifndef ALLUM1_H_
# define ALLUM1_H

#ifndef READ_SIZE
# define READ_SIZE (100)
#endif /* !READ_SIZE */

typedef struct  s_allum
{
  int           nb_line;
  int           *tab;
  int		state;
  int		line;
  int		matches;
  int		total_matches;
}               t_allum;

typedef struct s_game
{
  char		*str;
  int		user_state;
  char		*tmp;
}		t_game;

typedef struct s_two
{
  int		i;
  int		counter;
  int		save;
  int		res_xor;
  int		nb_tab;
}		t_two;

typedef struct s_ia
{
  int		i;
  int		cpt;
  int		counter;
  int		line;
  int		line_2;
}		t_ia;

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(const int fd);

#endif
