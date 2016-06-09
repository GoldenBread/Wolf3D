/*
** vecnorm.c for wolf3d in /home/thierry/Rendu/gfx_wolf3d/tcore
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri Jan  1 21:14:20 2016 Thierry LEVISSE
** Last update Fri Jan  1 21:34:19 2016 Thierry LEVISSE
*/

#include	<lapin.h>
#include	<math.h>

double		vecnorm(t_bunny_position *coord0,
			t_bunny_position *coord1)
{
  double	norm;
  unsigned int	square_1;
  unsigned int	square_2;

  square_1 = pow(coord1->y - coord0->y, 2);
  square_2 = pow(coord1->x - coord0->x, 2);
  norm = (double)sqrt(square_1 + square_2);
  return (norm);
}
