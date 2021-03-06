/*
** my_put_nbr.c for emacs in /home/detroy_j/delivery/CPool_Day03
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Thu Oct  6 19:38:09 2016 jean-baptiste detroyes
** Last update Wed Jan 11 20:29:46 2017 detroy_j
*/

int     my_putchar(char c);

int	my_put_nbr(int nb)
{
  int	a;

  if (nb < 0)
    {
      my_putchar(45);
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  a = (nb % 10);
	  nb = (nb - a) / 10;
	  my_put_nbr(nb);
	  my_putchar(48 + a);
	}
      else
	{
	  my_putchar(48 + nb);
	}
    }
  return (0);
}
