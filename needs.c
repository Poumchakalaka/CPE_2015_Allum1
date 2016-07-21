/*
** needs.c for  in /home/spare/CPE_2015_Allum1
** 
** Made by spare spare
** Login   <spare@epitech.net>
** 
** Started on  Wed Feb 17 18:25:35 2016 spare spare
** Last update Fri Feb 26 23:10:09 2016 Clément Henry
*/

# include "allum1.h"

int      my_getnbr(char *str)
{
  int    i;
  int    nb;
  int    res;

  i = 0;
  res = 0;
  while (str[i] != '\0')
    {
      if (str[i] <= '9' && str[i] >= '0')
        {
          nb = str[i] - 48;
          res = res + nb;
          if (str[i + 1] != '\0' && (str[i + 1] <= '9' && str[i + 1] >= '0'))
            res = res * 10;
        }
      i = i + 1;
    }
  if (str[0] == '-')
    res = res * -1;
  return (res);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    my_putchar(str[i++]);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int	my_putnbr(int nb)
{
  if (nb < 10)
    my_putchar(nb + 48);
  else
    {
      my_putnbr(nb / 10);
      my_putnbr(nb % 10);
    }
}
