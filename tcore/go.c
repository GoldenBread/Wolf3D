/*
** go.c for wolf3d in /home/thierry/Rendu/gfx_wolf3d/tcore
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri Jan  1 21:35:15 2016 Thierry LEVISSE
** Last update Fri Jan  1 23:04:19 2016 Thierry LEVISSE
*/

#include	<lapin.h>
#include	<math.h>

void	go(t_bunny_position *curpos,
	   double angle,
	   t_bunny_position *newpos,
	   int move)
{
  newpos->x = (move * cos(angle)) + curpos->x;
  newpos->y = (move * sin(angle)) + curpos->y;
}
